#define _CRT_SECURE_NO_WARNINGS
#include "Inventory.h"
#include "Book.h"
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

void Inventory::inventoryMenu()
{
	int inventoryChoice = 0;
//	bool validFunction;

	Inventory inventory;
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
			cout << "How would you like to look up a book?" << endl;

			break;


		case 2:;
		{
			inventory.addBook();

		}

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


void Inventory :: addBook()
{
	unsigned int isbn, quantity;
	char title[100], author[100], publisher[100];
	string dateAdded;
	double wholesaleCost = 0, retailPrice = 0;

	cout << "Please enter the following infornamtion." << endl;
	cout << "ISBN:" << endl;
	cin >> isbn;
	cout << "Title:" << endl;
	cin >> title;
	cout << "Author:" << endl;
	cin >> author;
	cout << "Publisher:" << endl;
	cin >> publisher;
	cout << "Date Added:" << endl;
	cin >> dateAdded;
	cout << "Quantity-On-Hand:" << endl;
	cin >> quantity;
	cout << "Wholesale Cost:" << endl;
	cin >> wholesaleCost;
	cout << "Retail Price:" << endl;
	cin >> retailPrice;
	Book book(isbn, title, author, publisher, quantity, wholesaleCost);
}