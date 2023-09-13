#include <iostream>

using namespace std;

class Entity{
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
	Entity(string name, int Health, int Mana, int Power, int Armor, int Level) {
		this->name = name;
		MaxHealth = Health;
		CurHealth = MaxHealth;
		MaxMana = Mana;
		CurMana = MaxMana;
		this->Power = Power;
		this->Armor = Armor;
		this->Level = Level;
	}
//Setters and Resetters
	int reduceHealth( int damage) {
		CurHealth -= damage;
		if (CurHealth > 0) {
			
			return CurHealth;
		}
		return - 1;
	}
	bool resetHealth() {
		CurHealth = MaxHealth;
		return true;
	}
	int reduceMana(int amount) {
		CurMana -= amount;
		if (CurMana > 0) {
			return CurMana;
		}
		return -1;
	}
	bool resetMana() {
		CurMana = MaxMana;
		return true;
	}

// Actual Functions
	// To be overidden by Player Class
	void printLevel() {
		cout << "Level : " << Level << endl;
	}
	void printStats(){
		cout << "-*-*- " << name << " -*-*-" << endl;
		printLevel();
		cout << "Health :" << CurHealth << "/" << MaxHealth << endl;
		cout << "Mana : " << CurMana << "/" << MaxMana << endl;
		cout << "Power : " << Power << endl;
		cout << "Armor : " << Armor << endl;
		
	}
};

class Player : Entity {
protected:
	int Money;
	int Exp;
	int ExpThreshold;
public:
	Player(string name, int Health, int Mana, int Power, int Armor, int Level,int Money) : Entity(name,Health,Mana,Power,Armor,Level) {
		this->Money = Money;
		Exp = 0;
		ExpThreshold = 10 * this->Level;
	}
};