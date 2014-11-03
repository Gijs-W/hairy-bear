#pragma once
#include "EngineState.h"
#include "Stairs.h"
#include "Engine.h"
class StairsViewState : public EngineState
{
public:
	StairsViewState(Stairs* stairs);
	virtual ~StairsViewState();
	void handle(Engine* context);
private: 
	Stairs* thisStairs;
	bool isWalkableTile(MapType* maptype);
	void handleHeroPosition(Hero* hero, Engine* context);
};

