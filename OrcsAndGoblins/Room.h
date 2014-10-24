#pragma once
#include "MapType.h"
#include "Hero.h"
#include "Enemy.h"
#include "Orc.h"

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
	int chanceEnemies = 100;
	
};

