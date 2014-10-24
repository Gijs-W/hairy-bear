#pragma once
#include "Enemy.h"
class Rat : public Enemy
{
public:
	Rat();
	virtual ~Rat();
	Rat(int dungeonLevel);
	int getXP();
	int getLevel();
	int getHealth();
	EnemyType getType();
	std::string getName();
private:
	void generateHealthAndLevel(int dungeonLevel);
	std::string m_name;
	int m_health;
	int m_level;
	int m_xpOnDeath;
	EnemyType type;
};

