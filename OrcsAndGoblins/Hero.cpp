#include "stdafx.h"
#include "Hero.h"


Hero::Hero()
{
}


Hero::~Hero()
{
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