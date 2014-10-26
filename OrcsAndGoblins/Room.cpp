#include "stdafx.h"
#include "Room.h"

Room::Room()
{
	corridors = new std::vector<MapType*>();
	enemies = new std::vector<Enemy*>();
	generateRoomContents();
}

Room::Room(Tile type) : type(type)
{
	corridors = new std::vector<MapType*>();
	enemies = new std::vector<Enemy*>();
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

	EnemyType et = EnemyType(rand() % 4);

	int count = rand() % (2 * (Map::currentLevel + 1));
	numberOfEnemies = count;
	int randenemies = rand() % 100;
	if (randenemies < chanceEnemies)
	{
		for (int i = 0; i < count; i++)
		{
			Enemy* enemy = nullptr;
			switch (et)
			{
			case(EnemyType::Orc):
				enemy = new Orc((Map::currentLevel + 1));
				break;
			case(EnemyType::Rat) :
				enemy = new Rat((Map::currentLevel + 1));
				break;
			case(EnemyType::Goblin) :
				enemy = new Goblin((Map::currentLevel + 1));
				break;
			case(EnemyType::Skeleton) :
				enemy = new Skeleton((Map::currentLevel + 1));
				break;
			}
			enemies->push_back(enemy);
		}
	}
}

std::vector<Enemy*>* Room::getEnemies()
{
	return enemies;
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

bool Room::lookForItems(Hero* hero) {
	//if room->containtsItems ofzo return true
	return false;
}


std::string Room::getDescription() {

	std::string size;
	std::string filth;
	std::string contents;
	std::string lightning;

	switch (m_size) {
	case Small:
		size = "kleine";
		break;
	case Medium:
		size = "normale";
		break;
	case Large:
		size = "grote";
		break;
	}

	switch (m_filth) {
	case Dirty:
		filth = "vieze";
		break;
	case Clean:
		filth = "schone";
		break;
	}

	switch (m_furniture) {
	case Empty:
		contents = "niets";
		break;
	case TableChair:
		contents = "een tafel met vier stoelen";
		break;
	case Bed:
		contents = "een bed";
		break;
	}

	switch (m_lightning) {
	case Torch:
		lightning = "fakkel";
		break;
	case Candle:
		lightning = "kaars";
		break;
	case Fireplace:
		lightning = "haardvuur";
		break;
	}

///	char buffer[500];

//	sprintf_s(buffer, 500, "Je staat in een %s, %s kamer.\nIn de kamer staat %s\nDe kamer wordt verlicht door een %s\n",
//		size, filth, contents, lightning
//		);

	std::string description = "Je staat in een ";
	description.append(size);
	description.append(", ");
	description.append(filth);
	description.append(" kamer.\nIn de kamer staat ");
	description.append(contents);
	description.append(".\nDe kamer wordt verlicht door een ");
	description.append(lightning);
	description.append(".\n");
	if (enemies->size() != 0)
	{
		for (int i = 0; i < enemies->size(); i++)
		{
			if (enemies->size() > 1)
			{
				description.append("In deze kamer staan ");
			}
			else
			{
				description.append("In deze kamer staat ");
			}
			description.append(std::to_string(numberOfEnemies) + " ");
			description.append(enemies->at(i)->getName());
			if (enemies->size() > 1)
			{
				switch (enemies->at(i)->getType())
				{
				case(EnemyType::Goblin) :
					description.append("s");
				case(EnemyType::Orc) :
					description.append("en");
				case(EnemyType::Skeleton) :
					description.append("ten");
				case(EnemyType::Rat) :
					description.append("ten");
				}
				description.append(enemies->at(i)->getMultipleDescription());
			}
			else
			{
				description.append(enemies->at(i)->getDescription());
			}
			description.append(".\n");
		}
	}
	return description;

}