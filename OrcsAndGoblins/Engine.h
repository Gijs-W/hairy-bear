#pragma once
#include "stdafx.h"
#include "Map.h"
#include "InputManager.h"
#include "Hero.h"
#include "EngineState.h"
#include "MapGenerator.h"
#include "HeroWalkState.h"
#include "MapDrawState.h"
#include "RoomViewState.h"
#include "HeroSaveLoad.h"
class Engine {
private:
	Hero* m_hero;
	MapGenerator* m_mapgen;
	std::vector<Map*>* m_maps;
	EngineState* m_state = nullptr;
	bool m_running = true;

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
	void save();

	Hero* getHero();
	MapGenerator* getMapGen();
	std::vector<Map*>* getMaps();
};
 
extern Engine engine;