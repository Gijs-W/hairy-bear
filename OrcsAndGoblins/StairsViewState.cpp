#include "stdafx.h"
#include "StairsViewState.h"


StairsViewState::StairsViewState(Stairs* stairs)
{
	this->thisStairs = stairs;
}


StairsViewState::~StairsViewState()
{
}

void StairsViewState::handle(Engine* context)
{
	Hero* hero = context->getHero();
	MapType* northMap = context->getMaps()->at(Map::currentLevel - 1).getMapType(hero->getPosX(), hero->getPosY() - 1);
	MapType* southMap = context->getMaps()->at(Map::currentLevel - 1).getMapType(hero->getPosX(), hero->getPosY() + 1);
	MapType* eastMap = context->getMaps()->at(Map::currentLevel - 1).getMapType(hero->getPosX() + 1, hero->getPosY());
	MapType* westMap = context->getMaps()->at(Map::currentLevel - 1).getMapType(hero->getPosX() - 1, hero->getPosY());


	vector<string> *expectedAnswers = new vector < string >;
	if (isWalkableTile(northMap)) expectedAnswers->push_back("noord");
	if (isWalkableTile(southMap)) expectedAnswers->push_back("zuid");
	if (isWalkableTile(eastMap)) expectedAnswers->push_back("oost");
	if (isWalkableTile(westMap)) expectedAnswers->push_back("west");
	MapType* curPos = context->getMaps()->at(Map::currentLevel - 1).getMapType(hero->getPosX(), hero->getPosY());

	if (curPos->getType() == Tile::StairsDown || curPos->getType() == Tile::StairsUp || curPos->getType() == Tile::UndiscoveredStairsDown || curPos->getType() == Tile::UndiscoveredStairsUp)
	{
		if (thisStairs->getToLevel() > Map::currentLevel)
		{
			expectedAnswers->push_back("naar beneden");
		}
		else
		{
			expectedAnswers->push_back("naar boven");
		}
	}

	string direction = InputManager::getInstance()->requestInput("Welke Richting?", expectedAnswers);
	bool handle = true;
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
	else if (direction == "naar beneden")
	{
		Map::setcurrentLevel(Map::currentLevel + 1);
		printf("Je gaat de trap omlaag");
		handle = false;
	}
	else if (direction == "naar boven")
	{
		Map::setcurrentLevel(Map::currentLevel - 1);
		printf("Je gaat de trap omhoog");
		handle = false;
	}
	if (handle)
		handleHeroPosition(hero, context);

	delete expectedAnswers;
}

void StairsViewState::handleHeroPosition(Hero* hero, Engine* context) {
	MapType* maptype = context->getMaps()->at(Map::currentLevel - 1).getMapType(hero->getPosX(), hero->getPosY());

	// ooit nog is een visitor pattern hier inbouwen
	Room* room = dynamic_cast<Room*>(maptype);

	if (room) {
		//room
		context->setState(new RoomViewState(room));
	}
	else {
		//context->setState(new RoomViewState(new Room()));
		//context->setState(new MapDrawState());
	}
}

bool StairsViewState::isWalkableTile(MapType* type) {
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