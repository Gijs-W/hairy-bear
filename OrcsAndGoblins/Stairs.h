#pragma once
#include "MapType.h"
class Stairs : public MapType
{
public:
	Stairs();
	virtual ~Stairs();
	Stairs(int from, int to);
	Tile getType();
	void setVisited(bool visit);
	bool getVisited();
	void setType(Tile type);
	int getToLevel();
	int getFromLevel();
private:
	int toLevel;
	int fromLevel;
	Tile type;
	bool visited;
};

