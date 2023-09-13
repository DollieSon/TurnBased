#include "Entity.cpp"

int main()
{
	PlayerEntity* MainCharacter = new PlayerEntity("Ray", 20, 10, 2, 5, 1, 100);
	EntityParent* Enemy = new EntityParent("Goblin", 5, 1, 1, 5, 1);
	MainCharacter->printStats();
	Enemy->printStats();
}
