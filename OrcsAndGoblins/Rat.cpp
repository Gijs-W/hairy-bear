#include "stdafx.h"
#include "Rat.h"


Rat::Rat()
{
}


Rat::~Rat()
{
}

Rat::Rat(int dungeonLevel)
{
	generateHealthAndLevel(dungeonLevel);
}

std::string Rat::getName()
{
	return "rat";
}

EnemyType Rat::getType()
{
	return EnemyType::Rat;
}

int Rat::getHealth()
{
	return m_health;
}

int Rat::doAttack()
{
	//todo
	return 1;
}

std::string Rat::getDescription()
{
	return ", het is een vies smerig beest en is niet bepaald vrolijk";
}

std::string Rat::getMultipleDescription()
{
	return ", ze rennen snel naar je toe met hun messcherpe tanden";
}

int Rat::attack(int damage)
{
	int realdamage = (damage - (m_armor / 2));
	m_health = m_health - realdamage;
	return realdamage;
}


void Rat::generateHealthAndLevel(int dungeonLevel)
{
	int m_basehealth = 15;
	m_health = m_basehealth * dungeonLevel;
	int m_baseXPonDeath = 15;
	m_xpOnDeath = m_baseXPonDeath * dungeonLevel;
	m_level = dungeonLevel * 1;
	int m_baseFlight = 50;
	m_flightChance = m_baseFlight / dungeonLevel;
	int m_baseArmor = 2;
	m_armor = m_baseArmor * dungeonLevel;
}
