/*
Lab5b
Matthew Fundora
Professor Biehl
Data Structres
11/24/1018
*/

#ifndef INVENTORY
#define INVENTORY

#include "Inventory.h"
#include <string>
#include <iomanip>

using namespace std;

Inventory::Inventory() {

}

Inventory::Inventory(const int _Q, const double _P, const string _PN) {
	Quantity = _Q;
	pricePer = _P;
	ProductName = _PN;
}

double Inventory::value() {
	return Quantity * pricePer;
}

bool operator==(const Inventory first, const Inventory second) {
	return first.Quantity == second.Quantity && first.pricePer == second.pricePer && first.ProductName == second.ProductName;
}

bool operator!=(const Inventory first, const Inventory second) {
	return first.Quantity || second.Quantity || first.pricePer != second.pricePer || first.ProductName != second.ProductName;
}

bool operator>(const Inventory first, const Inventory second) {
	return first.ProductName > second.ProductName;
}

ostream& operator<<(ostream& os, Inventory obj) {
	return os << setw(22) << obj.ProductName << setw(15) << obj.pricePer << setw(15) << obj.Quantity << setw(15) << fixed << setprecision(2) << obj.value();
}


#endif