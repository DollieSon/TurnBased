#include "Entity.cpp"

namespace Testing {
	void TestPrintStats();
}

void TestPrintStats() {
	PlayerEntity* MainCharacter = new PlayerEntity("Ray", 20, 10, 2, 5, 1, 100);
	EntityParent* Enemy = new EntityParent("Goblin", 5, 1, 1, 5, 1);
	MainCharacter->printLevel();
	Enemy->printLevel();
}