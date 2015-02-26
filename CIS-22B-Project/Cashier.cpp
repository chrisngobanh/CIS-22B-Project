#define _CRT_SECURE_NO_WARNINGS
#include "Cashier.h"
#include<iostream>
#include<iomanip>
#include "time.h"

using namespace std;

void Cashier::menu()
{
	system("CLS");
	char date[9];
	_strdate(date);

	cout << "Serendipity Booksellers\n";
	cout << "Date: " << date;
	cout << "Quantity";
	// << ;

}