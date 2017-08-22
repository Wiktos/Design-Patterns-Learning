#pragma once
#include <iostream>
#include <map>

typedef std::string RobotType;

class Robot
{
protected:
	RobotType type;
public:
	virtual void doAction() = 0;
};

class KitchenRobot : public Robot
{
public:
	static Robot* create()
	{
		return new KitchenRobot;
	}
	KitchenRobot()
	{
		Robot::type = "kitchen";
	}
	void doAction()
	{
		std::cout << "KitchenRobot action : preparing pizza" << std::endl;
	}
};

class MilitaryRobot : public Robot
{
public:
	static Robot* create()
	{
		return new MilitaryRobot;
	}
	MilitaryRobot()
	{
		Robot::type = "military";
	}
	void doAction()
	{
		std::cout << "MilitaryRobot action : defending airspace" << std::endl;
	}
};

class InvestigativeRobot : public Robot
{
public:
	static Robot* create()
	{
		return new InvestigativeRobot;
	}
	InvestigativeRobot()
	{
		Robot::type = "investigative";
	}
	void doAction()
	{
		std::cout << "InvastigativeRobot action : invastigating current area" << std::endl;
	}
};

class RobotFactory
{
	typedef Robot* (*createRobotFun)();
	typedef std::map<RobotType, createRobotFun> Creators;
	Creators robotCreators;
public:
	void registerRobot(RobotType type, createRobotFun constructor)
	{
		robotCreators.insert({ type, constructor });
	}
	Robot* createRobot(RobotType type)
	{
		Creators::const_iterator iter = robotCreators.find(type);
		if (iter != robotCreators.end())
			return iter->second();
		throw std::runtime_error("Unknown identifier");
	}
};