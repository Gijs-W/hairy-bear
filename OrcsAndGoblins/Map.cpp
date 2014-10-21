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

void Map::Print() const
{
	for (int j = 0; j < ySize; j++)
	{
		for (int i = 0; i < xSize; i++)
		{
			Tile t = GetCell(i, j);
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
		std::cout << std::endl;
	}
}

int xSize, ySize;
 
std::vector<Tile> data;
