#pragma once
#include "Map.h"
#include "InputManager.h"
#include "Hero.h"

class Engine {
private:
	Hero* m_hero;
public :
    Map* map;
 
    Engine();
    ~Engine();
    void update();
    void render();
	void initHero();
	void loop();
};
 
extern Engine engine;