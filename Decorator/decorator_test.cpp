#include <iostream>
#include "class_hier.h"

using namespace std;

Coffee* MilkedAndSugaredCoffee()
{
	Coffee* coffee = new SimpleCoffee;
	Coffee* milked = new MilkedCoffee(coffee);
	Coffee* milkedSugared = new SugaredCoffee(milked);
	return milkedSugared;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Coffee* myDreamCoffee = MilkedAndSugaredCoffee();
	cout << myDreamCoffee->getIngredients() << endl;
	
	delete myDreamCoffee; 
	return 0;
}