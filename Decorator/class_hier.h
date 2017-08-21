#pragma once
#include <string>

class Coffee
{
public:
	virtual std::string getIngredients() = 0;
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
};

class MilkedCoffee : public CoffeeDecorator
{
public:
	using CoffeeDecorator::CoffeeDecorator;
	virtual std::string getIngredients()
	{
		return CoffeeDecorator::getIngredients() + "Milk ";
	}
};

class SugaredCoffee : public CoffeeDecorator
{
public:
	using CoffeeDecorator::CoffeeDecorator;
	virtual std::string getIngredients()
	{
		return CoffeeDecorator::getIngredients() + "Sugar ";
	}
};