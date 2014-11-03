#pragma once
#include "stdafx.h"
#include "Hero.h"
class Trap {

public:
	virtual string getName() = 0;
	virtual void hurt(Hero* hero) = 0;
};