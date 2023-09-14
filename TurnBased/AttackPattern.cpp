#include "AttackPattern.h"

PatternNode::PatternNode() {
	Enemyptr = NULL;
	Next = NULL;
}

AttackPattern::AttackPattern() {
	HeadNode = NULL;
	TailNode = NULL;
}

void AttackPattern::pushTail(Enemy* Enemptr) {
	PatternNode* tempNode = new PatternNode;
	tempNode->Enemyptr = Enemptr;
	if (HeadNode == NULL && TailNode == NULL) {
		HeadNode = tempNode;
		TailNode = tempNode;
	}
	else {
	TailNode->Next = tempNode;
	TailNode = TailNode->Next;
	}

}
void AttackPattern::popAllNode(Enemy* Enemptr) {
	PatternNode* CurNode = HeadNode;
	PatternNode* TempNode;
	if (HeadNode == NULL) {
		cout << "List is Empty" << endl;
		return;
	}
	if (HeadNode->Enemyptr == Enemptr) {
		TempNode = HeadNode;
		HeadNode = HeadNode->Next;
		delete TempNode;
		return;
	}
	while(CurNode->Next != NULL) {
		if (CurNode->Next->Enemyptr == Enemptr) {
			TempNode = CurNode->Next;
			CurNode->Next = CurNode->Next->Next;
			delete TempNode;
		}
		CurNode = CurNode->Next;
	}

}
void AttackPattern::printAllNode() {
	PatternNode* CurNode = HeadNode;
	while (CurNode != NULL) {
		cout << CurNode->Enemyptr->GetName() << "---";
		CurNode = CurNode->Next;
	}
	cout << endl;
}