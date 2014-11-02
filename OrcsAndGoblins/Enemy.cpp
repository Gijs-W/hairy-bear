#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

int Enemy::getXP()
{
	return m_xpOnDeath;
}

int Enemy::getFlightChance()
{
	return m_flightChance;
}

int Enemy::getHealth()
{
	return m_health;
}

int Enemy::getLevel()
{
	return m_level;
}
