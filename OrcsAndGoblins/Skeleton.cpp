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

EnemyType Skeleton::getType()
{
	return EnemyType::Skeleton;
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
}