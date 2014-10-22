#include "stdafx.h"
#include "Corridor.h"


Corridor::Corridor()
{
}

Corridor::Corridor(Tile tile) : type(tile)
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
