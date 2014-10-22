#pragma once
#include "MapType.h"
class Corridor : public MapType
{
public:
	Corridor();
	Corridor(MapType* source, MapType* target);
	virtual ~Corridor();
	void setType(Tile type);
	Tile getType();
private:
	Tile type;
	MapType* source;
	MapType* target;
};

