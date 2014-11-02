#pragma once
#include "EngineState.h"
#include "RoomViewState.h"
#include "FlightState.h"
#include "Room.h"
class FightState : public EngineState
{
public:
	FightState(Room* room);
	virtual ~FightState();
	void handle(Engine* context);
private:
	bool checkIfEnemyHasHP(Enemy* enemy);
	void scheduleEnemyForRemoval(Enemy* enemy);
	Room* currentRoom;
	bool monstersLeft = true;
};

