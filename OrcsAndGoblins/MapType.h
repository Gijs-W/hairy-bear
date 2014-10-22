#pragma once

enum class Tile {
	Room,
	UndiscoveredRoom,
	RoomCorridor,
	CorridorVertical,
	CorridorHorizontal,
	Unused,
};
class MapType
{
public:
	MapType();
	virtual ~MapType();
	virtual Tile getType();
private :
	Tile type;
};

