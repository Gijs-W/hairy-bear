#pragma once
#include "Map.h"
#include "InputManager.h"

class Engine {
public :
    Map* map;
 
    Engine();
    ~Engine();
    void update();
    void render();
	void loop();
};
 
extern Engine engine;