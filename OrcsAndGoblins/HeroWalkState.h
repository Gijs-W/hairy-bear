#pragma once

#include "EngineState.h"
#include "Engine.h"
class HeroWalkState : public EngineState {
private:
	void handleHeroPosition(Hero* hero, Engine* context);


public:
	void handle(Engine* context);
};