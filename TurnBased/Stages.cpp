#include "Stages.h"
#include <random>
#include <string>
#include "Entity.h"
#include "Item.h"
#include <iostream>
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
			//should duplicate and not get refecnce (Needs Rework)
			if (YesNo(gen) == 1) ChosenItem = items[RandItem(gen)];
			else {
				noneItem = new Item("None", 0, 0, 0);
				ChosenItem = noneItem;
			}
			ChosenEnem = Entities[RandEnt(gen)];

			index = y + (x * (col));
			TempStage = CreateStage("R:"+to_string(x) + ",C:" + to_string(y), ChosenEnem, ChosenItem);
			//cout << TempStage->StageID << " " << endl;
			StageList[index] = TempStage;
			
		}
		//Connect Stages
		if (x < 1) continue;
		for (int y = 0; y < col; y++) {
			int rand = RandStage(gen);
			index = (y) + ((x-1) * col);
			index2 = y + (x * col);
			StageList[index]->Next = StageList[index2];
			index2 = (rand) + (x * col);
			StageList[index]->Side = StageList[index2];
		}
	}
};
void Stages::printStages() {
	const int margin = 5;
	const int LINESPERSTAGE = 4;
	vector<string> Lines;
	vector<string> TempLines;
	int index = -1;
	int biggest = 0;
	string stagename;
	int space;

	//get base
	//Should Be ReCoded --Still Works
	for (int x = 0; x < row; x++) {
		index = x * col;
		stagename = "N: End | S: End";
		//four lines
		Lines.push_back(StageList[index]->StageID);
		Lines.push_back(StageList[index]->Enemy->GetName());
		Lines.push_back(StageList[index]->reward->gName());
		if (StageList[index]->Next != nullptr) stagename =  StageList[index]->Next->StageID + "|"  + StageList[index]->Side->StageID;
		Lines.push_back(stagename);
	}

	space = GetLongest(&Lines);
	insertSpace(space+margin, &Lines);

	//build on base
	int lineIndex = 0;
	for(int y = 1; y < col; y++) {
		TempLines.resize(0);
		for (int x = 0; x < row; x++) {
			//reset everything
			index = (x * col) + y;
			stagename = "N: End | S: End";
			// set on templine
			TempLines.push_back(StageList[index]->StageID);
			TempLines.push_back(StageList[index]->Enemy->GetName());
			TempLines.push_back(StageList[index]->reward->gName());
			if (StageList[index]->Next != nullptr) stagename =  StageList[index]->Next->StageID + "|" +  StageList[index]->Side->StageID;
			TempLines.push_back(stagename);
		}

		/*for (string line : TempLines) {
			cout << line << endl;
		}*/
		//cout << endl << endl;
		lineIndex = 0;
		space = GetLongest(&TempLines);
		for (int x = 0; x < TempLines.size(); x++) {
			Lines[lineIndex++] += TempLines[x];
		}
		insertSpace(space + margin, &Lines, &TempLines);
	}
	// print all Lines
	for (int x = 0; x < Lines.size(); x++) {
		cout << Lines[x] << endl;
		if (x % LINESPERSTAGE == 3) cout << endl;

	}
	/*for (string Line : Lines) {
		cout << Line << endl;
	}*/

	cout << "Line Size: " << Lines.size();
};

void Stages::insertSpace(int spaces, vector<string>* lines) {
	int truespace = spaces ;
	string space(truespace, ' ');
	int curLen;
	for (int x = 0; x < lines->size(); x++) {
		curLen = (*lines)[x].size();
		(*lines)[x] += space.substr(0, truespace - curLen);
	}
}

void Stages::insertSpace(int spaces, vector<string>* lines, vector<string>* Templines) {
	int truespace = spaces;
	string space(truespace, ' ');
	int curLen;
	for (int x = 0; x < lines->size(); x++) {
		curLen = (*Templines)[x].size();
		(*lines)[x] += space.substr(0, truespace - curLen);
	}
}


int Stages::GetLongest(vector<string>* lines) {
	int Big = -1;
	int size;
	for (string line : *lines) {
		size = line.size();
		Big = size > Big ? size : Big;
	}
	return Big;
}