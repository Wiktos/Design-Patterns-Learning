#pragma once
class CarEngine
{
public:
	virtual std::string to_string() = 0;
};

class BMWEngine : public CarEngine
{
public:
	std::string to_string()
	{
		return "BMWEngine";
	}
};

class OpelEngine : public CarEngine
{
public:
	std::string to_string()
	{
		return "OpelEngine";
	}
};

class MazdaEngine : public CarEngine
{
public:
	std::string to_string()
	{
		return "MazdaEngine";
	}
};

class CarDoor
{
public:
	virtual std::string to_string() = 0;
};

class BMWDoor : public CarDoor
{
public:
	std::string to_string()
	{
		return "BMWDoor";
	}
};

class OpelDoor : public CarDoor
{
public :
	std::string to_string()
	{
		return "OpelDoor";
	}
};

class MazdaDoor : public CarDoor
{
public:
	std::string to_string()
	{
		return "MazdaDoor";
	}
};

class CarLamp
{
public:
	virtual std::string to_string() = 0;
};

class BMWLamp : public CarLamp
{
public:
	std::string to_string()
	{
		return "BMWLamp";
	}
};

class OpelLamp : public CarLamp
{
public:
	std::string to_string()
	{
		return "OpelLamp";
	}
};

class MazdaLamp : public CarLamp
{
public:
	std::string to_string()
	{
		return "MazdaLamp";
	}
};