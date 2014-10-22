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
	virtual int getX();
	virtual int getY();
	virtual void setX(int x);
	virtual void setY(int y);
private :
	Tile type;
	int x, y;
};

