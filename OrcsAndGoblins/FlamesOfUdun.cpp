#include "FlamesOfUdun.h"

string FlamesOfUdun::getName() {
	return "Vuur";
}

void FlamesOfUdun::hurt(Hero* hero) {
	hero->setHealth(hero->getHealth() - damage);
}