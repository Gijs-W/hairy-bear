#pragma once
#include "stdafx.h"
#include <iostream>
#include <vector>
#include "MapType.h"
#include "Room.h"
#include "Corridor.h"
#include "Unused.h"

enum class Direction
{
	North, South, East, West,
};

class Map
{
public:
	Map();
	virtual ~Map();
	Map(int x, int y, int level, Tile value = Tile::Unused);
	void SetCell(int x, int y, Tile type);
	Tile GetCell(int x, int y) const;
	bool IsXInBounds(int x) const;
	bool IsYInBounds(int y) const;
	bool IsAreaUnused(int xStart, int yStart, int xEnd, int yEnd);
	bool IsAdjacent(int x, int y, Tile tile);
	void checkEndRooms();
	void setLevel(int level);
	int getLevel();
	void Print() const;
	MapType* makeRoom(Tile tile, int x, int y);
	MapType* makeStairs(int x, int y);
	MapType* makeCorridor(int x, int y, MapType* sourceRoom, MapType* targetRoom, Direction direction);
	MapType* makeUnused(int x, int y);
	MapType* getMapType(int x, int y);
	static int currentLevel;
private:
	bool checkIfEntityExists(MapType* type);
	void deleteFromEntities(int x, int y);
	int level;
	int xSize, ySize;
	
	std::vector<MapType*>* allEntities = new std::vector<MapType*>();
	std::vector<MapType*>* rooms = new std::vector<MapType*>();
	std::vector<MapType*>* corridors = new std::vector<MapType*>();
	std::vector<MapType*>* stairs = new std::vector<MapType*>();
	std::vector<MapType*>* unuseds = new std::vector<MapType*>();
	std::vector<Tile> data;
};

