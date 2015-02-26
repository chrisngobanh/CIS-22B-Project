#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include"Inventory.h"
#include<string>
using namespace std;

int main()
{

	char choice;
	while (choice != 4)
	{
		cout << "Serendipity Booksellers\n";
		cout << "Main Menu\n\n";
		cout << "1. Cashier Module\n";
		cout << "2. Inventory Database Module\n";
		cout << "3. Report Module\n";
		cout << "4. Exit\n\n";
		cout << "Enter your choice: ";
		cin >> choice;

		while (choice < 1 || choice > 4)
		{
			cout << "Enter 1 - 4: ";
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
			//open cashier module
			break;
		case 2:
			//open inventory module
			break;
		case 3:
			//open report module
			break;
		case 4:
			break;
		}
	}

	return 0;
}