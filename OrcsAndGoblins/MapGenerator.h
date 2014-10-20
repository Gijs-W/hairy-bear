#pragma once
#include "stdafx.h"
#include "Map.h"
#include <iostream>
#include <string>
#include <random>
#include <cassert>

class MapGenerator
{
public:
	virtual ~MapGenerator();

	int rngSeed;
	int x, y;
	int maxFeatures;
	int chanceRoom, chanceCorridor;

	MapGenerator() : rngSeed(std::random_device() ()),
						x(10), y(10), maxFeatures(100), chanceRoom(50), chanceCorridor(50)
	{

	}

	Map generate();

private:
	typedef std::mt19937 RngT;

	bool MakeDungeon(Map& map, RngT& rng);
	bool MakeRoom(Map& map, RngT& rng, int x, int y, Direction direction, Tile tile);
	bool MakeStairs(Map& map, RngT& rng, Tile tile);
	Direction GetRandomDirection(RngT& rng);

};

