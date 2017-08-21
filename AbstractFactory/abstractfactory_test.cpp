#include "class_hier_factories.h"

using namespace std;

enum CarFactories 
{ 
	BMW,
	OPEL,
	MAZDA
};
static AbstractCarModelFactory* chooseFactory(CarFactories whichOne)
{
	switch (whichOne)
	{
	case BMW:
		return new BMWFactory;
	case OPEL:
		return new OpelFactory;
	case MAZDA:
		return new MazdaFactory;
	default:
		return nullptr;
	}
}

class Car
{
	AbstractCarModelFactory* factory;
	CarEngine* engine;
	CarDoor* door;
	CarLamp* lamp;
public:
	Car(AbstractCarModelFactory* fromFactory)
	{
		factory = fromFactory;
		engine = factory->createEngine();
		door = factory->createDoor();
		lamp = factory->createLamp();
	}
	void changeComponentsFactory(AbstractCarModelFactory* newFactory)
	{
		delete factory;
		factory = newFactory;
	}
	void replaceEngine()
	{
		delete engine;
		engine = factory->createEngine();
	}
	void replaceDoor()
	{
		delete door;
		door = factory->createDoor();
	}
	void replaceLamp()
	{
		delete lamp;
		lamp = factory->createLamp();
	}
	std::string carInfo()
	{
		return engine->to_string() 
			+ " " + door->to_string()
			+ " " + lamp->to_string();
	}
	~Car()
	{
		delete factory;
		delete engine;
		delete door;
		delete lamp;
	}
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	AbstractCarModelFactory* basicFactory = chooseFactory(OPEL);
	Car myDreamCar(basicFactory);
	cout << myDreamCar.carInfo() << endl;
	cout << "Hmmm dont like engine I want more power !!!" << endl;
	
	basicFactory = chooseFactory(BMW);
	myDreamCar.changeComponentsFactory(basicFactory);
	myDreamCar.replaceEngine();
	cout << myDreamCar.carInfo() << endl;

	return 0;
}