#pragma once
#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Room.h"

enum class Direction
{
	North, South, East, West,
};

class Map
{
public:
	Map();
	virtual ~Map();
	Map(int x, int y, Tile value = Tile::Unused);
	void SetCell(int x, int y, Tile type);
	Tile GetCell(int x, int y) const;
	bool IsXInBounds(int x) const;
	bool IsYInBounds(int y) const;
	bool IsAreaUnused(int xStart, int yStart, int xEnd, int yEnd);
	bool IsAdjacent(int x, int y, Tile tile);
	void Print() const;


private:
	int xSize, ySize;
	std::vector<MapType> rooms;
	std::vector<MapType> stairs;
	std::vector<Tile> data;
};

