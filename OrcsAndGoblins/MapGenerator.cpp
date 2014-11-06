#include "stdafx.h"
#include "MapGenerator.h"



MapGenerator::~MapGenerator()
{
	for (int i = 0; i < listMap->size(); i++)
	{
		delete listMap->at(i);
	}
	delete listMap;
}

void MapGenerator::clearListMap()
{
	for (int i = 0; i < listMap->size(); i++)
	{
		delete listMap->at(i);
	}
}

std::vector<Map*>* MapGenerator::generate()
{
	clearListMap();
	auto rng = RngT(rngSeed);
	Map* map = new Map(x, y, 1,Tile::Unused);
	MakeDungeon(*map, rng, x/2, y/2); //x/2 + y/2 for very first level
	return listMap;
}

bool MapGenerator::MakeDungeon(Map& map, RngT& rng, int x, int y)
{
	if (levels == 1)
	{
		MakeFirstRoomInDungeon(map, rng, x, y, Tile::Room);
		map.checkEndRooms();
		MapType* c = getRandomFromCorridor(map, rng);
		if (c != nullptr)
		{
			if (c->getType() != Tile::StairsDown || c->getType() != Tile::StairsUp || c->getType() != Tile::UndiscoveredStairsDown  || c->getType() != Tile::UndiscoveredStairsUp)
			{
				MakeStairs(map, rng, c->getX() , c->getY(), 2, Tile::UndiscoveredStairsDown);
				xStairs = c->getX();
				yStairs = c->getY();
			}
		}
		Map* m = &map;
		listMap->push_back(m);
	}
	if (levels <= maxLevels)
	{
		int nextLevel = levels++;
		Map* nextMap = new Map(x * 2, y * 2, nextLevel, Tile::Unused);
		Map next = *nextMap;
		MapType *stairs = MakeStairs(next, rng, xStairs, yStairs, nextLevel - 2, Tile::StairsUp); // case : level 1 = stairs down (to level 2), level 2 = stairs up(to level 1 = nextLevel - 2), stairs down
		MakeRoom(next, rng, xStairs, yStairs, GetRandomDirection(rng), Tile::UndiscoveredRoom, stairs, nextLevel);
		next.checkEndRooms();

		MapType* c = getRandomFromCorridor(next, rng);
		if (levels != maxLevels )
		if (c != nullptr)
		{
			if (c->getType() != Tile::StairsDown || c->getType() != Tile::StairsUp)
			{
				MakeStairs(next, rng, c->getX(), c->getY(), nextLevel, Tile::StairsDown);
				xStairs = c->getX();
				yStairs = c->getY();
			}
		}
		Map* m = &next;
		listMap->push_back(m);

		MakeDungeon(*m, rng, x, y);
	}
	return false;
}

MapType* MapGenerator::getRandomFromCorridor(Map& map, RngT& rng)
{
	return map.getEndRoom(rng);
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
			MakeRoom(map, rng, x, y, GetRandomDirection(rng), Tile::UndiscoveredRoom, room, 1);
		}
	}

	return false;
}

MapType* MapGenerator::MakeStairs(Map& map, RngT& rng, int x, int y, int toLevel, Tile type)
{
	map.SetCell(x, y, type);
	MapType* m = map.makeStairs(x, y, toLevel, type);
	return m;
}

bool MapGenerator::MakeRoom(Map& map, RngT& rng, int x, int y, Direction direction, Tile type, MapType* sourceRoom, int level)
{
	int maxTries = 4;
	if (level == 1 || level == 2)
		maxTries = 3; // magic number
	else
		maxTries = 4;

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
						MakeRoom(map, rng, x, y - 2, GetRandomDirection(rng), Tile::UndiscoveredRoom, room, level);
					}
					break;
				case(Direction::South) :
					if (checkIfUnused(map, x, y + 2))
					{
						map.SetCell(x, y + 2, Tile::UndiscoveredRoom);
						MapType *room = map.makeRoom(type, x, y + 2);
						MapType *corridor = map.makeCorridor(x, y + 1, sourceRoom, room, direction);
						MakeRoom(map, rng, x, y + 2, GetRandomDirection(rng), Tile::UndiscoveredRoom, room, level);
					}
					break;
					case(Direction::East) :
						if (checkIfUnused(map, x + 2, y))
						{
							map.SetCell(x + 2, y, Tile::UndiscoveredRoom);
							MapType *room = map.makeRoom(type, x + 2, y);
							MapType *corridor = map.makeCorridor(x + 1, y, sourceRoom, room, direction);
							MakeRoom(map, rng, x + 2, y, GetRandomDirection(rng), Tile::UndiscoveredRoom, room, level);
						}
						break;
					case(Direction::West) :
						if (checkIfUnused(map, x - 2, y))
						{
							map.SetCell(x - 2, y, Tile::UndiscoveredRoom);
							MapType *room = map.makeRoom(type, x - 2, y);
							MapType *corridor = map.makeCorridor(x - 1, y, sourceRoom, room, direction);
							MakeRoom(map, rng, x - 2, y, GetRandomDirection(rng), Tile::UndiscoveredRoom, room, level);
						}
						break;
					}
				
			}
			//else
				//return false;
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

Direction MapGenerator::GetRandomDirection(RngT& rng)
{
	return Direction(std::uniform_int_distribution<int>(0, 3)(rng));
}

