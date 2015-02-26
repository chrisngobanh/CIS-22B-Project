#define _CRT_SECURE_NO_WARNINGS
#include "Inventory.h"
#include <iostream>
using namespace std;

Inventory::Inventory(unsigned int isbn, string title, string author, string publisher, unsigned int quantity, double wholesale)
{
	sISBN = isbn;
	sTitle = title;
	sAuthor = author;
	sPublisher = publisher;
	sQuantity = quantity;
	sWholesale = wholesale;
}

void Inventory::setPrice(double retail)
{
	sRetail = retail;
}

void Inventory::addStock(unsigned int addition)
{
	sQuantity += addition;
}

void Inventory::subStock(unsigned int subtraction)
{
	sQuantity -= subtraction;
}

Inventory::~Inventory()
{
}
void Inventory::inventoryMenu()
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