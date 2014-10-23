#include "stdafx.h"
#include "Engine.h"


Engine::Engine() {
	m_state = new MapDrawState();
	m_maps = m_mapgen->generate();
}

Engine::~Engine() {
    //actors.clearAndDelete();
	delete m_hero;
	delete m_mapgen;
	delete m_state;
	delete m_maps;
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

	for (int i = 0; i < maps->size(); i++)
	{
		maps->at(i).Print();
		std::cout << std::endl;
	}

	//InputManager* manager = InputManager::getInstance();
	while (true){
	m_state->handle(this);
		this->update();
		this->render();
	}
}

Hero* Engine::getHero() {
	return m_hero;
}

MapGenerator* Engine::getMapGen() {
	return m_mapgen;
}
std::vector<Map>* Engine::getMaps() {
	return m_maps;
}

void Engine::setState(EngineState* state) {
	delete m_state; // vorige status opruimen. 
	m_state = state;
}

