#include "stdafx.h"
#include "MagicHealthPotion.h"
string MagicHealthPotion::getName() {
	return generateRandomPrefix().append("magisch levensdrankje");
}

void MagicHealthPotion::use(Hero* hero) {
	hero->regenerateHealth(3);
}