#pragma once
enum class EnemyType
{
	Orc,
	Goblin,
	Rat,
	Skeleton
};
class Enemy
{
public:
	Enemy();
	Enemy(int dungeonLevel);
	virtual ~Enemy();
	virtual std::string getName() = 0;
	virtual EnemyType getType() = 0;
	virtual int getHealth() = 0;
	virtual int getLevel() = 0;
	virtual int getXP() = 0;
private:
	virtual void generateHealthAndLevel(int dungeonLevel) = 0;
	std::string m_name;
	int m_health;
	int m_level;
	int m_xpOnDeath;
	EnemyType type;
};

