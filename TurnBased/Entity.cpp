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
	statuses.resize(6);
	//cout << "EntityParent Created" << endl;
}

	//Setters and Resetters
int Entity :: reduceHealth(int damage) {
		CurHealth -= damage;
		return (CurHealth < 0) ? CurHealth + damage : damage;
	}
bool Entity :: resetHealth() {
		CurHealth = MaxHealth;
		return true;
	}

int Entity :: reduceMana(int amount) {
		CurMana -= amount;
		return (CurMana < 0) ? CurMana + amount : amount;
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
	cout <<"Equiped: " << item->gName() << endl;
	MaxHealth += item->gHealth();
	MaxMana += item->gMana();
	Power += item->gPower();
	// turn to be dynamic
	Weapon = item;
	return 1;
}
bool Entity::unequip(Item* item) {
	cout << "Unequiped: " << item->gName() << endl;
	MaxHealth -= item->gHealth();
	MaxMana -= item->gMana();
	Power -= item->gPower();
	//Remove To be more dynamic
	Weapon = NULL;
	return 1;
}

void Entity::resetstats() {
	resetHealth();
	resetMana();
}


void Entity::setStatus(int index, int number) {
	statuses[index] = number;
}
void Entity::addStatus(int index, int number){
	statuses[index] += number;
}
//
//1 Bleed // damaging
//2 Poison // damaging
//3 Healing // negative damaging
//4 LowerAttack // lower stat
//5 LowerMana // lower stat
//6 LowerHealth // lower stat
int Entity::HealingStatuses() {
	// Check Heal
	int HealedAmt =0;
	if (statuses[2] > 0) {
		//debug
		cout << name << " Healed : " << statuses[2] << endl;

		CurHealth += statuses[2];
		HealedAmt += statuses[2];
		statuses[2] /= 2;
	}
	return HealedAmt;
}
int Entity::DamageByStatus() {
	//Check Bleed
	int DamageDealt = 0;
	if (statuses[0] > 0) {

		cout << name << " Bled : " << statuses[0] << endl;

		DamageDealt += statuses[0];
		CurHealth -= statuses[0];
	}
	if (statuses[1] > 0) {

		cout << name << " poisoned : " << statuses[1] << endl;

		DamageDealt += statuses[1];
		CurHealth -= statuses[1];
		statuses[1] /= 2;
		statuses[1] -= 1;
	}
	return DamageDealt;
}


void Entity::ApplyStatusByWeapon(Item* weapon) {
	for (int x = 0; x < 6; x++) {
		if (x == 2) continue;
		statuses[x] += weapon->gEffecLevel(x);
	}
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

