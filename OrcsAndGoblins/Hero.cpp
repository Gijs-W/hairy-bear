#include "stdafx.h"
#include "Hero.h"


Hero::Hero()
{
	m_posX = 0;
	m_posY = 0;
	inventory = new vector < Item* > ();

}


Hero::~Hero()
{
	for (auto &it : *inventory) {
		delete it;
	}
	delete inventory;
}

bool Hero::regenerateHealth(int health) {
	// Het maximum aantal levens cappen bij regeneraten
	int maxHealth = m_level * 2;

	if (m_health + health >= maxHealth) {
		if (maxHealth - m_health == 0) {
			return false;
		}
		m_health = maxHealth;
		return true;
	}
	m_health += health;
	return true;
}

bool Hero::regenerateHealth() {
	return regenerateHealth(1);
}


void Hero::addToInventory(Item* item) {
	inventory->push_back(item);
}
void Hero::removeFromInventory(Item* item) {
	for (auto it = inventory->begin(); it != inventory->end(); it++) {
		if (*it == item) {
			*it = nullptr;
			delete item;
		}
	}

	auto toRemove = std::remove_if(inventory->begin(), inventory->end(), [](Item* p) {
		return p == nullptr;
	});

	inventory->erase(toRemove, inventory->end());
}
vector<Item*>* Hero::getInventoryList() {
	return inventory;
}


string Hero::getName() {
	return m_name;
}
int Hero::getLevel() {
	return m_level;
}
int Hero::getHealth() {
	return m_health;
}
int Hero::getXP() {
	return m_XP;
}
int Hero::getAttackXP() {
	return m_attackXP;
}
int Hero::getDefenceXP() {
	return m_defenceXP;
}
int Hero::getAlertnessXP() {
	return m_alertnessXP;
}

void Hero::setName(string name) {
	m_name = name;
}
void Hero::setLevel(int level) {
	m_level = level;
}
void Hero::setHealth(int health) {
	m_health = health;
}
void Hero::setXP(int xp) {
	m_XP = xp;
}
void Hero::setAttackXP(int attackXP) {
	m_attackXP;
}
void Hero::setDefenceXP(int defenceXP) {
	m_defenceXP;
}
void Hero::setAlertnessXP(int alertnessXP) {
	m_alertnessXP = alertnessXP;
}

int Hero::getPosX() {
	return m_posX;
}

int Hero::getPosY() {
	return m_posY;
}

void Hero::setPosY(int y) {
	m_posY = y;
}

void Hero::setPosX(int x){
	 m_posX = x;
}