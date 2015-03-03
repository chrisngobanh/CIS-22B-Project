#define _CRT_SECURE_NO_WARNINGS
#include "Inventory.h"
using namespace std;

void Inventory::setPrice(Book target, double retail)
{
	target.setPrice(retail);
}

void Inventory::addStock(Book target, unsigned int addition)
{
	target.addStock(addition);
}

void Inventory::subStock(Book target, unsigned int subtraction)
{
	target.subStock(subtraction);
}

void inventoryMenu()
{
	int inventoryChoice = 0;
	bool validFunction;
	do
	{
		system("CLS");

		cout << "Serendipity Booksellers Inventory Database" << endl;

		cout << "1. Look Up a Book" << endl;

		cout << "2. Add a Book" << endl;

		cout << "3. Edit a Book's Record" << endl;

		cout << "4. Delete a Book" << endl;

		cout << "5. Return to the Main Menu" << endl << endl;
		cout << "Enter your Choice: " << endl << endl;

		cin >> inventoryChoice;


		switch (inventoryChoice)
		{

		case 1:;


			break;


		case 2:;




			break;


		case 3:;



			break;


		case 4:;





			break;


		case 5:


			break;

		default: cout << "You did not enter a valid option 1, 2, 3, 4, 5. Please try again." << endl;



		}
	} while (inventoryChoice != 5);
}

Inventory::~Inventory()
{
}
