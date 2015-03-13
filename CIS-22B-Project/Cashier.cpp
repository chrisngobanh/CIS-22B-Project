#define _CRT_SECURE_NO_WARNINGS
#include"Cashier.h"
#include <iomanip>
#include <cstring>
#include <vector>
#include "Inventory.h"
#include "Book.h"

using namespace std;

void Cashier::menu()
{

	bool found = false;
	Book book;
	Inventory inventory;
	vector<Book> booklist = inventory.readList(), temp;
	int choice = 0;
	char title[100];

	while (choice != 2)
	{
		system("CLS");

		found = false;

		time_t rawtime;
		struct tm * timeinfo;
		char current[80] = "";

		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(current, 80, "%m/%d/%y %I:%M%p", timeinfo);

		for (int i = 0; i < 80; i++)
			cout << current[i];
		cout << "Serendipity Booksellers\n";
		cout << "1. Add a book to the sale\n";
		cout << "2. Proceed to checkout\n";
		cout << "Enter your choice: ";
		cin >> choice;
		while (choice < 1 || choice > 2)
		{
			cout << "Please enter 1 or 2: ";
			cin >> choice;
		}

		if (choice == 1)
		{
			cout << "\nPlease enter the title of the book: ";
			cin.ignore();
			cin.getline(title, 100);

			for (unsigned int i = 0; i < booklist.size(); i++)
			{
				if (title == booklist[i].getTitle())
				{
					found = true;
					book = booklist[i];
				}
			}

			while (found != true)
			{
				cout << "Book not found. Please enter another title: \n";

				cin.getline(title, 100);

				for (unsigned int i = 0; i < booklist.size(); i++)
				{
					if (title == booklist[i].getTitle())
					{
						found = true;
						book = booklist[i];
					}
				}
			}

			temp = addToSale(book, temp);
		}
	}
//	Checkout(booklist);
}


vector<Book> Cashier::addToSale(Book book, vector<Book> temp)
{
	Inventory inventory;
	vector<Book> booklist = inventory.readList();
	unsigned int number, quantity;

	cout << "How many of '" << book.getTitle() << "' would you like to add?\n";
	cin >> number;

	quantity = book.getQuantity();	//something wrong here

	if (quantity == 0)
	{
		cout << "There are no more '" << book.getTitle() << "' left in the inventory.\n";
		return temp;
	}

	else
	{
		while (number > quantity)
		{
			cout << "There are less than " << number << " of '" << book.getTitle() << "' available in the inventory. \nPlease enter a different number: ";
			cin >> number;
		}

		for (unsigned int i = 0; i < booklist.size(); i++)
		{
			if (book.getTitle() == booklist[i].getTitle())
			{
				booklist[i].subStock(number);
			}
		}

		book.subStock(number);
		inventory.writeList(booklist);

		book.setStock(number);
		temp.push_back(book);

		return temp;
	}
}

/*	
}

void Cashier::Checkout(array of books from addBook);


	cout << "Serendipity Booksellers\n";
	cout << "Date: " << date;
	cout << "Qty" << setw(14) << "ISBN" << setw(20) << "Title" << setw(10) << "Price" << setw(10) << "Total\n";
	cout << "==================================================================================================\n";
	loop here to write the books out w/ same formatting, while looping should be adding prices to total
	display total at bottom, use the sales tax from the Cashier class to calculate tax and final price
	cout << "Thank you for shopping at Serendipity!";
*/