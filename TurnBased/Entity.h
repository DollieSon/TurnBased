#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Item.h"
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
	// implement AttackPatternNode
	
	//Statuses Should be dynamic, currently sized 6
	vector<int> statuses;

public:
	// to be changed into an equipment class
	Item* Weapon;
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
	bool equip(Item* item);
	bool unequip(Item* item);
	void resetstats();
	void setStatus(int index, int number);
	void addStatus(int index, int number);
	int HealingStatuses();
	int DamageByStatus();
	void ApplyStatusByWeapon(Item* weapon);
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