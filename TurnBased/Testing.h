#include "Entity.h"

namespace Testing {
	void TestPrintStats();
}

void TestPrintStats() {
	Player* MainCharacter = new Player("Ray", 20, 10, 2, 5, 1, 100);
	Entity* Enemy = new Entity("Goblin", 5, 1, 1, 5, 1);
	MainCharacter->printStats();
	Enemy->printStats();
}