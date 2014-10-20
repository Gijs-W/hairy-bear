#pragma once
#include "stdafx.h"
using namespace std;
class Hero
{
private:
	string m_name;
	int m_level = 1;
	int m_health = 100;
	int m_XP = 0;
	int m_attackXP = 0;
	int m_defenceXP = 0;
	int m_alertnessXP = 0;

public:
	Hero();
	virtual ~Hero();

	string getName();
	int getLevel();
	int getHealth();
	int getXP();
	int getAttackXP();
	int getDefenceXP();
	int getAlertnessXP();

	void setName(string name);
	void setLevel(int level);
	void setHealth(int health);
	void setXP(int xp);
	void setAttackXP(int attackXP);
	void setDefenceXP(int defenceXP);
	void setAlertnessXP(int alertnessXP);


};

