#pragma once
#include <string>
#include <iostream>

using namespace std;

class Item
{
protected:
	string name;
	int BonusHealth;
	int BonusMana;
	int BonusPower;
public:
	Item(string name,int Health,int Mana,int Power);
	int gHealth();
	int gMana();
	int gPower();
	string gName();
};

