#include "stdafx.h"
#include "Corridor.h"


Corridor::Corridor()
{
}

Corridor::Corridor(MapType* source, MapType* target) : source(source), target(target)
{

}


Corridor::~Corridor()
{
}

void Corridor::setType(Tile tile)
{
	type = tile;
}

Tile Corridor::getType()
{
	return type;
}

void Corridor::setVisited(bool visit)
{
	visited = visit;
	if (visited)
	{
		switch (type)
		{

		case(Tile::UndiscoveredCorridorHorizontal) :
			setType(Tile::CorridorHorizontal);
			break;
		case(Tile::UndiscoveredCorridorVertical) :
			setType(Tile::CorridorVertical);
			break;
		}
	}
}

bool Corridor::getVisited()
{
	return visited;
}
