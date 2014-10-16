#include "stdafx.h"
#include "MapGenerator.h"


MapGenerator::MapGenerator()
{
}


MapGenerator::~MapGenerator()
{
}

Map MapGenerator::generate()
{
	auto rng = RngT(rngSeed);
	Map map = Map(x, y, Tile::Unused);
	MakeDungeon(map, rng);
}

bool MapGenerator::MakeDungeon(Map& map, RngT& rng)
{
	MakeRoom(map, rng, x/2, y/2, GetRandomDirection(rng)); //midden in de map een kamer maken
	return false;
}

bool MapGenerator::MakeRoom(Map& map, RngT& rng, int x, int y, Direction direction)
{
	map.SetCell(x, y, Tile::Room);
	//doe iets met description;
	std::uniform_int_distribution<int>(0, chanceRoom)(rng);


}

bool MapGenerator::MakeStairs(Map& map, RngT& rng, Tile tile)
{

}

Direction MapGenerator::GetRandomDirection(RngT& rng)
{
	return Direction(std::uniform_int_distribution<int>(0, 3)(rng));
}