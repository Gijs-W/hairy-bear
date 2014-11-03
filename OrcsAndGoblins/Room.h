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
#include "FlamesOfUdun.h"
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



	static string room_size[3];
	static string room_lightning[3];
	static string room_furniture[3];
	static string room_filth[2];
	static void loadRoomDescriptions();
	
};

