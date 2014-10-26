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

std::string Orc::getDescription()
{
	return ", je ziet zijn varkensachtig gezicht met smerige, scherpe tanden";
}

std::string Orc::getMultipleDescription()
{
	return ", ze zitten elkaar uit te schelden in een taal die je niet kent, totdat ze jouw zien staan";
}

EnemyType Orc::getType()
{
	return EnemyType::Orc;
}

int Orc::getHealth()
{
	return m_health;
}

int Orc::doAttack()
{
	//todo
	return 1;
}

int Orc::attack(int damage)
{
	int realdamage = (damage - (m_armor / 2));
	m_health = m_health - realdamage;
	return realdamage;
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
	int m_baseArmor = 5;
	m_armor = m_baseArmor * dungeonLevel;
}