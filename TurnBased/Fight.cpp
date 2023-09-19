#include "Fight.h"
#include "Entity.h"

void Fight(Player* MainChar, Enemy* Opponent) {
	int turns = 0;
	int total_damage = 0;
	int damage_taken = 0;
	int tempdamage;
	cout << MainChar->GetName() << " Vs. " << Opponent->GetName() << endl;
	cout << "Starting..." << endl;
	// starting fight
	// Fight Order
	// Heal
	// Attack
	// Apply Status
	// Status Damage

	// THIS IS SCUFFED SHOULD BE REIMPLEMENTED
	while (MainChar->isAlive() && Opponent->isAlive()) {

		cout << "-----Turn: " << turns << "--------" << endl << endl << endl;

		// Player First:
		// insert Heal Opponent
		Opponent->HealingStatuses();
		tempdamage = MainChar->getPower();
		total_damage += Opponent->reduceHealth(tempdamage);
		// Apply Status Effects From Weapon to Opponent
		Opponent->ApplyStatusByWeapon(MainChar->Weapon);
		MainChar->addStatus(2, MainChar->Weapon->gEffecLevel(2));
		total_damage += Opponent->reduceHealth(tempdamage * MainChar->Weapon->gEffecLevel(6));
		MainChar->reduceHealth((-1) * MainChar->Weapon->gEffecLevel(7));
		MainChar->reduceHealth(Opponent->Weapon->gEffecLevel(8));
		// Deal Damage to Oppent by thier statuses
		total_damage += Opponent->DamageByStatus();
		

		// Monster's turn
		MainChar->HealingStatuses();
		tempdamage = Opponent->getPower();
		damage_taken += MainChar->reduceHealth(tempdamage);
		// Apply Status Effects From Weapon to Opponent
		MainChar->ApplyStatusByWeapon(MainChar->Weapon);
		Opponent->addStatus(2, Opponent->Weapon->gEffecLevel(2));
		damage_taken += Opponent->reduceHealth(tempdamage * Opponent->Weapon->gEffecLevel(6));
		Opponent->reduceHealth((-1) * MainChar->Weapon->gEffecLevel(7));
		Opponent->reduceHealth(MainChar->Weapon->gEffecLevel(8));
		// Deal Damage to MainChar by thier statuses
		damage_taken += MainChar->DamageByStatus();
		turns += 1;

		// debug purposes
		MainChar->printStats();
		Opponent->printStats();
	}
	// checking who wins
	if (MainChar->isAlive()) {
		cout << MainChar->GetName() << " Won!!" << endl;
	}
	else {
		cout << Opponent->GetName() << " Won!!" << endl;
	}
	MainChar->resetstats();
	//printing stats
	cout << "Damage dealt :" << total_damage  << "/" << (double) total_damage / turns  << " Per turn" << endl;
	cout << "Damage taken :" << damage_taken << "/" << (double) damage_taken / turns << " Per Turn" << endl;
}