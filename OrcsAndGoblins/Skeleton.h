#pragma once
#include "Enemy.h"
class Skeleton : public Enemy
{
public:
	Skeleton();
	virtual ~Skeleton();
	Skeleton(int dungeonLevel);
	EnemyType getType();
	int getHealth();
	std::string getName();
	int getXP();
	int doAttack();
	int attack(int damage);
	int getFlightChance();
	std::string getDescription();
	std::string getMultipleDescription();
private:
	void generateHealthAndLevel(int dungeonLevel);
	std::string m_name;
	int m_health;
	int m_level;
	int m_flightChance;
	int m_xpOnDeath;
	int m_attack;
	int m_armor;
	EnemyType type;
};

