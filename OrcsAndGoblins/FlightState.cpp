#include "stdafx.h"
#include "FlightState.h"


FlightState::FlightState(Room* room)
{
	currentRoom = room;
}


FlightState::~FlightState()
{
}

void FlightState::handle(Engine* context)
{
	Hero* hero = context->getHero();
	MapType* northMap = context->getMaps()->at(Map::currentLevel - 1).getMapType(hero->getPosX(), hero->getPosY() - 1);
	MapType* southMap = context->getMaps()->at(Map::currentLevel - 1).getMapType(hero->getPosX(), hero->getPosY() + 1);
	MapType* eastMap = context->getMaps()->at(Map::currentLevel - 1).getMapType(hero->getPosX() + 1, hero->getPosY());
	MapType* westMap = context->getMaps()->at(Map::currentLevel - 1).getMapType(hero->getPosX() - 1, hero->getPosY());

	if (checkIfCanFlight())
	{
		printf("Je bent gevlucht van de monsters! \n");
		if (isWalkableTile(northMap))
		{
			printf("Je bent 1 positie naar het noorden gevlucht! \n");
			hero->setPosY(hero->getPosY() - 1);
		}
		else if (isWalkableTile(southMap))
		{
			printf("Je bent 1 positie naar het zuiden gevlucht! \n");
			hero->setPosY(hero->getPosY() + 1);
		}
		else if (isWalkableTile(eastMap))
		{
			printf("Je bent 1 positie naar het oosten gevlucht! \n");
			hero->setPosX(hero->getPosX() + 1);
		}
		else if (isWalkableTile(westMap))
		{
			printf("Je bent 1 positie naar het westen gevlucht! \n");
			hero->setPosX(hero->getPosX() - 1);
		}
		context->setState(new HeroWalkState());
		//flight
	}
	else
	{
		printf("Je hebt niet kunnen vluchten! \n");
		context->setState(new FightState(currentRoom));
		//cant flight
	}
}

bool FlightState::checkIfCanFlight()
{
	Enemy* enemy = currentRoom->getEnemies()->at(0);
	int flightchance = rand() % 100;
	if (flightchance < enemy->getFlightChance())
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool FlightState::isWalkableTile(MapType* type) {
	if (type == nullptr) return false;

	Tile tile = type->getType();

	switch (tile) {
		/* falltrough*/
	case Tile::CorridorHorizontal:
		return true;
	case Tile::CorridorVertical:
		return true;
	default:
		return false;
	}
}