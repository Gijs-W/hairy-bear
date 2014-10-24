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

int Orc::getHealth()
{
	return m_health;
}

int Orc::getLevel()
{
	return m_level;
}

std::string Orc::getName()
{
	return "Ork";
}

int Orc::getXP()
{
	return m_xpOnDeath;
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
}