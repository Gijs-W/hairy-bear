#include "stdafx.h"
#include "HeroWalkState.h"
#include "RoomViewState.h"
void HeroWalkState::handle(Engine* context) {
	Hero* hero = context->getHero();
	MapType* northMap = context->getMaps()->at(Map::currentLevel -1).getMapType(hero->getPosX(), hero->getPosY() - 1);
	MapType* southMap = context->getMaps()->at(Map::currentLevel - 1).getMapType(hero->getPosX(), hero->getPosY() + 1);
	MapType* eastMap = context->getMaps()->at(Map::currentLevel - 1).getMapType(hero->getPosX() + 1, hero->getPosY());
	MapType* westMap = context->getMaps()->at(Map::currentLevel - 1).getMapType(hero->getPosX() - 1, hero->getPosY());


	vector<string> *expectedAnswers = new vector < string > ;
	if (isWalkableTile(northMap)) expectedAnswers->push_back("noord");
	if (isWalkableTile(southMap)) expectedAnswers->push_back("zuid");
	if (isWalkableTile(eastMap)) expectedAnswers->push_back("oost");
	if (isWalkableTile(westMap)) expectedAnswers->push_back("west");

	

	string direction = InputManager::getInstance()->requestInput("Welke Richting?", expectedAnswers);

	if (direction == "noord") {
		hero->setPosY(hero->getPosY() - 1);
		printf("Hero gaat naar noord\n");
	}
	else if (direction == "zuid") {
		hero->setPosY(hero->getPosY() + 1);
		printf("Hero gaat naar zuid\n");
	}
	else if (direction == "oost") {
		hero->setPosX(hero->getPosX() + 1);
		printf("Hero gaat naar oost\n");
	}
	else if (direction == "west") {
		hero->setPosX(hero->getPosX() - 1);
		printf("Hero gaat naar west\n");
	}
	handleHeroPosition(hero, context);

	

	delete expectedAnswers;
}

void HeroWalkState::handleHeroPosition(Hero* hero, Engine* context ) {
	MapType* maptype = context->getMaps()->at(Map::currentLevel -1).getMapType(hero->getPosX(), hero->getPosY());
	
	// ooit nog is een visitor pattern hier inbouwen
	Room* room = dynamic_cast<Room*>(maptype);

	if (room) {
		//room
		context->setState(new RoomViewState(room));
	}
	else {
		Stairs* stairs = dynamic_cast<Stairs*>(maptype);
		if (stairs)
		{
			context->setState(new StairsViewState(stairs));
		}
		//context->setState(new RoomViewState(new Room()));
		//context->setState(new MapDrawState());
	}
}

bool HeroWalkState::isWalkableTile(MapType* type) {
	if (type == nullptr) return false;

	Tile tile = type->getType();

	switch (tile) {
		/* falltrough*/
	case Tile::Unused:
		return false;
	default:
		return true;
	}
}