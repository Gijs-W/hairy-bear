#include "stdafx.h"
#include "Engine.h"
#include "Map.h"
Map *map;

Engine::Engine() {

	//map = new Map(40, 70);
}

Engine::~Engine() {
    //actors.clearAndDelete();
    delete map;
	delete m_hero;
}

void Engine::render() {
    // draw the map
   // map->render();

}

void Engine::update() {

}

void Engine::initHero() {
	string name = InputManager::getInstance()->requestInput("Voer de naam van je hero in:");
	m_hero = new Hero;
	m_hero->setName(name);

}

void Engine::loop(){
	bool getMessage = false;
	
	//InputManager* manager = InputManager::getInstance();
	while (getMessage){
		this->update();
		this->render();
	}
}