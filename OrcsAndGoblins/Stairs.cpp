#include "stdafx.h"
#include "Stairs.h"


Stairs::Stairs()
{
}


Stairs::~Stairs()
{
}

Stairs::Stairs(int from, int to) : toLevel(to), fromLevel(from)
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

void Stairs::setVisited(bool visit)
{
	visited = visit;
	if (visited)
	{
		switch (type)
		{
		case(Tile::UndiscoveredStairsUp) :
			setType(Tile::StairsUp);
			break;
		case(Tile::UndiscoveredStairsDown) :
			setType(Tile::StairsDown);
			break;
		}
	}
}

bool Stairs::getVisited()
{
	return visited;
}
