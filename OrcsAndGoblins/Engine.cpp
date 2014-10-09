#include "stdafx.h"
#include "Engine.h"
#include "Map.h"
Map *map;

Engine::Engine() {

	int *w = new int;
	int *h = new int;
	*w = 70;
	*h = 40;
    map = new Map(w, h);
}

Engine::~Engine() {
    //actors.clearAndDelete();
    delete map;
}

void Engine::render() {
    // draw the map
    map->render();

}

void Engine::update() {

}