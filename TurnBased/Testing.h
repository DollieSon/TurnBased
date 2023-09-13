#include "Entity.h"
#include "Fight.h"
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