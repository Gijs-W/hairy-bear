#pragma once
#include "Trap.h"

class Flames : public Trap {

private:
	const int damage = 5;
public:
	string getName();
	void hurt(Hero* hero);
};