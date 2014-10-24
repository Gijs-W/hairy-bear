#pragma once

#include "EngineState.h"
#include "Engine.h"
class HeroWalkState : public EngineState {
private:
	void handleHeroPosition(Hero* hero, Engine* context);
	bool isWalkableTile(MapType* type);

public:
	void handle(Engine* context);
};