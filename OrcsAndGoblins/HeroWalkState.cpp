#include "stdafx.h"
#include "HeroWalkState.h"

void HeroWalkState::handle(Engine* context) {
	vector<string> *expectedAnswers = new vector < string > ;
	expectedAnswers->push_back("noord");
	expectedAnswers->push_back("zuid");
	expectedAnswers->push_back("oost");
	expectedAnswers->push_back("west");

	string direction = InputManager::getInstance()->requestInput("Welke Richting?", expectedAnswers);

	if (direction == "noord") {
		printf("Hero gaat naar noord");
	}
	else if (direction == "zuid") {
		printf("Hero gaat naar zuid");
	}
	else if (direction == "oost") {
		printf("Hero gaat naar oost");
	}
	else if (direction == "west") {
		printf("Hero gaat naar west");
	}



	delete expectedAnswers;
}