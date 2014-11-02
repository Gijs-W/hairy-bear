#include "stdafx.h"
#include "Unused.h"


Unused::Unused()
{
}


Unused::~Unused()
{
}

Tile Unused::getType()
{
	return Tile::Unused;
}

void Unused::setType(Tile type)
{
	this->type = type;
}