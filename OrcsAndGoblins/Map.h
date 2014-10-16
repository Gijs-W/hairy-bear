#pragma once
#include "stdafx.h"
#include <iostream>
#include <vector>

enum class Tile
{
	Unused,
	Corridor,
	Room,
	UpStairs,
	DownStairs
};

enum class Direction
{
	North, South, East, West,
};

class Map
{
public:
	Map();
	Map(int x, int y, Tile value = Tile::Unused);
	void SetCell(int x, int y, Tile celltype);
	Tile GetCell(int x, int y) const;
	void SetCells(int xStart, int yStart, int xEnd, int yEnd, Tile cellType);
	bool IsXInBounds(int x) const;
	bool IsYInBounds(int y) const;
	bool IsAreaUnused(int xStart, int yStart, int xEnd, int yEnd);
	bool IsAdjacent(int x, int y, Tile tile);
	void Print() const;

private:
	int xSize, ySize;
 
	std::vector<Tile> data;
};

