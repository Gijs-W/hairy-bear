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


void Map::SetCell(int x, int y, Tile celltype)
{
	assert(IsXInBounds(x));
	assert(IsYInBounds(y));

	data[x + xSize * y] = celltype;
}

Tile Map::GetCell(int x, int y) const
{
	assert(IsXInBounds(x));
	assert(IsYInBounds(y));

	return data[x + xSize * y];
}

void Map::SetCells(int xStart, int yStart, int xEnd, int yEnd, Tile cellType)
{
	assert(IsXInBounds(xStart) && IsXInBounds(xEnd));
	assert(IsYInBounds(yStart) && IsYInBounds(yEnd));

	assert(xStart <= xEnd);
	assert(yStart <= yEnd);

	for (auto y = yStart; y != yEnd + 1; ++y)
		for (auto x = xStart; x != xEnd + 1; ++x)
			SetCell(x, y, cellType);
}

bool Map::IsXInBounds(int x) const
{
	return x >= 0 && x < xSize;
}

bool Map::IsYInBounds(int y) const
{
	return y >= 0 && y < ySize;
}

bool Map::IsAreaUnused(int xStart, int yStart, int xEnd, int yEnd)
{
	assert(IsXInBounds(xStart) && IsXInBounds(xEnd));
	assert(IsYInBounds(yStart) && IsYInBounds(yEnd));

	assert(xStart <= xEnd);
	assert(yStart <= yEnd);

	for (auto y = yStart; y != yEnd + 1; ++y)
		for (auto x = xStart; x != xEnd + 1; ++x)
			if (GetCell(x, y) != Tile::Unused)
				return false;

	return true;
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
	for (int i = 0; i < xSize; i++)
	{
		for (int j = 0; j < ySize; j++)
		{
			Tile t = GetCell(i, j);
			switch (t)
			{
			case(Tile::Unused) :
				printf("x");
				break;
			case(Tile::Room) :
				printf("0");
				break;
			case(Tile::UndiscoveredRoom) :
				printf(".");
				break;
			}
		}
	}
}

int xSize, ySize;
 
std::vector<Tile> data;
