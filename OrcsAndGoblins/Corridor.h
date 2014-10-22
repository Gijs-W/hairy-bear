#pragma once
#include "MapType.h"
class Corridor : public MapType
{
public:
	Corridor();
	Corridor(Tile tile);
	virtual ~Corridor();
	void setType(Tile type);
	Tile getType();
private:
	Tile type;
};

