#include "class_hier.h"
#include <vector>

using namespace std;

const RobotType KITCHEN_ROBOT = "Kitchen";
const RobotType MILITARY_ROBOT = "Military";
const RobotType INVESTIGATIVE_ROBOT = "Investigative";

void registerRobotsToFactoryCatalog(RobotFactory& factory)
{
	factory.registerRobot(KITCHEN_ROBOT, KitchenRobot::create);
	factory.registerRobot(MILITARY_ROBOT, MilitaryRobot::create);
	factory.registerRobot(INVESTIGATIVE_ROBOT, InvestigativeRobot::create);
}

void deleteAllRobotsPointer(std::vector<Robot*> robots)
{
	for (Robot* robot : robots)
		delete robot;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	RobotFactory robotFactory;
	registerRobotsToFactoryCatalog(robotFactory);

	cout << "USA Army bought military robot in our factory and now they testing it... " << endl;
	Robot* usaArmyBrandNewRobot = robotFactory.createRobot(MILITARY_ROBOT);
	usaArmyBrandNewRobot->doAction();

	cout << "Hmmm Uncle Tina came to our shop either to buy kitchen help... " << endl;
	Robot* uncleTinaBrandNewRobot = robotFactory.createRobot(KITCHEN_ROBOT);
	uncleTinaBrandNewRobot->doAction();

	cout << "Faculty of Geodezy need something to investigate area very easily.. " << endl;
	Robot* geodeticInvestigativeRobot = robotFactory.createRobot(INVESTIGATIVE_ROBOT);
	geodeticInvestigativeRobot->doAction();

	system("pause");
	deleteAllRobotsPointer(
	{ 
		usaArmyBrandNewRobot, 
		uncleTinaBrandNewRobot, 
		geodeticInvestigativeRobot 
	});
	return 0;
}