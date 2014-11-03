#include "stdafx.h"
#include "Item.h"

string Item::generateRandomPrefix() {
	string retval = "";


	int superDice = rand() % 2;
	
	if (superDice <= 1) {
		retval.append("super ");
	}
	
	int sizeDice = rand() % 3;

	switch (sizeDice) {
	case 0:
		retval.append("groot ");
		break;
	case 1:
		retval.append("medium");
		break;
	case 2:
		retval.append("klein ");
		break;
	}

	int dustDice = rand() % 2;

	if (dustDice <= 1) {
		retval.append("en stoffig ");
	}

	int touchOfGodDice = rand() % 2;

	if (touchOfGodDice <= 1) {
		retval.append("door een god gemaakt ");
	}

	int hairyDice = rand() % 2;

	if (hairyDice <= 1) {
		retval.append("harig ");
	}


		
	return retval;
}