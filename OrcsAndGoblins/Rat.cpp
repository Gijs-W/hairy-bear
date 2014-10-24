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

int Rat::getHealth()
{
	return m_health;
}

int Rat::getLevel()
{
	return m_level;
}

std::string Rat::getName()
{
	return "Rat";
}

int Rat::getXP()
{
	return m_xpOnDeath;
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
}
