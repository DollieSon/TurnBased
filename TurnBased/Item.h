#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Item
{
protected:
	string name;
	int BonusHealth;
	int BonusMana;
	int BonusPower;
	vector<int> WeaponEffects;

public:
	Item(string name,int Health,int Mana,int Power);
	int gHealth();
	int gMana();
	int gPower();
	string gName();
	int gEffecLevel(int ind);
	void printEffects();
	int setWeaponEffect(int index, int number);
};

