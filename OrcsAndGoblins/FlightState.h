#pragma once
#include "EngineState.h"
#include "RoomViewState.h"
#include "Room.h"
class FlightState : public EngineState
{
public:
	FlightState(Room* room);
	virtual ~FlightState();
	void handle(Engine* context);
private:
	Room* currentRoom;
	bool checkIfCanFlight();
	bool isWalkableTile(MapType* type);
};

