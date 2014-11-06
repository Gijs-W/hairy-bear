#include "stdafx.h"
#include "HeroSaveLoad.h"
HeroSaveLoad::HeroSaveLoad(Hero* hero) {
	m_hero = hero;
}

void HeroSaveLoad::save() {
	ofstream output("assets/hero.txt");
	output << m_hero->getName() << std::endl;
	output << m_hero->getLevel() << std::endl;
	output << m_hero->getHealth() << std::endl;
	output << m_hero->getXP() << std::endl;
	output << m_hero->getAttackXP() << std::endl;
	output << m_hero->getDefenceXP() << std::endl;
	output << m_hero->getAlertnessXP() << std::endl;
}

void HeroSaveLoad::load() {

	ifstream input("assets/hero.txt");
	string name;
	int level;
	int health;
	int XP;
	int attackXP;
	int defenceXP;
	int alertnessXP;


	input >> name >> health >> XP >> attackXP >> defenceXP >> alertnessXP;

	m_hero->setName(name);
	m_hero->setHealth(health);
	m_hero->setXP(XP);
	m_hero->setAttackXP(attackXP);
	m_hero->setDefenceXP(defenceXP);
	m_hero->setAlertnessXP(alertnessXP);
}
bool HeroSaveLoad::saveFileExists()
{
	FILE * file;

	if (fopen_s(&file, "assets/hero.txt", "r") == 0)
	{
		fclose(file);
		return true;
	}
	return false;
}