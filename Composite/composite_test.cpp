#include "class_hier.h"

using namespace std;

void saveEmotionMadeDurringTheDay(FacialExpressionsComposite& dayExpressions)
{
	dayExpressions.addExpression(new SadFace);
	dayExpressions.addExpression(new EmotionLessFace);
	dayExpressions.addExpression(new SadFace);
	dayExpressions.addExpression(new SmileFace);
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	FacialExpressionsComposite myMoodDurringMonday;
	saveEmotionMadeDurringTheDay(myMoodDurringMonday);
	cout << "On Monday I usually feel like : " << endl;
	myMoodDurringMonday.showEmotion();

	return 0;
}