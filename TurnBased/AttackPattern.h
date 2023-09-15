#pragma once
#include "Entity.h"
#ifndef ATTACKPATTERN

struct PatternNode {
	Enemy* Enemyptr;
	PatternNode* Next;

	PatternNode();
};


class AttackPattern
{
protected:
	PatternNode* HeadNode;
	PatternNode* TailNode;
public:
	AttackPattern();
	void pushTail(Enemy* Enemptr);
	void popAllNode(Enemy* Enemptr);
	void printAllNode();

};
#endif // !ATTACKPATTERN


