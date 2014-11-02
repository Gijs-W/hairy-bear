#pragma once

#include "EngineState.h"
#include "Engine.h"
class MapDrawState : public EngineState {
	void handle(Engine* context);
public:
	MapDrawState(Room* room);
private:
	Room* curRoom = nullptr;
};