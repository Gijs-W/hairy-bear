#pragma once
#include "stdafx.h"
#include "Hero.h"

class Hero;
class Item {
public:

	virtual string getName() = 0;
	virtual void use(Hero* hero) =0;
};