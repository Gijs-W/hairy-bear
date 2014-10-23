#pragma once
#include "MapType.h"
class Stairs : public MapType
{
public:
	Stairs();
	virtual ~Stairs();
	Stairs(int to, int from);
	Tile getType();
	void setType(Tile type);
	int getToLevel();
	int getFromLevel();
private:
	int toLevel;
	int fromLevel;
	Tile type;
};

