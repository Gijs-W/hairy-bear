#include "stdafx.h"
#include "MapType.h"


MapType::MapType()
{
}


MapType::~MapType()
{
}

Tile MapType::getType()
{
	return type;
}

int MapType::getX()
{
	return x;
}

int MapType::getY()
{
	return y;
}

void MapType::setX(int x)
{
	this->x = x;
}

void MapType::setY(int y)
{
	this->y = y;
}

void MapType::setType(Tile type)
{
	this->type = type;
}

bool MapType::getVisited()
{
	return visited;
}

void MapType::setVisited(bool visit)
{
	visited = visit;
}