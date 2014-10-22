#include "stdafx.h"
#include "Map.h"
#include <iostream>
#include <string>
#include <random>
#include <cassert>

Map::Map() : xSize(0), ySize(0), data()
{
}

Map::Map(int x, int y, Tile value):	xSize(x), ySize(y),	data(x * y, value)
{
	for (int i = 0; i < ySize; i++)
	{
		for (int j = 0; j < xSize; j++)
		{
			makeUnused(i, j);
		}
	}
}

Map::~Map()
{

}


void Map::SetCell(int x, int y, Tile type)
{
	assert(IsXInBounds(x));
	assert(IsYInBounds(y));

	data[x + xSize * y] = type;
}

Tile Map::GetCell(int x, int y) const
{
	assert(IsXInBounds(x));
	assert(IsYInBounds(y));

	return data[x + xSize * y];
}

bool Map::IsXInBounds(int x) const
{
	return x >= 0 && x < xSize;
}

bool Map::IsYInBounds(int y) const
{
	return y >= 0 && y < ySize;
}

bool Map::IsAdjacent(int x, int y, Tile tile)
{
	assert(IsXInBounds(x - 1) && IsXInBounds(x + 1));
	assert(IsYInBounds(y - 1) && IsYInBounds(y + 1));

	return 
		GetCell(x - 1, y) == tile || GetCell(x + 1, y) == tile ||
		GetCell(x, y - 1) == tile || GetCell(x, y + 1) == tile;
}

bool Map::checkIfEntityExists(MapType* type)
{
	bool value = false;
	if (allEntities->size() == 0)
		return value;
	else
	{
		for (int i = 0; i < allEntities->size(); i++)
		{
			MapType* entity = allEntities->at(i);
			if (entity->getX() == type->getX() && entity->getY() == type->getY())
			{
				value = true;
			}
		}
	}

	return value;
}

void Map::deleteFromEntities(int x, int y)
{
	for (int i = 0; i < allEntities->size(); i++)
	{
		MapType* entity = allEntities->at(i);
		if (entity->getX() == x && entity->getY() == y)
		{
			allEntities->erase(allEntities->begin() + i);
		}
	}
}

MapType* Map::makeRoom(Tile tile, int x, int y)
{
	MapType *room = new Room(tile);
	room->setX(x);
	room->setY(y);
	rooms->push_back(room);
	if (checkIfEntityExists(room))
		deleteFromEntities(room->getX(), room->getY());

	allEntities->push_back(room);
	return room;
}

MapType* Map::makeUnused(int x, int y)
{
	MapType *unused = new Unused();
	unused->setX(x);
	unused->setY(y);
	unuseds->push_back(unused);
	allEntities->push_back(unused);
	return unused;
}
//
//MapType Map::makeStairs(int x, int y);
//{
//
//}
//
//MapType Map::makeCorridor(int x, int y);
//{
//
//}


void Map::Print() const
{
	for (int j = 0; j < ySize; j++)
	{
		for (int i = 0; i < xSize; i++)
		{
			for (int k = 0; k < allEntities->size(); k++)
			{
				MapType *r = allEntities->at(k);
				if (r->getX() == i && r->getY() == j)
				{
					Tile t = r->getType();
					switch (t)
					{
					case(Tile::CorridorVertical) :
						printf("|"); 
						break;
					case(Tile::CorridorHorizontal) :
						printf("-");
						break;
					case(Tile::Unused) :
						printf(".");
						break;
					case(Tile::Room) :
						printf("0");
						break;
					case(Tile::UndiscoveredRoom) :
						printf("O");
						break;
					case(Tile::RoomCorridor) :
						printf("x");
						break;
					}
				}
			}
			//Tile t = GetCell(i, j);
		}
		std::cout << std::endl;
	}
}

int xSize, ySize;
 
std::vector<Tile> data;
