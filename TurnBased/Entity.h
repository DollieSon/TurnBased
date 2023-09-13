#include <iostream>
#include <string>
#ifndef ENTITY
#define ENTITY

using namespace std;

class Entity {
protected:
	string name;
	int MaxHealth;
	int CurHealth;
	int Power;
	int MaxMana;
	int CurMana;
	int Armor;
	int Level;
public:
	Entity(string name, int Health, int Mana, int Power, int Armor, int Level);
	int reduceHealth(int damage);
	bool resetHealth();
	int reduceMana(int amount);
	bool resetMana();
	void printLevel();
	void printStats();
	string GetName();
	bool isAlive();
	int getPower();
};

class Player : public Entity {
protected:
	int Money;
	int Exp;
	int ExpThreshold;
public:
	Player(string name, int Health, int Mana, int Power, int Armor, int Level, int Money);
	void printLevel();
};

class Enemy : public Entity{
protected:
	int MoneyReward;
public:
	Enemy(string name, int Health, int Mana, int Power, int Armor, int Level, int GoldDrop);
};
#endif // !ENTITY