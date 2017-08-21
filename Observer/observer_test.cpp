#include "class_hier.h"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Patient Wiktor;
	BloodPreassureMeasurer bloodPreassureMeasurer;
	MusclePreassureMeasurer musclePreassureMeasurer;

	Wiktor.attachObsDevice(&bloodPreassureMeasurer);
	Wiktor.attachObsDevice(&musclePreassureMeasurer);

	Wiktor.preassureRise();
	Wiktor.preassureRise();
	Wiktor.preassureDrop();

	return 0;
}