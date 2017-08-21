#include "class_hier.h"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	WeakComputer myComputer;
	myComputer.installWitcher();
	myComputer.changeGameInDrive(new WitcherThreeGame);
	myComputer.installWitcher();

	SuperComputer myDreamComputer;
	myDreamComputer.installWitcher();
	myDreamComputer.changeGameInDrive(new WitcherOneGame);
	myDreamComputer.installWitcher();

	return 0;
}