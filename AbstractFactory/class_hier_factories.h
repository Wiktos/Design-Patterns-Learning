#pragma once
#include "class_hier_programobj.h"

class AbstractCarModelFactory
{
public:
	virtual CarEngine* createEngine() = 0;
	virtual CarDoor* createDoor() = 0;
	virtual CarLamp* createLamp() = 0;
	virtual ~AbstractCarModelFactory()
	{}
};

class OpelFactory : public AbstractCarModelFactory
{
public:
	CarEngine* createEngine()
	{
		return new OpelEngine;
	}
	CarDoor* createDoor()
	{
		return new OpelDoor;
	}
	CarLamp* createLamp()
	{
		return new OpelLamp;
	}
};

class MazdaFactory : public AbstractCarModelFactory
{
public:
	CarEngine* createEngine()
	{
		return new MazdaEngine;
	}
	CarDoor* createDoor()
	{
		return new MazdaDoor;
	}
	CarLamp* createLamp()
	{
		return new MazdaLamp;
	}
};

class BMWFactory : public AbstractCarModelFactory
{
public:
	CarEngine* createEngine()
	{
		return new BMWEngine;
	}
	CarDoor* createDoor()
	{
		return new BMWDoor;
	}
	CarLamp* createLamp()
	{
		return new BMWLamp;
	}
};