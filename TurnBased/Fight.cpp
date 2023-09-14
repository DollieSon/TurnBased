#include "Fight.h"
#include "Entity.h"
void Fight(Player* MainChar, Enemy* Opponent) {
	int turns = 0;
	int total_damage = 0;
	int damage_taken = 0;
	int tempdamage;
	cout << MainChar->GetName() << " Vs. " << Opponent->GetName() << endl;
	cout << "Starting..." << endl;
	while (MainChar->isAlive() || Opponent->isAlive()) {
		tempdamage = MainChar->getPower();
		total_damage += tempdamage;
		Opponent->reduceHealth(tempdamage);
		tempdamage = Opponent->getPower();
		damage_taken += tempdamage;
		MainChar->reduceHealth(tempdamage);
		turns += 1;
	}
	if (MainChar->isAlive()) {
		cout << MainChar->GetName() << " Won!!" << endl;
	}
	else {
		cout << Opponent->GetName() << " Won!!" << endl;
	}
	cout << "Damage dealt :" << total_damage  << "/" << (double) total_damage / turns  << " Per turn" << endl;
	cout << "Damage taken :" << damage_taken << "/" << (double) damage_taken / turns << " Per Turn" << endl;
}