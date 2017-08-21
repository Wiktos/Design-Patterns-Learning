#include <iostream>
#include "class_hier.h"

using namespace std;

static inline Coffee* MilkedAndSugaredCoffee()
{
	return new MilkedCoffee(new SugaredCoffee(new SimpleCoffee()));
}

int main()
{
	Coffee* myDreamCoffee = MilkedAndSugaredCoffee();

	cout << myDreamCoffee->getIngredients() << endl;

	return 0;
}