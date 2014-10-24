#pragma once

#include "Engine.h"
class Hero;
class Item {
public:

	virtual string getName() = 0;
	virtual void use(Hero* hero) =0;
};