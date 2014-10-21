#pragma once
#include "stdafx.h"
#include "Map.h"
#include "InputManager.h"
#include "Hero.h"
#include "EngineState.h"
#include "MapGenerator.h"
#include "HeroWalkState.h"
class Engine {
private:
	Hero* m_hero;
	EngineState* m_state = nullptr;

public :
    Map* map;
 
    Engine();
    virtual ~Engine();
    void update();
    void render();
	void initHero();
	void loop();
	void setState(EngineState* state);

	Hero* getHero();
};
 
extern Engine engine;