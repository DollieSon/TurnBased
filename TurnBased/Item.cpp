#include "Item.h"
Item::Item(string name,int Health, int Mana, int Power) {
	this->name = name;
	BonusHealth = Health;
	BonusMana = Mana;
	BonusPower = Power;
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