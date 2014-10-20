#include "stdafx.h"
#include "MapGenerator.h"



MapGenerator::~MapGenerator()
{
}

Map MapGenerator::generate()
{
	auto rng = RngT(rngSeed);
	Map map = Map(x, y, Tile::Unused);
	MakeDungeon(map, rng);
	map.Print();
	return map;
}

bool MapGenerator::MakeDungeon(Map& map, RngT& rng)
{
	MakeRoom(map, rng, x / 2, y / 2, GetRandomDirection(rng), Tile::Room); //midden in de map een kamer maken
	return false;
}

bool MapGenerator::MakeRoom(Map& map, RngT& rng, int x, int y, Direction direction, Tile tile)
{
	if (map.IsXInBounds(x) && map.IsYInBounds(y))
	{
		map.SetCell(x, y, tile);
		switch (direction)
		{
		case(Direction::North) :
			MakeRoom(map, rng, x, y - 1, GetRandomDirection(rng), Tile::UndiscoveredRoom);
			break;
		case(Direction::South) :
			MakeRoom(map, rng, x, y + 1, GetRandomDirection(rng), Tile::UndiscoveredRoom);
			break;
		case(Direction::East) :
			MakeRoom(map, rng, x + 1, y, GetRandomDirection(rng), Tile::UndiscoveredRoom);
			break;
		case(Direction::West) :
			MakeRoom(map, rng, x - 1, y, GetRandomDirection(rng), Tile::UndiscoveredRoom);
			break;
		}
	}
	//doe iets met description;
	return false;

}

bool MapGenerator::MakeStairs(Map& map, RngT& rng, Tile tile)
{
	return false;

}

Direction MapGenerator::GetRandomDirection(RngT& rng)
{
	return Direction(std::uniform_int_distribution<int>(0, 3)(rng));
}

