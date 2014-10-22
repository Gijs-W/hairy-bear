#pragma once
#include "MapType.h"
class Unused : public MapType
{
public:
	Unused();
	virtual ~Unused();
	Tile getType();
};

