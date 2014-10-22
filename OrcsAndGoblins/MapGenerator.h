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

	Map generate();

private:
	typedef std::mt19937 RngT;
	bool checkIfUnused(Map& map,int x, int y);
	bool MakeDungeon(Map& map, RngT& rng);
	bool MakeRoom(Map& map, RngT& rng, int x, int y, Direction direction, Tile type, MapType* sourceRoom);
	bool MakeFirstRoomInDungeon(Map& map, RngT& rng, int x, int y, Tile type);
	bool MakeCorridor(Map& map, RngT& rng, int x, int y, Direction direction);
	bool MakeStairs(Map& map, RngT& rng, Tile tile);
	Direction GetRandomDirection(RngT& rng);

};

