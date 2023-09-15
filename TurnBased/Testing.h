#pragma once
#include "Item.h"
#include "Entity.h"
#include "Fight.h"
#include "AttackPattern.h"
namespace Testing {
	void TestPrintStats();
}

void TestPrintStats() {
	Player* MainCharacter = new Player("Ray", 20, 10, 2, 5, 1, 100);
	Entity* Enemy = new Entity("Goblin", 5, 1, 1, 5, 1);
	MainCharacter->printStats();
	Enemy->printStats();
	delete MainCharacter;
	delete Enemy;
}

void TestFighting() {
	Player* MainCharacter = new Player("Ray", 20, 10, 2, 5, 1, 100);
	Enemy* Globlin = new Enemy("Goblin", 12, 13, 3, 6, 1, 21);
	Fight(MainCharacter,Globlin);
	delete MainCharacter;
	delete Globlin;
}

void TestAttackPattern() {
	AttackPattern* Number1 = new AttackPattern;
	Enemy* Globlin1 = new Enemy("Goblin1", 12, 13, 3, 6, 1, 21);
	Enemy* Globlin2 = new Enemy("Goblin2", 12, 13, 3, 6, 1, 21);
	Enemy* Globlin3 = new Enemy("Goblin3", 12, 13, 3, 6, 1, 21);
	Enemy* Globlin4 = new Enemy("Goblin4", 12, 13, 3, 6, 1, 21);
	Number1->pushTail(Globlin1);
	Number1->pushTail(Globlin2);
	Number1->pushTail(Globlin3);
	Number1->pushTail(Globlin2);
	Number1->pushTail(Globlin4);
	Number1->printAllNode();
	cout << "Popping" << endl << endl;
	Number1->popAllNode(Globlin2);
	Number1->printAllNode();
	Number1->popAllNode(Globlin1);
	Number1->printAllNode();
	Number1->popAllNode(Globlin3);
	Number1->printAllNode();
	Number1->popAllNode(Globlin4);
	Number1->printAllNode();

}