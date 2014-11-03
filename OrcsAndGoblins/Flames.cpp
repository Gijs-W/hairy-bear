#include "stdafx.h"
#include "Flames.h"

string Flames::getName() {
	return "Vuur";
}

void Flames::hurt(Hero* hero) {
	hero->setHealth(hero->getHealth() - damage);
}