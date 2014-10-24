#include "stdafx.h"
#include "Engine.h"


Engine::Engine() {
	m_state = new MapDrawState();
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
	for (int i = 0; i < m_maps->size(); i++)
	{
		if (!(m_maps->at(i).getHero() == m_hero) && m_maps->at(i).getLevel() == Map::currentLevel)
		{
			m_maps->at(i).setHero(m_hero);
		}
	}
}

void Engine::initMap()
{
	m_maps = m_mapgen->generate();
	Map::currentLevel = 1; // beginnen op level 1;

	for (int i = 0; i < m_maps->size(); i++)
	{
		if (!(m_maps->at(i).getHero() == m_hero) && m_maps->at(i).getLevel() == Map::currentLevel)
		{
			m_maps->at(i).setHero(m_hero);
			m_maps->at(i).getHero()->setPosX((m_maps->at(i).getXsize()) /2);
			m_maps->at(i).getHero()->setPosY((m_maps->at(i).getYsize()) /2);
		}
	}		
}

void Engine::initHero() {
	string name = InputManager::getInstance()->requestInput("Voer de naam van je hero in:");
	m_hero = new Hero;
	m_hero->setName(name);

}

void Engine::loop(){

	//InputManager* manager = InputManager::getInstance();
	while (true)
	{
		this->update();
		m_state->handle(this);
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

