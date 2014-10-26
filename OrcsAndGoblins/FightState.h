#pragma once
#include "EngineState.h"
#include "RoomViewState.h"
#include "Room.h"
class FightState : public EngineState
{
public:
	FightState(Room* room);
	virtual ~FightState();
	void handle(Engine* context);
private:
	Room* currentRoom;
	bool monstersLeft = true;
};

