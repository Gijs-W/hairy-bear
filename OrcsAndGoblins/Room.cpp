#include "stdafx.h"
#include "Room.h"

Room::Room()
{
	corridors = new std::vector<MapType*>();
	generateRoomContents();
}

Room::Room(Tile type) : type(type)
{
	corridors = new std::vector<MapType*>();
	generateRoomContents();
}


Room::~Room()
{
	//for (int i = corridors->size(); i >= 0; i--)
	//{
	//	MapType *c = corridors->at(i);
	//	delete c;
	//}
	//delete corridors;
}

void Room::generateRoomContents() {
	m_size = RoomSize(rand() % 3);
	m_lightning = RoomLighting(rand() % 3);
	m_furniture = RoomFurniture(rand() % 3);
	m_filth = RoomFilth(rand() % 2);

}

void Room::addCorridor(MapType* corridor)
{
	corridors->push_back(corridor);
}

std::vector<MapType*>* Room::getCorridors()
{
	return corridors;
}

void Room::setVisited(bool visit)
{
	visited = visit;
	if (visited)
	{
		setType(Tile::Room);
	}
}

bool Room::getVisited()
{
	return visited;
}

void Room::setType(Tile tile)
{
	type = tile;
}

Tile Room::getType()
{
	return type;
}