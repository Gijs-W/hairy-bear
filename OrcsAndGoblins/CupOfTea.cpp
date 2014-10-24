#include "stdafx.h"
#include "CupOfTea.h"
string CupOfTea::getName() {
	return "kopje thee";
}

void CupOfTea::use(Hero* hero) {
	hero->setAlertnessXP(hero->getAlertnessXP() + 10);
}