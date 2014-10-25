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

void Rat::generateHealthAndLevel(int dungeonLevel)
{
	int m_basehealth = 15;
	m_health = m_basehealth * dungeonLevel;
	int m_baseXPonDeath = 15;
	m_xpOnDeath = m_baseXPonDeath * dungeonLevel;
	m_level = dungeonLevel * 1;
	int m_baseFlight = 50;
	m_flightChance = m_baseFlight / dungeonLevel;
}
