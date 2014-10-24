#include "Item.h"
class MagicHealthPotion : public Item {
public:
	string getName();
	void use(Hero* hero);
};