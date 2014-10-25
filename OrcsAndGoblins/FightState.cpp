#include "stdafx.h"
#include "FightState.h"


FightState::FightState(Room* room)
{
	currentRoom = room;
}


FightState::~FightState()
{
}

void FightState::handle(Engine* context)
{
	printf("\nJe bent in gevecht met: \n");
	std::vector<Enemy*>* enemies = currentRoom->getEnemies();
	for (int i = 0; i < enemies->size(); i++)
	{
		Enemy* enemy = enemies->at(i);
		std::cout << enemy->getName() + " " + std::to_string(i) + ": met " + std::to_string(enemy->getHealth()) + " levenspunten" << std::endl;
	}
	vector<string> *expectedAnswers = new vector < string >;
	expectedAnswers->push_back("test");
	InputManager::getInstance()->requestInput("Wat doe je?", expectedAnswers);
}