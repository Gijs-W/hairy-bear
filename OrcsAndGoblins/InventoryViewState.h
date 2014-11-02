#pragma once

#include "EngineState.h"
#include "Engine.h"
#include "RoomViewState.h"
class InventoryViewState : public EngineState {
private:
	Room* m_comingFromRoom;
public:
	InventoryViewState(Room* room);
	void handle(Engine* context);
};