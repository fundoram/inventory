//Ryan Dalmas's Lab 5b Submission

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "LinkedSortedList.h"
#include "Inventory.h"

using namespace std;

int main() {

	LinkedSortedList<Inventory> List = LinkedSortedList<Inventory>();

	string filename = "inventory.txt";
	ifstream inFile;

	inFile.open(filename.c_str());
	//inFile.ignore();

	int _Quantity;
	double _PricePer;
	string _ProductName;

	//inFile >> _Quantity >> _PricePer >> _ProductName
	string Line;
	if (!inFile.fail()) {
		while (getline(inFile, Line)) {
			_Quantity = stoi(Line.substr(0, Line.find(" ")));
			Line = Line.substr(Line.find(" ") + 1);
			_PricePer = stod(Line.substr(0, Line.find(" ")));
			Line = Line.substr(Line.find(" ") + 1);
			_ProductName = Line;

			Inventory Temp = Inventory(_Quantity, _PricePer, _ProductName);
			//cout << Temp << endl;

			List.insertSorted(Temp);
		}
	}
	else {
		inFile.close();
		cout << filename << " Failed to Open.";
		system("pause");
		return 0;
	}
	cout << left;
	cout << setw(22) << "ProductName" << setw(15) << "PricePer" << setw(15) << "Quantity" << setw(15) << "ValueOnHand" << endl << endl;

	double Total = 0.0;
	for (int Counter = 1; Counter <= List.getLength(); Counter++) {
		cout << List.getEntry(Counter) << endl;
		Total += List.getEntry(Counter).value();
	}

	cout << setw(52) << "TotalValue --------------------------------------->" << Total << endl;

	inFile.close();

	cout << endl << endl << "Hit End Of File" << endl;
	system("Pause");
	return 0;
}