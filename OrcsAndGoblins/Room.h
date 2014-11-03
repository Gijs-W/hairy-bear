#pragma once
#include "MapType.h"
#include "Hero.h"
#include "Enemy.h"
#include "Orc.h"
#include "Goblin.h"
#include "Rat.h"
#include "Skeleton.h"
#include "Map.h"
#include "MagicHealthPotion.h"
#include "CupOfTea.h"
#include "Trap.h"
#include "Flames.h"
#include "BearTrap.h"
#include <fstream>

enum RoomSize {
	Small,
	Medium,
	Large
};
enum RoomFilth {
	Clean,
	Dirty
};
enum RoomFurniture {
	TableChair,
	Bed,
	Empty
};

enum RoomLighting {
	Candle,
	Torch,
	Fireplace

};

class Room : public MapType
{
public:
	Room();
	Room(Tile type);
	virtual ~Room();

	std::string getDescription();
	std::vector<MapType*>* getCorridors();
	void addCorridor(MapType* corridor);
	void setVisited(bool visit);
	bool getVisited();
	void setType(Tile tile);
	Tile getType();
	void generateRoomContents();
	bool lookForItems(Hero* hero);
	std::vector<Enemy*>* getEnemies();
	std::vector<Item*>* getItems();
	std::vector<Trap*>* getTraps();
	void dismantleTraps();
private:
	RoomSize m_size;
	RoomFilth m_filth;
	RoomFurniture m_furniture;
	RoomLighting m_lightning;
	bool visited;
	Tile type;
	std::string description;
	std::vector<MapType*>* corridors;
	std::vector<Enemy*>* enemies;
	std::vector<Item*>* items;
	std::vector<Trap*>* traps;
	int chanceEnemies = 75;
	int numberOfEnemies;
	std::string enemydescription;

	//orc
	static string orc_multiple_init[1];
	static string orc_single_init[1];
	static string orc_multiple_description[5];
	static string orc_multiple_enddescription[3];
	static string orc_single_description[5];
	static string orc_single_enddescription[3];

	//rat
	static string rat_multiple_init[1];
	static string rat_single_init[1];
	static string rat_multiple_description[5];
	static string rat_multiple_enddescription[3];
	static string rat_single_description[5];
	static string rat_single_enddescription[3];

	//goblin
	static string goblin_multiple_init[1];
	static string goblin_single_init[1];
	static string goblin_multiple_description[5];
	static string goblin_multiple_enddescription[3];
	static string goblin_single_description[5];
	static string goblin_single_enddescription[3];

	//skeleton
	static string skeleton_multiple_init[1];
	static string skeleton_single_init[1];
	static string skeleton_multiple_description[5];
	static string skeleton_multiple_enddescription[3];
	static string skeleton_single_description[5];
	static string skeleton_single_enddescription[3];

	static void loadEnemyDescriptions();

	//rooms
	static string room_size[3];
	static string room_lightning[3];
	static string room_furniture[3];
	static string room_filth[2];
	static void loadRoomDescriptions();
	
};

