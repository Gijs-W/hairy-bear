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
	int m_baseFlightChance = 20;
	m_flightChance = m_baseFlightChance / dungeonLevel;
}