#include "stdafx.h"
#include "Map.h"
#include <iostream>
#include <string>
#include <random>
#include <cassert>
int Map::currentLevel;

Map::Map() : xSize(0), ySize(0), data()
{
}

Map::Map(int x, int y, int level, Tile value) : xSize(x), ySize(y), data(x * y, value), level(level)
{
	for (int i = 0; i < ySize; i++)
	{
		for (int j = 0; j < xSize; j++)
		{
			makeUnused(i, j);
		}
	}
}

Map::~Map()
{
	//for (int i = 0; i < allEntities->size(); i++)
	//{
	//	delete allEntities->at(i);
	//}
	//delete allEntities;

	//cant do this yet
	/*for (int i = 0; i < rooms->size(); i++)
	{
	delete rooms->at(i);
	}
	delete rooms;

	for (int i = 0; i < stairs->size(); i++)
	{
	delete stairs->at(i);
	}
	delete stairs;

	for (int i = 0; i < unuseds->size(); i++)
	{
	delete unuseds->at(i);
	}
	delete unuseds;

	for (int i = 0; i < corridors->size(); i++)
	{
	delete corridors->at(i);
	}
	delete corridors;*/

}

int Map::getXsize()
{
	return xSize;
}

int Map::getYsize()
{
	return ySize;
}

void Map::SetCell(int x, int y, Tile type)
{
	assert(IsXInBounds(x));
	assert(IsYInBounds(y));

	data[x + xSize * y] = type;
}

Tile Map::GetCell(int x, int y) const
{
	assert(IsXInBounds(x));
	assert(IsYInBounds(y));

	return data[x + xSize * y];
}

bool Map::IsXInBounds(int x) const
{
	return x >= 0 && x < xSize;
}

bool Map::IsYInBounds(int y) const
{
	return y >= 0 && y < ySize;
}

bool Map::IsAdjacent(int x, int y, Tile tile)
{
	assert(IsXInBounds(x - 1) && IsXInBounds(x + 1));
	assert(IsYInBounds(y - 1) && IsYInBounds(y + 1));

	return
		GetCell(x - 1, y) == tile || GetCell(x + 1, y) == tile ||
		GetCell(x, y - 1) == tile || GetCell(x, y + 1) == tile;
}

bool Map::checkIfEntityExists(int x, int y)
{
	bool value = false;
	if (allEntities->size() == 0)
		return value;
	else
	{
		for (int i = 0; i < allEntities->size(); i++)
		{
			MapType* entity = allEntities->at(i);
			if (entity->getX() == x && entity->getY() == y)
			{
				value = true;
			}
		}
	}

	return value;
}

void Map::deleteFromEntities(int x, int y)
{
	for (int i = 0; i < allEntities->size(); i++)
	{
		MapType* entity = allEntities->at(i);
		if (entity->getX() == x && entity->getY() == y)
		{
			allEntities->erase(allEntities->begin() + i);
		}
	}
}

MapType* Map::getMapType(int x, int y) {
	MapType* type = nullptr;
	for (int i = 0; i < allEntities->size(); i++)
	{
		MapType* entity = allEntities->at(i);
		if (entity->getX() == x && entity->getY() == y)
		{
			type = entity;
			break;
		}
	}

	return type;
}

int Map::getLevel()
{
	return level;
}

MapType* Map::makeRoom(Tile tile, int x, int y)
{
	if (checkIfEntityExists(x, y))
		deleteFromEntities(x, y);

	MapType *room = new Room(tile);
	room->setX(x);
	room->setY(y);
	rooms->push_back(room);

	allEntities->push_back(room);
	return room;
}

MapType* Map::makeUnused(int x, int y)
{
	MapType *unused = new Unused();
	unused->setX(x);
	unused->setY(y);
	unuseds->push_back(unused);
	allEntities->push_back(unused);
	return unused;
}

MapType* Map::makeStairs(int x, int y, int to, Tile type)
{
	if (checkIfEntityExists(x, y))
		deleteFromEntities(x, y);
	MapType *stair = new Stairs(level, to);
	stair->setX(x);
	stair->setY(y);
	stair->setType(type);
	stairs->push_back(stair);

	allEntities->push_back(stair);
	return stair;
}


