#pragma once
#include "Enemy.h"
class Orc : public Enemy
{
public:
	Orc();
	Orc(int dungeonLevel);
	virtual ~Orc();
	EnemyType getType();
	int getHealth();
	std::string getName();
	int doAttack();
	int attack(int damage);
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
