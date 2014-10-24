#include "stdafx.h"
#include "Hero.h"


Hero::Hero()
{
	m_posX = 0;
	m_posY = 0;
}


Hero::~Hero()
{
}

bool Hero::regenerateHealth() {
	// Het maximum aantal levens cappen bij regeneraten
	if (m_health >= m_level * 2) {
		return false;
	}
	m_health++;
	return true;
}

bool Hero::regenerateHealth(int health) {
	// Het maximum aantal levens cappen bij regeneraten
	if (m_health >= m_level * 2) {
		return false;
	}
	m_health += health
	return true;
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