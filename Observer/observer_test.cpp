#include "class_hier.h"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Patient Wiktor;

	Wiktor.attachObsDevice(new BloodPreassureMeasurer);
	Wiktor.attachObsDevice(new MusclePreassureMeasurer);

	Wiktor.preassureRise();
	Wiktor.preassureRise();
	Wiktor.preassureDrop();

	return 0;
}