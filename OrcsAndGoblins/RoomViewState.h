#pragma once

#include "EngineState.h"
#include "Engine.h"

class RoomViewState : public EngineState {
private:
	Room* m_room; 
public:

	RoomViewState(Room* room);

	void handle(Engine* context);
};