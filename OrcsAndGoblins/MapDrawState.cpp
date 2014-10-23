#include "stdafx.h"
#include "mapDrawState.h"

void MapDrawState::handle(Engine* context) {
	std::vector<Map>* maps = context->getMaps();

	for (int i = 0; i < maps->size(); i++)
	{
		maps->at(i).Print();
	}


	context->setState(new HeroWalkState());
}