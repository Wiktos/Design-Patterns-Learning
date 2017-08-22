#pragma once
#include <string>

class Coffee
{
public:
	virtual std::string getIngredients() = 0;
	virtual ~Coffee()
	{}
};

class SimpleCoffee : public Coffee
{
public:
	virtual std::string getIngredients()
	{
		return "Coffee ";
	}
};

class CoffeeDecorator : public Coffee
{
	Coffee* coffee;
public:
	CoffeeDecorator(Coffee* coffee) : coffee(coffee)
	{}
	virtual std::string getIngredients()
	{
		return coffee->getIngredients();
	}
	virtual ~CoffeeDecorator()
	{
		delete coffee;
	}
};

class MilkedCoffee : public CoffeeDecorator
{
public:
	MilkedCoffee(Coffee* coffee) : CoffeeDecorator(coffee)
	{}
	virtual std::string getIngredients()
	{
		return CoffeeDecorator::getIngredients() + "Milk ";
	}
};

class SugaredCoffee : public CoffeeDecorator
{
public:
	SugaredCoffee(Coffee* coffee) : CoffeeDecorator(coffee)
	{}
	virtual std::string getIngredients()
	{
		return CoffeeDecorator::getIngredients() + "Sugar ";
	}
};