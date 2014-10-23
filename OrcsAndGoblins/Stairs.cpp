#include "stdafx.h"
#include "Stairs.h"


Stairs::Stairs()
{
}


Stairs::~Stairs()
{
}

Stairs::Stairs(int to, int from) : toLevel(to), fromLevel(from)
{

}

Tile Stairs::getType()
{
	return type;
}

void Stairs::setType(Tile type)
{
	this->type = type;
}

int Stairs::getFromLevel()
{
	return fromLevel;
}

int Stairs::getToLevel()
{
	return toLevel;
}