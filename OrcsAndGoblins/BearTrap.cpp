#include "BearTrap.h"

string BearTrap::getName() {
	return "Beren Val";
}

void BearTrap::hurt(Hero* hero) {
	hero->setHealth(hero->getHealth() - damage);
}