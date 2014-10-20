#pragma once
#include "stdafx.h"
#include "InputManager.h"
class Engine;
class EngineState {

public:
	virtual void handle(Engine* context) = 0;
	virtual ~EngineState(){}
};