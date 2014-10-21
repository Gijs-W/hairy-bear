#include "stdafx.h"
#include "Room.h"


Room::Room()
{
	corridors = new std::vector<MapType*>();
}


Room::~Room()
{
	for (int i = corridors->size(); i >= 0; i--)
	{
		MapType *c = corridors->at(i);
		delete c;
	}
	delete corridors;
}

void Room::addCorridor(MapType* corridor)
{
	corridors->push_back(corridor);
}

std::vector<MapType*>* Room::getCorridors()
{
	return corridors;
}

void Room::setVisited(bool visit)
{
	visited = visit;
	if (visited)
	{
		setType(Tile::Room);
	}
}

bool Room::getVisited()
{
	return visited;
}

void Room::setType(Tile tile)
{
	type = tile;
}