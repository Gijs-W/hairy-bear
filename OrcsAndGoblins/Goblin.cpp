#include "stdafx.h"
#include "Goblin.h"


Goblin::Goblin()
{
}


Goblin::~Goblin()
{
}

Goblin::Goblin(int dungeonLevel)
{
	generateHealthAndLevel(dungeonLevel);
}

std::string Goblin::getName()
{
	return "goblin";
}

std::string Goblin::getDescription()
{
	return ", hij is klein en ziet er niet sterk uit";
}

std::string Goblin::getMultipleDescription()
{
	return ", ze rennen naar je toe met hun messen en knuppels";
}

int Goblin::getFlightChance()
{
	return m_flightChance;
}

EnemyType Goblin::getType()
{
	return EnemyType::Goblin;
}

int Goblin::getHealth()
{
	return m_health;
}

int Goblin::doAttack()
{
	//todo
	return (rand() % (m_level * 3));
}

int Goblin::attack(int damage)
{
	int realdamage = (((damage * 100) - m_armor)/100);
	m_health = m_health - realdamage;
	return realdamage;
}

int Goblin::getXP()
{
	return (m_level * 15);
}

void Goblin::generateHealthAndLevel(int dungeonLevel)
{
	int m_basehealth = 20;
	m_health = m_basehealth * dungeonLevel;
	int m_baseXPonDeath = 20;
	m_xpOnDeath = m_baseXPonDeath * dungeonLevel;
	m_level = dungeonLevel * 2;
	int m_baseFlightChance = 20;
	m_flightChance = m_baseFlightChance / dungeonLevel;
	int m_baseArmor = 8;
	m_armor = m_baseArmor * dungeonLevel;
}