#pragma once

enum class Tile {
	Room,
	UndiscoveredRoom,
	RoomCorridor,
	UndiscoveredRoomCorridor,
	CorridorVertical,
	CorridorHorizontal,
	UndiscoveredCorridorVertical,
	UndiscoveredCorridorHorizontal,
	Unused,
	StairsUp,
	StairsDown,
	UndiscoveredStairsUp,
	UndiscoveredStairsDown
};
class MapType
{
public:
	MapType();
	virtual ~MapType();
	virtual Tile getType();
	virtual void setType(Tile type);
	virtual void setVisited(bool visit);
	virtual bool getVisited();
	virtual int getX();
	virtual int getY();
	virtual void setX(int x);
	virtual void setY(int y);
private :
	Tile type;
	bool visited;
	int x, y;
};

