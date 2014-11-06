#pragma once
#include "EngineState.h"
#include "Engine.h"
class DieState : public EngineState
{
public:
	DieState();
	void handle(Engine* context);
	virtual ~DieState();
};

