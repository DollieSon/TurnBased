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
	uniform_int_distribution<int> RandStage(0, row - 1);
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

			index = y + (x * (col));
			TempStage = CreateStage("Row:"+to_string(x) + ", Col:" + to_string(y), ChosenEnem, ChosenItem);
			//cout << TempStage->StageID << " " << endl;
			StageList[index] = TempStage;
			
		}
		//Connect Stages
		if (x < 1) continue;
		for (int y = 0; y < col; y++) {
			index = (y) + ((x-1) * col);
			index2 = y + (x * col);
			StageList[index]->Next = StageList[index2];
			index2 = (RandStage(gen)) + (x * col);
			StageList[index]->Side = StageList[index2];
		}
	}
};
void Stages::printStages() {
	vector<string> Lines;
	int index = -1;
	int biggest = 0;
	string stagename;
	//get base
	for (int x = 0; x < row; x++) {
		index = x * col;
		stagename = "N: End | S: End";
		//four lines
		Lines.push_back(StageList[index]->StageID);
		Lines.push_back(StageList[index]->Enemy->GetName());
		Lines.push_back(StageList[index]->reward->gName());
		if (StageList[index]->Next != nullptr) stagename = "N: " + StageList[index]->Next->StageID + "|" + "S:" + StageList[index]->Side->StageID;
		Lines.push_back(stagename);
	}
	//build on base
	for(int y = 0; y < col; y++) {

		
	}
	// print all Lines
	for (string Line : Lines) {
		cout << Line << endl;
	}
};
