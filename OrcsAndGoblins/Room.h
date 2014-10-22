#pragma once
#include "MapType.h"

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
private:
	bool visited;
	Tile type;
	std::string description;
	std::vector<MapType*>* corridors;
};

