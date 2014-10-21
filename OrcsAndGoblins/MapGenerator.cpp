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

bool MapGenerator::MakeCorridor(Map& map, RngT& rng, int x, int y, Direction direction)
{
	if (map.IsXInBounds(x) && map.IsYInBounds(y) && map.IsXInBounds(x + 1) && map.IsYInBounds(y + 1) 
		&& map.IsXInBounds(x -1) && map.IsYInBounds(y -1))
	{
		switch (direction)
		{
		case(Direction::North) :
			map.SetCell(x, y, Tile::CorridorVertical);
			break;
		case(Direction::South) :
			map.SetCell(x, y, Tile::CorridorVertical);
			break;
		case(Direction::East) :
			map.SetCell(x, y, Tile::CorridorHorizontal);
			break;
		case(Direction::West) :
			map.SetCell(x, y, Tile::CorridorHorizontal);
			break;
		}
	}
	return false;
}

bool MapGenerator::MakeRoom(Map& map, RngT& rng, int x, int y, Direction direction, Tile type)
{
	int maxTries = 4;
	int curTries = 1;

	if (map.IsXInBounds(x) && map.IsYInBounds(y))
	{
		for (int i = 1; i < maxTries; i++)
		{
			int rand = std::uniform_int_distribution<int>(0, chanceRoom + chanceCorridor)(rng);

			if (chanceRoom > 1)
			{
				direction = GetRandomDirection(rng);
				map.SetCell(x, y, type);
				switch (direction)
				{
				case(Direction::North) :
					if (checkIfUnused(map, x, y - 2))
					{
						MakeCorridor(map, rng, x, y - 1, direction);
						MakeRoom(map, rng, x, y - 2, GetRandomDirection(rng), Tile::UndiscoveredRoom);
					}
					break;
				case(Direction::South) :
					if (checkIfUnused(map, x, y + 2))
					{
						MakeCorridor(map, rng, x, y + 1, direction);
						MakeRoom(map, rng, x, y + 2, GetRandomDirection(rng), Tile::UndiscoveredRoom);
					}
					break;
				case(Direction::East) :
					if (checkIfUnused(map, x + 2, y))
					{
						MakeCorridor(map, rng, x + 1, y, direction);
						MakeRoom(map, rng, x + 2, y, GetRandomDirection(rng), Tile::UndiscoveredRoom);
					}
					break;
				case(Direction::West) :
					if (checkIfUnused(map, x - 2, y))
					{
						MakeCorridor(map, rng, x - 1, y, direction);
						MakeRoom(map, rng, x - 2, y, GetRandomDirection(rng), Tile::UndiscoveredRoom);
					}
					break;
				}
			}
			else
			{

				map.SetCell(x, y, type);
				//switch (direction)
				//{
				//case(Direction::North) :
				//	MakeRoom(map, rng, x, y - 1, GetRandomDirection(rng), Tile::UndiscoveredRoom);
				//	break;
				//case(Direction::South) :
				//	MakeRoom(map, rng, x, y + 1, GetRandomDirection(rng), Tile::UndiscoveredRoom);
				//	break;
				//case(Direction::East) :
				//	MakeRoom(map, rng, x + 1, y, GetRandomDirection(rng), Tile::UndiscoveredRoom);
				//	break;
				//case(Direction::West) :
				//	MakeRoom(map, rng, x - 1, y, GetRandomDirection(rng), Tile::UndiscoveredRoom);
				//	break;
				//}
			}
		}
	}
	//doe iets met description;
	return false;

}

bool MapGenerator::checkIfUnused(Map& map, int x, int y)
{
	if (map.IsXInBounds(x) && map.IsYInBounds(y))
	{
		Tile t = map.GetCell(x, y);
		if (t == Tile::Unused)
			return true;
		else
			return false;
	}
}

bool MapGenerator::MakeStairs(Map& map, RngT& rng, Tile tile)
{
	return false;

}

Direction MapGenerator::GetRandomDirection(RngT& rng)
{
	return Direction(std::uniform_int_distribution<int>(0, 3)(rng));
}

