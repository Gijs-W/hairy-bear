#pragma once

#include "Engine.h"
#include "Hero.h"
class Item {
public:
	virtual string getName() = 0;
	virtual void use(Hero* hero) =0;
};