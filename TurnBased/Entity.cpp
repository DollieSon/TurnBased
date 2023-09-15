#include "Entity.h"


Entity::Entity(string name, int Health, int Mana, int Power, int Armor, int Level) {
	Weapon = NULL;
	this->name = name;
	MaxHealth = Health;
	CurHealth = MaxHealth;
	MaxMana = Mana;
	CurMana = MaxMana;
	this->Power = Power;
	this->Armor = Armor;
	this->Level = Level;
	//cout << "EntityParent Created" << endl;
}

	//Setters and Resetters
int Entity :: reduceHealth(int damage) {
		CurHealth -= damage;
		if (CurHealth > 0) {

			return CurHealth;
		}
		return -1;
	}
bool Entity :: resetHealth() {
		CurHealth = MaxHealth;
		return true;
	}

int Entity :: reduceMana(int amount) {
		CurMana -= amount;
		if (CurMana > 0) {
			return CurMana;
		}
		return -1;
	}
bool Entity :: resetMana() {
		CurMana = MaxMana;
		return true;
	}

	// Actual Functions
		// To be overidden by Player Class

void Entity :: printLevel() {
		cout << "Level : " << Level << endl;
}

void Entity :: printStats() {
		cout << "-*-*- " << name << " -*-*-" << endl;
		printLevel();
		cout << "Health :" << CurHealth << "/" << MaxHealth << endl;
		cout << "Mana : " << CurMana << "/" << MaxMana << endl;
		cout << "Power : " << Power << endl;
		cout << "Armor : " << Armor << endl;

}

string Entity::GetName() {
	return name;
}

bool Entity::isAlive() {
	if (CurHealth > 0) {
		return 1;
	}
	return 0;
}

int Entity::getPower() {
	return Power;
}

bool Entity::equip(Item* item) {
	MaxHealth += item->gHealth();
	MaxMana += item->gMana();
	Power += item->gPower();
}
bool Entity::unequip(Item* item) {
	MaxHealth -= item->gHealth();
	MaxMana -= item->gMana();
	Power -= item->gPower();
}


// Player Class

Player :: Player(string name, int Health, int Mana, int Power, int Armor, int Level, int Money) : Entity(name, Health, Mana, Power, Armor, Level) {
		//cout << "--Player Model" << endl;
		this->Money = Money;
		Exp = 0;
		ExpThreshold = 10 * this->Level;
	}

void Player :: printLevel() {
		Entity::printLevel();
		cout << "Level : " << Level << "(" << Exp << "/" << ExpThreshold << ")" << endl;
	}


// Enemy Class

Enemy::Enemy(string name, int Health, int Mana, int Power, int Armor, int Level, int GoldDrop) : Entity(name, Health, Mana, Power, Armor, Level) {
	MoneyReward = GoldDrop;
}