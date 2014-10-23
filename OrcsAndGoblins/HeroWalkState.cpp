#include "stdafx.h"
#include "HeroWalkState.h"

void HeroWalkState::handle(Engine* context) {
	vector<string> *expectedAnswers = new vector < string > ;
	expectedAnswers->push_back("noord");
	expectedAnswers->push_back("zuid");
	expectedAnswers->push_back("oost");
	expectedAnswers->push_back("west");

	Hero* hero = context->getHero();

	string direction = InputManager::getInstance()->requestInput("Welke Richting?", expectedAnswers);

	if (direction == "noord") {
		hero->setPosY(hero->getPosY() + 1);
		printf("Hero gaat naar noord\n");
	}
	else if (direction == "zuid") {
		hero->setPosY(hero->getPosY() - 1);
		printf("Hero gaat naar zuid\n");
	}
	else if (direction == "oost") {
		hero->setPosX(hero->getPosX() + 1);
		printf("Hero gaat naar oost\n");
	}
	else if (direction == "west") {
		hero->setPosX(hero->getPosX() - 1);
		printf("Hero gaat naar west");
	}
	handleHeroPosition(hero, context);

	// als we in combat komen switchen naar combatstate ipv MapDrawState
	context->setState(new MapDrawState());

	delete expectedAnswers;
}

void HeroWalkState::handleHeroPosition(Hero* hero, Engine* context ) {
	MapType* maptype = context->getMaps()->at(Map::currentLevel).getMapType(hero->getPosX(), hero->getPosX());
	
	switch (maptype->getType()) {
	case Tile::Room:
		break;
	}

}