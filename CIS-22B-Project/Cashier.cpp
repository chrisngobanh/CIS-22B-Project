#define _CRT_SECURE_NO_WARNINGS
#include "Cashier.h"
#include<iostream>
#include "time.h"

using namespace std;

void Cashier::menu()
{
	char date[9];
	_strdate(date);

	cout << "Serendipity Booksellers\n";
	cout << "Date: " << date;
	cout << "Quantity";
	cout << "2. Inventory Database Module\n";
	cout << "3. Report Module\n";
	cout << "4. Exit\n\n";
	cout << "Enter your choice: ";

}