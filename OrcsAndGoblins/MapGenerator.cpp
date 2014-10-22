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
	MakeFirstRoomInDungeon(map, rng, x / 2, y / 2, Tile::Room);
	map.checkEndRooms();
	//MakeRoom(map, rng, x / 2, y / 2, GetRandomDirection(rng), Tile::Room); //midden in de map een kamer maken
	return false;
}

bool MapGenerator::MakeCorridor(Map& map, RngT& rng, int x, int y, Direction direction)
{
	if (map.IsXInBounds(x) && map.IsYInBounds(y))
	{
		switch (direction)
		{
		case(Direction::North) :
			if (map.IsYInBounds(y - 1) && map.IsXInBounds(x))
			{
				map.SetCell(x, y, Tile::CorridorVertical);
			}
			break;
		case(Direction::South) :
			if (map.IsYInBounds(y + 1) && map.IsXInBounds(x))
			{
				map.SetCell(x, y, Tile::CorridorVertical);
			}
			break;
		case(Direction::East) :
			if (map.IsXInBounds(x + 1) && map.IsYInBounds(y))
			{
				map.SetCell(x, y, Tile::CorridorHorizontal);
			}
			break;
		case(Direction::West) :
			if (map.IsXInBounds(x - 1) && map.IsYInBounds(y))
			{
				map.SetCell(x, y, Tile::CorridorHorizontal);
			}
			break;
		}
	}
	return false;
}

bool MapGenerator::MakeFirstRoomInDungeon(Map& map, RngT& rng, int x, int y, Tile type)
{
	int maxTries = 4;

	if (map.IsXInBounds(x) && map.IsYInBounds(y))
	{
		MapType *room = map.makeRoom(type, x, y);
		for (int i = 1; i < maxTries; i++)
		{
			map.SetCell(x, y, Tile::Room);
			MakeRoom(map, rng, x, y, GetRandomDirection(rng), Tile::UndiscoveredRoom, room);
		}
	}

	return false;
}

bool MapGenerator::MakeRoom(Map& map, RngT& rng, int x, int y, Direction direction, Tile type, MapType* sourceRoom)
{
	int maxTries = 4; // magic number

	if (map.IsXInBounds(x) && map.IsYInBounds(y))
	{
		for (int i = 1; i < maxTries; i++)
		{
			int rand = std::uniform_int_distribution<int>(0, chanceRoom + chanceCorridor)(rng);

			if (chanceRoom > rand)
			{
				Direction direction = GetRandomDirection(rng);
				switch (direction)
				{
				case(Direction::North) :
					if (checkIfUnused(map, x, y - 2))
					{
						map.SetCell(x, y -2 , Tile::UndiscoveredRoom);
						MapType *room = map.makeRoom(type, x, y - 2);
						MapType *corridor = map.makeCorridor(x, y - 1, sourceRoom, room, direction);
						MakeRoom(map, rng, x, y - 2, GetRandomDirection(rng), Tile::UndiscoveredRoom, room);
					}
					break;
				case(Direction::South) :
					if (checkIfUnused(map, x, y + 2))
					{
						map.SetCell(x, y + 2, Tile::UndiscoveredRoom);
						MapType *room = map.makeRoom(type, x, y + 2);
						MapType *corridor = map.makeCorridor(x, y + 1, sourceRoom, room, direction);
						MakeRoom(map, rng, x, y + 2, GetRandomDirection(rng), Tile::UndiscoveredRoom, room);
					}
					break;
					case(Direction::East) :
						if (checkIfUnused(map, x + 2, y))
						{
							map.SetCell(x + 2, y, Tile::UndiscoveredRoom);
							MapType *room = map.makeRoom(type, x + 2, y);
							MapType *corridor = map.makeCorridor(x + 1, y, sourceRoom, room, direction);
							MakeRoom(map, rng, x + 2, y, GetRandomDirection(rng), Tile::UndiscoveredRoom, room);
						}
						break;
					case(Direction::West) :
						if (checkIfUnused(map, x - 2, y))
						{
							map.SetCell(x - 2, y, Tile::UndiscoveredRoom);
							MapType *room = map.makeRoom(type, x - 2, y);
							MapType *corridor = map.makeCorridor(x - 1, y, sourceRoom, room, direction);
							MakeRoom(map, rng, x - 2, y, GetRandomDirection(rng), Tile::UndiscoveredRoom, room);
						}
						break;
					}
				
			}
			//else
			//	return false;
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

