#ifndef CASHIER_H
#define CASHIER_H

#include <iostream>
#include <string>
#include "Book.h"
#include "Menu.h"
#include "Inventory.h"

using namespace std;

class Cashier: public Inventory
{
private:
	int quantity;
	const double taxrate = .0875;
	vector<Book> salelist;

public:
	void menu();
	void addToSale(int, vector<Book>&, vector<Book>&);
	void subFromSale(int, vector<Book>&, vector<Book>&);
	void Checkout(vector<Book>);

};
#endif