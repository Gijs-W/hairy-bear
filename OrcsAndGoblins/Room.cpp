#include "stdafx.h"
#include "Room.h"

Room::Room()
{
	corridors = new std::vector<MapType*>();
	enemies = new std::vector<Enemy*>();
	items = new std::vector < Item* >;
	traps = new std::vector < Trap* > ;
	loadRoomDescriptions();
	generateRoomContents();
}

Room::Room(Tile type) : type(type)
{
	corridors = new std::vector<MapType*>();
	enemies = new std::vector<Enemy*>();
	items = new std::vector < Item* > ;
	traps = new std::vector < Trap* >;
	loadRoomDescriptions();
	loadEnemyDescriptions();
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
	for (auto item : *items) { 
		delete item;
	}
	delete items;

	//corridors get deleted in map
	//for (auto corridor : *corridors) {
	//	delete corridor;
	//}
	delete corridors;

	for (auto enemy : *enemies) {
		delete enemy;
	}
	delete enemies;

	for (auto trap : *traps) {
		delete trap;
	}
	delete traps;
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
			case(EnemyType::Orc) :
				enemy = new Orc((Map::currentLevel + 1));
				if (count > 1)
				{
					string desc = orc_multiple_description[rand() % 5];
					string desc1 = orc_multiple_enddescription[rand() % 3];
					description = orc_multiple_init[1] + desc + desc1;
				}
				else
				{
					string desc = orc_single_description[rand() % 5];
					string desc1 = orc_single_enddescription[rand() % 3];
					description = orc_single_init[1] + desc + desc1;
				}
				break;
			case(EnemyType::Rat) :
				enemy = new Rat((Map::currentLevel + 1));
				if (count > 1)
				{
					string desc = rat_multiple_description[rand() % 5];
					string desc1 = rat_multiple_enddescription[rand() % 3];
					description = rat_multiple_init[1] + desc + desc1;
				}
				else
				{
					string desc = rat_single_description[rand() % 5];
					string desc1 = rat_single_enddescription[rand() % 3];
					description = rat_single_init[1] + desc + desc1;
				}
				break;
			case(EnemyType::Goblin) :
				enemy = new Goblin((Map::currentLevel + 1));
				if (count > 1)
				{
					string desc = goblin_multiple_description[rand() % 5];
					string desc1 = goblin_multiple_enddescription[rand() % 3];
					description = goblin_multiple_init[1] + desc + desc1;
				}
				else
				{
					string desc = goblin_single_description[rand() % 5];
					string desc1 = goblin_single_enddescription[rand() % 3];
					description = goblin_single_init[1] + desc + desc1;
				}
				break;
			case(EnemyType::Skeleton) :
				enemy = new Skeleton((Map::currentLevel + 1));
				if (count > 1)
				{
					string desc = skeleton_multiple_description[rand() % 5];
					string desc1 = skeleton_multiple_enddescription[rand() % 3];
					description = skeleton_multiple_init[1] + desc + desc1;
				}
				else
				{
					string desc = skeleton_single_description[rand() % 5];
					string desc1 = skeleton_single_enddescription[rand() % 3];
					description = skeleton_single_init[1] + desc + desc1;
				}
				break;
			}
			enemies->push_back(enemy);
		}
	}

	int itemDice = rand() % 3;
	switch (itemDice) {
	case 0:
		items->push_back(new MagicHealthPotion);
		break;
	case 1:
		items->push_back(new CupOfTea);
		break;
	}

	int trapDice = rand() % 3;

	switch (trapDice) {
	case 0:
		traps->push_back(new BearTrap());
		break;
	case 1:
		traps->push_back(new Flames());
		break;
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

std::vector<Trap*>* Room::getTraps() {
	return traps;
}

void Room::dismantleTraps() {
	for (auto trap : *traps) {
		delete trap;
	}
	traps->clear();
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
	if (items->size() > 0) {
		for (auto &item : *items) {
			hero->addToInventory(item);
		}

		items->clear();
		return true;
	}

	return false;
}

std::vector<Item*>* Room::getItems() {
	return items;
}

std::string Room::getDescription() {

	std::string size;
	std::string filth;
	std::string contents;
	std::string lightning;

	size = room_size[m_size];
	filth = room_filth[m_filth];
	contents = room_furniture[m_furniture];
	lightning = room_lightning[m_lightning];


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
			description.append(enemydescription);
			description.append(".\n");
		}
	}
	return description;

}


string Room::room_size[3] = {};
string Room::room_filth[2] = {};
string Room::room_lightning[3] = {};
string Room::room_furniture[3] = {};

