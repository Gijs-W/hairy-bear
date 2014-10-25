#include "stdafx.h"
#include "mapDrawState.h"
MapDrawState::MapDrawState(Room* room)
{
	curRoom = room;
}
void MapDrawState::handle(Engine* context) {
	std::vector<Map>* maps = context->getMaps();

	
		maps->at(Map::currentLevel - 1).Print();


		context->setState(new RoomViewState(curRoom));
}