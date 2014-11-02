#pragma once
#include "stdafx.h"
#include <algorithm>

using namespace std;
struct Position {
	int x;
	int y;
};
class Item;

class Hero
{
private:
	vector<Item*>* inventory;
	string m_name;
	int m_level = 1;
	int m_health = 100;
	int m_XP = 0;
	int m_attackXP = 0;
	int m_defenceXP = 0;
	int m_alertnessXP = 0;
	int m_posX;
	int m_posY;
	

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
	int getPosX();
	int getPosY();
	int getAttackLevel();
	int getDefenseLevel();
	int getAlertnessLevel();

	void setName(string name);
	void setLevel(int level);
	void setHealth(int health);
	void setXP(int xp);
	void setAttackXP(int attackXP);
	void setDefenceXP(int defenceXP);
	void setAlertnessXP(int alertnessXP);
	void setPosX(int x);
	void setPosY(int y);

	bool regenerateHealth();
	bool regenerateHealth(int health);

	void addToInventory(Item* item);
	void removeFromInventory(Item* item);
	vector<Item*>* getInventoryList();

};

