#include "stdafx.h"
#include "Orc.h"


Orc::Orc()
{
}


Orc::~Orc()
{
}

Orc::Orc(int dungeonLevel)
{
	generateHealthAndLevel(dungeonLevel);
}

std::string Orc::getName()
{
	return "ork";
}

EnemyType Orc::getType()
{
	return EnemyType::Orc;
}

void Orc::generateHealthAndLevel(int dungeonLevel)
{
	int m_basehealth = 30;
	m_health = m_basehealth * dungeonLevel;
	int m_baseXPonDeath = 30;
	m_xpOnDeath = m_baseXPonDeath * dungeonLevel;
	m_level = dungeonLevel * 2;
	int m_baseFlightChance = 20;
	m_flightChance = m_baseFlightChance / dungeonLevel;
}