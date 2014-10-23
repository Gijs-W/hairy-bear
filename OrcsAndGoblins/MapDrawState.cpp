#include "stdafx.h"
#include "mapDrawState.h"

void MapDrawState::handle(Engine* context) {
	std::vector<Map>* maps = context->getMaps();

	
		maps->at(Map::currentLevel).Print();


	context->setState(new HeroWalkState());
}