#ifndef CASHIER_H
#define CASHIER_H

#include <iostream>
#include <string>
#include "Book.h"
#include "Menu.h"

using namespace std;

//not done.

class Cashier: public Menu
{
private:
	string bookName;
	double bookPrice;
	int quantity;
	const double taxrate = .0875;

public:
	void menu();
	
	void addToSale(int, vector<Book>&, vector<Book>&);
	void Checkout(vector<Book>);

};
#endif