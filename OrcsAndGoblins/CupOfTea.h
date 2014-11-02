#pragma once
#include "Item.h"
class CupOfTea : public Item {
public:

	string getName();
	void use(Hero* hero);
};