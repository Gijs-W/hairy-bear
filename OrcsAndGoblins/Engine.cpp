#include "stdafx.h"
#include "Engine.h"
#include "MapGenerator.h"

Engine::Engine() {

}

Engine::~Engine() {
    //actors.clearAndDelete();
}

void Engine::render() {
    // draw the map
   // map->render();

}

void Engine::update() {

}

void Engine::loop(){
	bool getMessage = false;
	MapGenerator *m = new MapGenerator();
	m->generate();
	//InputManager* manager = InputManager::getInstance();
	while (getMessage){
		this->update();
		this->render();
	}
}