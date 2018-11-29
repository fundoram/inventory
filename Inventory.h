/*
Lab5b
Matthew Fundora
Professor Biehl
Data Structres
11/24/1018
*/


#include <string>

using namespace std;

class Inventory {
private:
	int Quantity;
	double pricePer;
	string ProductName;
public:
	Inventory();
	Inventory(const int q, const double pp, const string pn);
	double value();
	friend bool operator==(const Inventory first, const Inventory second);
	friend bool operator!=(const Inventory first, const Inventory second);
	friend bool operator>(const Inventory first, const Inventory second);
	friend ostream& operator<<(ostream& os, Inventory obj);
}; 
