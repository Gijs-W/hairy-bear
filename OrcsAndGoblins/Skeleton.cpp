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

int Skeleton::getHealth()
{
	return m_health;
}

int Skeleton::getLevel()
{
	return m_level;
}

std::string Skeleton::getName()
{
	return "Skeleton";
}

int Skeleton::getXP()
{
	return m_xpOnDeath;
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
}