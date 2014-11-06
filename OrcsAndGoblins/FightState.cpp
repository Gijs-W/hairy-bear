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
	if (monstersLeft)
	{
		printf("\nJe bent in gevecht met: \n");
		std::vector<Enemy*>* enemies = currentRoom->getEnemies();
		for (int i = 0; i < enemies->size(); i++)
		{
			Enemy* enemy = enemies->at(i);
			std::cout << enemy->getName() + " " + std::to_string(i + 1) + ": met " + std::to_string(enemy->getHealth()) + " levenspunten" << std::endl;
		}
		vector<string> *expectedAnswers = new vector < string >;
		expectedAnswers->push_back("aanvallen");
		expectedAnswers->push_back("vluchten");
		expectedAnswers->push_back("inventory");

		std::string action = InputManager::getInstance()->requestInput("Wat doe je?", expectedAnswers);
		if (action == "vluchten")
		{
			context->setState(new FlightState(currentRoom));
		}
		else if (action == "aanvallen")
		{
			int m_attackLevel = context->getHero()->getAttackLevel();
			for (int i = 0; i < enemies->size(); i++)
			{
				//jij mag eerst aanvallen
				int m_dmg = (rand() % 10) * (m_attackLevel);
				int m_dmgdone = enemies->at(i)->attack(m_dmg);
				std::cout << "Je valt " + enemies->at(i)->getName() + " " + std::to_string(i + 1) + " aan voor " + std::to_string(m_dmgdone) + " levenspunten" << std::endl;

				if (checkIfEnemyHasHP(enemies->at(i)))
				{
					//nu valt enemy aan
					int m_herodamage = enemies->at(i)->doAttack();
					int m_realherodamage = (((m_herodamage * 100) - context->getHero()->getDefenseLevel()) / 100); //armor berekening
					std::cout << enemies->at(i)->getName() + " " + std::to_string(i + 1) + " valt jou aan voor " + std::to_string(m_realherodamage) + " levenspunten" << std::endl;
					context->getHero()->setHealth((context->getHero()->getHealth() - m_realherodamage));
					if (context->getHero()->getHealth() < 0)
					{
						std::cout << "Je bent doodgegaan!" << endl;
						context->setState(new DieState());
					}
					else
					{
						std::cout << "Je hebt nog " + std::to_string(context->getHero()->getHealth()) + " levenspunten over" << std::endl;
					}
				}
				else
				{
					std::cout << enemies->at(i)->getName() + " " + std::to_string(i + 1) + " is verslagen" << std::endl;
					std::cout << "Je heb " + std::to_string(enemies->at(i)->getXP()) + " xp verdient aan het verslaan van " + enemies->at(i)->getName() +" " + std::to_string(i + 1) << std::endl;
					context->getHero()->setAttackXP(enemies->at(i)->getXP());
					context->getHero()->setDefenceXP(enemies->at(i)->getXP());
					printf("\n"); //extra enter
					scheduleEnemyForRemoval(enemies->at(i));

					if (enemies->size() == 0)
					{
						monstersLeft = false;
					}
					//break; //TODO :: kijken of deze break hier goed staat
				}
			}
		}
		delete expectedAnswers;
	}
	else
	{
		context->setState(new RoomViewState(currentRoom));
	}
}

bool FightState::checkIfEnemyHasHP(Enemy* enemy)
{ 
	if (enemy->getHealth() <= 0)
	{
		return false;
	}
	else
		return true;
}

void FightState::scheduleEnemyForRemoval(Enemy* enemy)
{
	std::vector<Enemy*>* enemies = currentRoom->getEnemies();
	for (int i = 0; i < enemies->size(); i++)
	{
		if (enemy == enemies->at(i))
		{
			enemies->erase(enemies->begin() + i);
			delete enemy;
		}
	}
}