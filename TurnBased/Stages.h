#pragma once
#include <string>
#include "Entity.h"
#include "Item.h"
using namespace std;

struct StageNode
{
	string StageID;
	Entity* Enemy;
	Item* reward;
	StageNode* Next;
	StageNode* Side;
	
	StageNode() {
		StageID = "";
	}

};


class Stages
{
protected:
	vector<StageNode*> StageList;
	int row;
	int col;
public:
	Stages(int col, int row);
	StageNode* CreateStage(string name, Entity* enemy, Item* reward);
	void GenerateStages(vector<Entity*> Entities, vector<Item*> items);
	void printStages();
};

