#pragma once
#include "Trap.h"

class BearTrap : public Trap {
private:
	const int damage = 2;
public:
	string getName();
	void hurt(Hero* hero);
};