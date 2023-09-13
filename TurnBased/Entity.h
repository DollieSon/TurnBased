#include <iostream>
#include <string>
using namespace std;

class Entity {
public:
	Entity(string name, int Health, int Mana, int Power, int Armor, int Level);
	int reduceHealth(int damage);
	bool resetHealth();
	int reduceMana(int amount);
	bool resetMana();
	void printLevel();
	void printStats();
};

class Player : public Entity {
public:
	Player(string name, int Health, int Mana, int Power, int Armor, int Level, int Money);
	void printLevel();
};

