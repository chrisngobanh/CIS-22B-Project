#define _CRT_SECURE_NO_WARNINGS
#include"Cashier.h"
#include<iomanip>
#include<cstring>

using namespace std;

void Cashier::menu()		//Not done yet, still need working Inventory Module before we can search for a book/remove book from the inventory file.
{
	system("CLS");

	//declare array/vector of book objects to add to w/ addBook function
	int choice = 0;
	char title[100];
	char date[9];

	_strdate(date);

	while (choice != 2)
	{
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
			//			addBook(title);
		}
	}
	//Checkout(array of books added to by addBook function above);
}

/*
void Cashier::addBook(char title[])
{
	
	for (int i = 0; i < strlen(title); i++);
	{
	}

		need to be able to compare with each element of booklist array, don't have booklist in array form yet
		IF we find the book in the file, then might still need to check the quantity of that book? If quantity can be 0 without deleting the book's entry in the file?
		need to ask how many of the book the customer wants to purchase
		if we don't have that many ask again
		remove that many of the book from the book obj, possibly delete that obj from the array if quant goes to 0?
		rewrite file after done editing the booklist array
		add book's info to another array of book objects which is sent to checkout eventually
	
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