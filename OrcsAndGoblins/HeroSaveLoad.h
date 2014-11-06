#pragma once
#include "Hero.h"
#include <fstream>
class HeroSaveLoad {
private:
	Hero* m_hero;
	
public:
	HeroSaveLoad(Hero* hero);
	void save();
	void load();
	bool saveFileExists();
};