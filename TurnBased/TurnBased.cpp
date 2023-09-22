#include "Testing.h"
#include "Entity.h"
#include "Fight.h"
int main()
{
	//
	int col = 3;
	int row = 10;
	int num;
	/*for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			num = (y + (x * (col)));
			cout << num << " ";
		}
		cout << endl;
	}
	*/
	TestGeneration(col, row);
	/*cout << endl << endl;
	TestGeneration(3, 10);
	cout << endl << endl;*/
}
	