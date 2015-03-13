#ifndef CASHIER_H
#define CASHIER_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

//not done.

class Cashier
{
private:
	string bookName;
	double bookPrice;
	int quantity;
	const double taxrate = .0875;

public:
	void menu();
	
	vector<Book> addToSale(char[], vector<Book>, unsigned int);
//	void Checkout(vector<Book>)

};
#endif