void Room::loadRoomDescriptions() {

	if (room_size[0].size() > 0) {
		// File is al een keer ingelezen, dus we kunnen nu al stoppen;
		return;
	}

	ifstream input_file("assets/room_size.txt");
	input_file >> room_size[RoomSize::Small] >> room_size[RoomSize::Medium] >> room_size[RoomSize::Large];

	ifstream input_file2("assets/room_filth.txt");
	input_file2 >> room_filth[RoomFilth::Clean] >> room_filth[RoomFilth::Dirty];

	ifstream input_file3("assets/room_lightning.txt");
	input_file3 >> room_lightning[RoomLighting::Torch] >> room_lightning[RoomLighting::Candle] >> room_lightning[RoomLighting::Fireplace];

	ifstream input_file4("assets/room_furniture.txt");
	input_file4 >> room_furniture[RoomFurniture::Empty] >> room_furniture[RoomFurniture::TableChair] >> room_furniture[RoomFurniture::Bed];


}

string Room::orc_multiple_init[1] = {};
string Room::orc_single_init[1] = {};
string Room::orc_multiple_description[5] = {};
string Room::orc_multiple_enddescription[3] = {};
string Room::orc_single_description[5] = {};
string Room::orc_single_enddescription[3] = {};

string Room::rat_multiple_init[1] = {};
string Room::rat_single_init[1] = {};
string Room::rat_multiple_description[5] = {};
string Room::rat_multiple_enddescription[3] = {};
string Room::rat_single_description[5] = {};
string Room::rat_single_enddescription[3] = {};

string Room::goblin_multiple_init[1] = {};
string Room::goblin_single_init[1] = {};
string Room::goblin_multiple_description[5] = {};
string Room::goblin_multiple_enddescription[3] = {};
string Room::goblin_single_description[5] = {};
string Room::goblin_single_enddescription[3] = {};

string Room::skeleton_multiple_init[1] = {};
string Room::skeleton_single_init[1] = {};
string Room::skeleton_multiple_description[5] = {};
string Room::skeleton_multiple_enddescription[3] = {};
string Room::skeleton_single_description[5] = {};
string Room::skeleton_single_enddescription[3] = {};

void Room::loadEnemyDescriptions() {

	if (orc_multiple_init[0].size() > 0) {
		// File is al een keer ingelezen, dus we kunnen nu al stoppen;
		return;
	}

	ifstream input_file("assets/orc_multiple.txt");
	input_file >> orc_multiple_init[1] >> orc_multiple_description[1] >> orc_multiple_description[2] >> orc_multiple_description[3] >> orc_multiple_description[4] >> orc_multiple_description[5] >> orc_multiple_enddescription[1] >> orc_multiple_enddescription[2] >> orc_multiple_enddescription[3];

	ifstream input_file1("assets/orc_single.txt");
	input_file1 >> orc_single_init[1] >> orc_single_description[1] >> orc_single_description[2] >> orc_single_description[3] >> orc_single_description[4] >> orc_single_description[5] >> orc_single_enddescription[1] >> orc_single_enddescription[2] >> orc_single_enddescription[3];

	ifstream input_file2("assets/rat_multiple.txt");
	input_file2 >> rat_multiple_init[1] >> rat_multiple_description[1] >> rat_multiple_description[2] >> rat_multiple_description[3] >> rat_multiple_description[4] >> rat_multiple_description[5] >> rat_multiple_enddescription[1] >> rat_multiple_enddescription[2] >> rat_multiple_enddescription[3];

	ifstream input_file3("assets/rat_single.txt");
	input_file3 >> rat_single_init[1] >> rat_single_description[1] >> rat_single_description[2] >> rat_single_description[3] >> rat_single_description[4] >> rat_single_description[5] >> rat_single_enddescription[1] >> rat_single_enddescription[2] >> rat_single_enddescription[3];

	ifstream input_file4("assets/goblin_multiple.txt");
	input_file4 >> goblin_multiple_init[1] >> goblin_multiple_description[1] >> goblin_multiple_description[2] >> goblin_multiple_description[3] >> goblin_multiple_description[4] >> goblin_multiple_description[5] >> goblin_multiple_enddescription[1] >> goblin_multiple_enddescription[2] >> goblin_multiple_enddescription[3];

	ifstream input_file5("assets/goblin_single.txt");
	input_file5 >> goblin_single_init[1] >> goblin_single_description[1] >> goblin_single_description[2] >> goblin_single_description[3] >> goblin_single_description[4] >> goblin_single_description[5] >> goblin_single_enddescription[1] >> goblin_single_enddescription[2] >> goblin_single_enddescription[3];

	ifstream input_file6("assets/skeleton_multiple.txt");
	input_file6 >> skeleton_multiple_init[1] >> skeleton_multiple_description[1] >> skeleton_multiple_description[2] >> skeleton_multiple_description[3] >> skeleton_multiple_description[4] >> skeleton_multiple_description[5] >> rat_multiple_enddescription[1] >> rat_multiple_enddescription[2] >> rat_multiple_enddescription[3];

	ifstream input_file7("assets/skeleton_single.txt");
	input_file7 >> skeleton_single_init[1] >> skeleton_single_description[1] >> skeleton_single_description[2] >> skeleton_single_description[3] >> skeleton_single_description[4] >> skeleton_single_description[5] >> skeleton_single_enddescription[1] >> skeleton_single_enddescription[2] >> skeleton_single_enddescription[3];
}