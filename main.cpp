#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include"Cashier.h"
#include"Inventory.h"
#include<string>
#include<fstream>
using namespace std;

int main()
{
	Cashier cashier;
	Inventory inventory;
	int choice=0;
	fstream bookList;

	bookList.open("booklist.txt", ios::in);
	bookList.open("booklist.txt", ios::out);

	while (choice != 4)
	{
		system("CLS");
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
			cashier.menu();
			//open cashier module
			break;
		case 2:
			inventory.inventoryMenu();
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