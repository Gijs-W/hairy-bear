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
