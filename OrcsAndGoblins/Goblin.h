#pragma once
#include "Enemy.h"
class Goblin : public Enemy
{
public: 
	Goblin();
	virtual ~Goblin();
	Goblin(int dungeonLevel);
	EnemyType getType();
	std::string getName();
private:
	void generateHealthAndLevel(int dungeonLevel);
	std::string m_name;
	int m_health;
	int m_level;
	int m_flightChance;
	int m_xpOnDeath;
	EnemyType type;
};

