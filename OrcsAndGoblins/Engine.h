#pragma once
#include "stdafx.h"
#include "Map.h"
#include "InputManager.h"
#include "Hero.h"
#include "EngineState.h"
#include "MapGenerator.h"
#include "HeroWalkState.h"
#include "MapDrawState.h"
class Engine {
private:
	Hero* m_hero;
	MapGenerator* m_mapgen = new MapGenerator;
	std::vector<Map>* m_maps;
	EngineState* m_state = nullptr;

public :
    Map* map;
 
    Engine();
    virtual ~Engine();
    void update();
    void render();
	void initHero();
	void initMap();
	void loop();
	void setState(EngineState* state);

	Hero* getHero();
	MapGenerator* getMapGen();
	std::vector<Map>* getMaps();
};
 
extern Engine engine;