void Map::checkEndRooms()
{
	for (int i = 0; i < rooms->size(); i++)
	{
		MapType *r = rooms->at(i);

		Room* room = dynamic_cast<Room*>(r);
		if (room)
		{
			if (room->getCorridors()->size() == 1)
			{
				room->setType(Tile::UndiscoveredRoomCorridor);
				roomCorridors->push_back(room);
			}
		}
	}
}

Hero* Map::getHero()
{
	return hero;
}

void Map::setHero(Hero* hero)
{
	this->hero = hero;
}

MapType* Map::getEndRoom(RngT& rng)
{
	if (roomCorridors->size() == 0)
	{
		return nullptr;
	}
	MapType* rValue = nullptr;

	int rand = std::uniform_int_distribution<int>(0, roomCorridors->size() - 1)(rng);

	MapType *r = roomCorridors->at(rand);

	rValue = r;
	return rValue;
}

MapType* Map::makeCorridor(int x, int y, MapType* sourceRoom, MapType* targetRoom, Direction direction)
{
	if (checkIfEntityExists(x,y))
		deleteFromEntities(x, y);

	MapType *corridor = new Corridor(sourceRoom, targetRoom);
	corridor->setX(x);
	corridor->setY(y);

	//dynamic casting :(
	Room* r1 = dynamic_cast<Room*>(sourceRoom);
	if (r1)
		r1->addCorridor(corridor);

	Room* r2 = dynamic_cast<Room*>(targetRoom);
	if (r2)
		r2->addCorridor(corridor);


	switch (direction)
	{
	case(Direction::North) :
		corridor->setType(Tile::UndiscoveredCorridorVertical);
		break;
	case(Direction::South) :
		corridor->setType(Tile::UndiscoveredCorridorVertical);
		break;
	case(Direction::East) :
		corridor->setType(Tile::UndiscoveredCorridorHorizontal);
		break;
	case(Direction::West) :
		corridor->setType(Tile::UndiscoveredCorridorHorizontal);
		break;
	}

	corridors->push_back(corridor);

	allEntities->push_back(corridor);

	return corridor;
}


void Map::Print() const
{
	for (int j = 0; j < ySize; j++)
	{
		for (int i = 0; i < xSize; i++)
		{
			for (int k = 0; k < allEntities->size(); k++)
			{
				MapType *r = allEntities->at(k);
				if (r->getX() == i && r->getY() == j)
				{
					if (hero->getPosX() == i && hero->getPosY() == j)
					{
						printf("@");
					}
					else
					{
						//if (i == 10 && j == 9)
						//{
						//	printf("north");
						//}
						//else if (i == 10 && j == 11)
						//{
						//	printf("south");
						//}
						//else if (i == 11 && j == 10)
						//{
						//	printf("east");
						//}
						//else if (i == 9 && j == 10)
						//{
						//	printf("west");
						//}
						Tile t = r->getType();
						switch (t)
						{
						case(Tile::CorridorVertical) :
							printf("|");
							break;
						case(Tile::CorridorHorizontal) :
							printf("-");
							break;
						case(Tile::Unused) :
							printf(".");
							break;
						case(Tile::Room) :
							printf("0");
							break;
						case(Tile::UndiscoveredRoom) :
							printf(".");
							break;
						case(Tile::RoomCorridor) :
							printf("x");
							break;
						case(Tile::UndiscoveredRoomCorridor) :
							printf(".");
							break;
						case(Tile::StairsDown) :
							printf("D");
							break;
						case(Tile::StairsUp) :
							printf("U");
							break;
						case(Tile::UndiscoveredCorridorHorizontal) :
							printf(".");
							break;
						case(Tile::UndiscoveredCorridorVertical) :
							printf(".");
							break;
						case(Tile::UndiscoveredStairsDown) :
							printf(".");
							break;
						case(Tile::UndiscoveredStairsUp) :
							printf(".");
							break;
						}
					}
					printf(" ");
				}
			}
			//Tile t = GetCell(i, j);
		}
		std::cout << std::endl;
	}
}

int xSize, ySize;

std::vector<Tile> data;
