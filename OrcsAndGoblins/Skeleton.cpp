#include "stdafx.h"
#include "Skeleton.h"


Skeleton::Skeleton()
{
}


Skeleton::~Skeleton()
{
}

Skeleton::Skeleton(int dungeonLevel)
{
	generateHealthAndLevel(dungeonLevel);
}

std::string Skeleton::getName()
{
	return "skelet";
}

int Skeleton::getFlightChance()
{
	return m_flightChance;
}

std::string Skeleton::getDescription()
{
	return ", hij zit je dodelijk aan te kijken met zijn lege oogkassen";
}

std::string Skeleton::getMultipleDescription()
{
	return ", ze ruiken je aanwezigheid en rennen naar je toe";
}

EnemyType Skeleton::getType()
{
	return EnemyType::Skeleton;
}

int Skeleton::getXP()
{
	return (m_level * 17);
}

int Skeleton::getHealth()
{
	return m_health;
}

int Skeleton::doAttack()
{
	//todo
	return (rand() % (m_level * 3));
}

int Skeleton::attack(int damage)
{
	int realdamage = (((damage * 100) - m_armor) / 100);
	m_health = m_health - realdamage;
	return realdamage;
}

void Skeleton::generateHealthAndLevel(int dungeonLevel)
{
	int m_basehealth = 40;
	m_health = m_basehealth * dungeonLevel;
	int m_baseXPonDeath = 40;
	m_xpOnDeath = m_baseXPonDeath * dungeonLevel;
	m_level = dungeonLevel * 3;
	int m_baseFlightChance = 20;
	m_flightChance = m_baseFlightChance / dungeonLevel;
	int m_baseArmor = 8;
	m_armor = m_baseArmor * dungeonLevel;
}