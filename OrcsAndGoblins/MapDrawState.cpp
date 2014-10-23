#include "stdafx.h"
#include "mapDrawState.h"

void MapDrawState::handle(Engine* context) {
	std::vector<Map>* maps = context->getMaps();

	
		maps->at(Map::currentLevel - 1).Print();


	context->setState(new HeroWalkState());
}