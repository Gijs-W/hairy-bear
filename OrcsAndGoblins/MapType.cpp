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