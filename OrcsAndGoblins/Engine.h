#pragma once
#include "Map.h"
class Engine {
public :
    Map* map;
 
    Engine();
    ~Engine();
    void update();
    void render();
};
 
extern Engine engine;