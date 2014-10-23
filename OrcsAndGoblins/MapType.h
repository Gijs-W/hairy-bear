#pragma once

enum class Tile {
	Room,
	UndiscoveredRoom,
	RoomCorridor,
	UndiscoveredRoomCorridor,
	CorridorVertical,
	CorridorHorizontal,
	Unused,
	StairsUp,
	StairsDown
};
class MapType
{
public:
	MapType();
	virtual ~MapType();
	virtual Tile getType();
	virtual void setType(Tile type);
	virtual int getX();
	virtual int getY();
	virtual void setX(int x);
	virtual void setY(int y);
private :
	Tile type;
	int x, y;
};

