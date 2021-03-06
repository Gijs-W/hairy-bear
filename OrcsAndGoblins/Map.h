#pragma once
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <random>
#include <cassert>
#include "MapType.h"
#include "Room.h"
#include "Corridor.h"
#include "Unused.h"
#include "Hero.h"
#include "Stairs.h"

enum class Direction
{
	North, South, East, West,
};

class Map
{
public:
	typedef std::mt19937 RngT;
	Map();

	virtual ~Map();
	Map(int x, int y, int level, Tile value = Tile::Unused);

	int getXsize();
	int getYsize();
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

	Hero* getHero();
	void setHero(Hero* hero);
	MapType* getEndRoom(RngT& rng);
	MapType* makeRoom(Tile tile, int x, int y);
	MapType* makeStairs(int x, int y, int to, Tile type);
	MapType* makeCorridor(int x, int y, MapType* sourceRoom, MapType* targetRoom, Direction direction);
	MapType* makeUnused(int x, int y);
	MapType* getMapType(int x, int y);
	static int currentLevel;
	static void setcurrentLevel(int level);
private:

	bool checkIfEntityExists(int x, int y);
	void deleteFromEntities(int x, int y);
	int level;
	int xSize, ySize;
	Hero* hero;

	std::vector<MapType*>* allEntities = new std::vector<MapType*>();
	std::vector<MapType*>* rooms = new std::vector<MapType*>();
	std::vector<MapType*>* corridors = new std::vector<MapType*>();
	std::vector<MapType*>* stairs = new std::vector<MapType*>();
	std::vector<MapType*>* unuseds = new std::vector<MapType*>();
	std::vector<MapType*>* roomCorridors = new std::vector<MapType*>();
	std::vector<Tile> data;
};

