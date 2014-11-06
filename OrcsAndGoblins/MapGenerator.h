#pragma once
#include "stdafx.h"
#include "Map.h"
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include "MapType.h"

class MapGenerator
{
public:
	virtual ~MapGenerator();

	int rngSeed;
	int x, y;
	int maxFeatures;
	int chanceRoom, chanceCorridor;
	

	MapGenerator() : rngSeed(std::random_device() ()),
						x(20), y(20), maxFeatures(100), chanceRoom(90), chanceCorridor(10)
	{

	}

	std::vector<Map*>* generate();

private:
	typedef std::mt19937 RngT;
	void clearListMap();
	bool checkIfUnused(Map& map,int x, int y);
	bool MakeDungeon(Map& map, RngT& rng, int x, int y);
	MapType* MakeStairs(Map& map, RngT& rng, int x, int y, int toLevel, Tile type);
	bool MakeRoom(Map& map, RngT& rng, int x, int y, Direction direction, Tile type, MapType* sourceRoom, int level);
	bool MakeFirstRoomInDungeon(Map& map, RngT& rng, int x, int y, Tile type);
	bool MakeCorridor(Map& map, RngT& rng, int x, int y, Direction direction);

	MapType* getRandomFromCorridor(Map& map, RngT& rng);
	Direction GetRandomDirection(RngT& rng);
	int levels = 1;
	int maxLevels = 5;
	int xStairs;
	int yStairs;

	std::vector<Map*>* listMap = new std::vector<Map*>();

};

