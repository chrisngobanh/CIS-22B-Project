#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include"Inventory.h"
#include<string>
using namespace std;

int main()
{

	int choice;
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

		if (choice == 1)
		//open cashier screen
		else if (choice == 2)
		//open inventory database screen
		else if (choice == 3)
		//open report screen
		else if (choice == 4)
		return 0;
	}

	return 0;
}