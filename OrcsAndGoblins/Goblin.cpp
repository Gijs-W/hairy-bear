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

int Goblin::getHealth()
{
	return m_health;
}

int Goblin::getLevel()
{
	return m_level;
}

std::string Goblin::getName()
{
	return "Goblin";
}

int Goblin::getXP()
{
	return m_xpOnDeath;
}

EnemyType Goblin::getType()
{
	return EnemyType::Goblin;
}

void Goblin::generateHealthAndLevel(int dungeonLevel)
{
	int m_basehealth = 20;
	m_health = m_basehealth * dungeonLevel;
	int m_baseXPonDeath = 20;
	m_xpOnDeath = m_baseXPonDeath * dungeonLevel;
	m_level = dungeonLevel * 2;
}