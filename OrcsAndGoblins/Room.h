#pragma once
#include "MapType.h"

class Room : public MapType
{
public:
	Room();
	virtual ~Room();

	std::string getDescription();
	std::vector<MapType*>* getCorridors();
	void addCorridor(MapType* corridor);
	void setVisited(bool visit);
	bool getVisited();
private:
	bool visited;
	Tile type;
	std::string description;
	std::vector<MapType*>* corridors;
	void setType(Tile tile);
};

