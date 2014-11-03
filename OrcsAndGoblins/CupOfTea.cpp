#include "stdafx.h"
#include "CupOfTea.h"
string CupOfTea::getName() {
	return generateRandomPrefix().append("kopje thee");
}

void CupOfTea::use(Hero* hero) {
	hero->setAlertnessXP(hero->getAlertnessXP() + 10);
}