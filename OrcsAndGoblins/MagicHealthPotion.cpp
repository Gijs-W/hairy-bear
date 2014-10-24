#include "MagicHealthPotion.h"
string MagicHealthPotion::getName() {
	return "magisch levensdrankje";
}

void MagicHealthPotion::use(Hero* hero) {
	hero->regenerateHealth();
	hero->regenerateHealth();
	hero->regenerateHealth();
	hero->regenerateHealth();
}