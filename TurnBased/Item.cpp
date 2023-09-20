#include "Item.h"

#define EFFECTNUM 9

Item::Item(string name,int Health, int Mana, int Power) {
	this->name = name;
	BonusHealth = Health;
	BonusMana = Mana;
	BonusPower = Power;
	WeaponEffects.resize(EFFECTNUM);
	/*
	for (int x = 0; x < WeaponEffects.size();x++) {
		x = -1;
	}*/
}

int Item::gHealth() {
	return BonusHealth;
}
int Item::gMana() {
	return BonusMana;
}
int Item::gPower() {
	return BonusPower;
}

string Item::gName() {
	return name;
}


int Item::gEffecLevel(int ind) {
	if (ind > 0 && ind < WeaponEffects.size()) {
		return WeaponEffects[ind];
	}
	return -10000;
}

void Item::printEffects() {
	vector<string> titles = { "Bleeding","Poison","Healing","Decreased Attack","Decrease Mana","Decrease Health","Multi-Attack","Lifesteal","Thorns"};
	cout << "Weapon Name: " << name << endl;
	for (int i = 0; i < titles.size(); i++) {
		cout << titles[i] << ": " << WeaponEffects[i] << endl;
	}

}

int Item::setWeaponEffect(int index, int number) {
	if (index > 0 && index < WeaponEffects.size()) {
		WeaponEffects[index-1] = number;
		return 1;
	}
	return 0;
}
