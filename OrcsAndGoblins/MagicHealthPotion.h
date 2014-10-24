#include "Item.h"
class MagicHealthPotion : Item {
public:
	string getName();
	void use(Hero* hero);
};