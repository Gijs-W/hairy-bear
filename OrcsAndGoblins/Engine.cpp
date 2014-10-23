#include "stdafx.h"
#include "Engine.h"


Engine::Engine() {
	m_state = new HeroWalkState();
}

Engine::~Engine() {
    //actors.clearAndDelete();
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
	MapGenerator *m = new MapGenerator();
	std::vector<Map>* maps = m->generate();

	for (int i = 0; i < maps->size(); i++)
	{
		maps->at(i).Print();
	}

	m_state->handle(this);
	//InputManager* manager = InputManager::getInstance();
	while (getMessage){
		
		this->update();
		this->render();
	}
}

Hero* Engine::getHero() {
	return m_hero;
}

void Engine::setState(EngineState* state) {
	delete m_state; // vorige status opruimen. 
	m_state = state;
}