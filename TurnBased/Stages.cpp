#include "Stages.h"
#include <random>
#include <string>
#include "Entity.h"
#include "Item.h"
using namespace std;



StageNode* Stages::CreateStage(string name, Entity* enemy, Item* reward) {
	StageNode* res = new StageNode();
	if (res == NULL) return NULL;
	res->StageID = "";
	res->StageID += name;
	res->Enemy = enemy;
	res->reward = reward;
	res->Side = nullptr;
	res->Next = nullptr;
	return res;
}

Stages::Stages(int col, int row) {
	this->col = col;
	this->row = row;
	StageList.resize(col * row);

};

void Stages::GenerateStages(vector<Entity*> Entities, vector<Item*> items) {
	random_device rd;
	Item* noneItem;
	mt19937 gen(rd());
	uniform_int_distribution<int> YesNo(0, 1);
	uniform_int_distribution<int> RandEnt(0, Entities.size()-1);
	uniform_int_distribution<int> RandItem(0, items.size()-1);
	uniform_int_distribution<int> RandStage(0, col - 1);
	Entity* ChosenEnem = nullptr;
	Item* ChosenItem = nullptr;
	StageNode* TempStage = nullptr;
	int index = -1;
	int index2 = -1;
	if (StageList.size() == 0) return;
	for (int x = 0; x < row; x++) {
		//genrate Stages
		for (int y = 0; y < col; y++) {
			//generate item and enemy
			if (YesNo(gen) == 1) ChosenItem = items[RandItem(gen)];
			else {
				noneItem = new Item("None", 0, 0, 0);
				ChosenItem = noneItem;
			}
			ChosenEnem = Entities[RandEnt(gen)];

			index = x + (y * col);
			TempStage = CreateStage("Row:"+to_string(x) + ", Col:" + to_string(y), ChosenEnem, ChosenItem);
			StageList[index] = TempStage;
			
		}
		//Connect Stages
		if (x < 1) continue;
		for (int y = 0; y < col; y++) {
			index = (x - 1) + (y * col);
			index2 = x + (y * col);
			StageList[index]->Next = StageList[index2];
			index2 = (x) + (RandStage(gen) * col);
			StageList[index]->Side = StageList[index2];
		}
	}
};
void Stages::printStages() {
	vector<string> Lines;
	int index = -1;
	int biggest = 0;
	//get base
	for (int x = 0; x < row; x++) {
		index = x * col;
		//four lines
		Lines.push_back(StageList[index]->StageID);
		Lines.push_back(StageList[index]->Enemy->GetName());
		Lines.push_back(StageList[index]->reward->gName());
		Lines.push_back("Next: " + StageList[index]->Next->StageID + "|" + "Side:" + StageList[index]->Side->StageID);
	}
	//build on base
	for(int y = 0; y < col; y++) {

		
	}
	// print all Lines
	for (string Line : Lines) {
		cout << Line << endl;
	}
};
