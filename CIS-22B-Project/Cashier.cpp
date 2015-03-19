#define _CRT_SECURE_NO_WARNINGS
#include"Cashier.h"
#include <iomanip>
#include <cstring>
#include <vector>
#include "Inventory.h"
#include "Book.h"

using namespace std;

// main cashier menu tree
void Cashier::menu()
{
	Book book;

	vector<Book> booklist = readList();
	int choice = 0, n = 0;
	do
	{
		system("CLS");

		time_t rawtime;
		struct tm * timeinfo;
		char current[80] = "";

		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(current, 80, "%m/%d/%Y %I:%M%p", timeinfo);
		puts(current);

		cout << "Serendipity Booksellers\n";
		cout << "Cashier Menu - Main\n\n";
		cout << "What would you like to do?\n";
		cout << "1. Add a book to the sale\n";
		cout << "2. Proceed to checkout\n";
		cout << "3. Return to main menu\n";
		cout << "Enter your choice: ";
		cin >> choice;
		if (!cin){
			cin.clear();
			choice = 0; // defaults choice to 0 if user attempts to enter a non-number
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << endl;

		switch (choice){

		case 1:
		{
			int choice;
			bool validChoice = false;
			do{
				system("CLS");

				time(&rawtime);
				timeinfo = localtime(&rawtime);
				strftime(current, 80, "%m/%d/%Y %I:%M%p", timeinfo);
				puts(current);

				cout << "Serendipity Booksellers" << endl << "Cashier Menu - Add Book" << endl << endl; // allows user to add books to shopping cart
				cout << "What book would you like to add to sale ? Search the book by" << endl;
				cout << "1. ISBN" << endl;
				cout << "2. Title" << endl;
				cout << "3. Author" << endl;
				cout << "4. Publisher" << endl;
				cout << "5. Return to the Cashier Menu." << endl;
				cout << "Enter your Choice: ";
				cin >> choice;
				if (!cin){
					cin.clear();
					choice = 0; // defaults choice to 0 if user attempts to enter a non-number
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				cout << endl;

				switch (choice){
				case 1:
				{
					char isbn[13];
					cout << "ISBN: ";
					cin.ignore();
					cin.getline(isbn, 13);
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					try
					{
						vector<int> searchResults = lookUpBookISBN(isbn, booklist);
						cout << "Which book do you want to add to sale? Or enter 0 to cancel: ";

						unsigned int bookChoice;
						validChoice = false;
						while (validChoice != true){
							cin >> bookChoice;
							if (!cin){
								cin.clear();
								bookChoice = searchResults.size() + 1;
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
							}
							if (bookChoice > searchResults.size()) cout << "Invalid selection. Please try again: ";
							else validChoice = true;
						}

						cout << endl;
						if (bookChoice != 0)
						{
							try
							{
								addToSale(searchResults[bookChoice - 1], booklist, salelist);
							}
							catch (char* error)
							{
								cout << endl << error;
							}
							cout << endl;
							system("pause");

						}
						cout << endl;
					}
					catch (char* error)
					{
						cout << error << endl;
					}
					break;
				}
				case 2:
				{
					char title[100];
					cout << "Title: ";
					cin.ignore();
					cin.getline(title, 100);
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					try
					{
						vector<int> searchResults = lookUpBookTitle(title, booklist);
						cout << "Which book do you want to add to sale? Or enter 0 to cancel: ";

						unsigned int bookChoice;
						validChoice = false;
						while (validChoice != true){
							cin >> bookChoice;
							if (!cin){
								cin.clear();
								bookChoice = searchResults.size() + 1;
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
							}
							if (bookChoice > searchResults.size()) cout << "Invalid selection. Please try again: ";
							else validChoice = true;
						}

						cout << endl;
						if (bookChoice != 0)
						{
							try
							{
								addToSale(searchResults[bookChoice - 1], booklist, salelist);
							}
							catch (char* error)
							{
								cout << endl << error;
							}
							cout << endl;
							system("pause");

						}
						cout << endl;
					}
					catch (char* error)
					{
						cout << error << endl;
					}
					break;
				}
				case 3:
				{
					char author[100];
					cout << "Author: ";
					cin.ignore();
					cin.getline(author, 100);
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					try
					{
						vector<int> searchResults = lookUpBookAuthor(author, booklist);
						cout << "Which book do you want to add to sale? Or enter 0 to cancel: ";

						unsigned int bookChoice;
						validChoice = false;
						while (validChoice != true){
							cin >> bookChoice;
							if (!cin){
								cin.clear();
								bookChoice = searchResults.size() + 1;
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
							}
							if (bookChoice > searchResults.size()) cout << "Invalid selection. Please try again: ";
							else validChoice = true;
						}

						cout << endl;
						if (bookChoice != 0)
						{
							try
							{
								addToSale(searchResults[bookChoice - 1], booklist, salelist);
							}
							catch (char* error)
							{
								cout << endl << error;
							}

							cout << endl;
							system("pause");
						}

						cout << endl;
					}
					catch (char* error)
					{
						cout << error << endl;
					}
					break;
				}
				case 4:
				{
					char publisher[100];
					cout << "Publisher: ";
					cin.ignore();
					cin.getline(publisher, 100);
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					try
					{
						vector<int> searchResults = lookUpBookPublisher(publisher, booklist);
						cout << "Which book do you want to add to sale? Or enter 0 to cancel: ";

						unsigned int bookChoice;
						validChoice = false;
						while (validChoice != true){
							cin >> bookChoice;
							if (!cin){
								cin.clear();
								bookChoice = searchResults.size() + 1;
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
							}
							if (bookChoice > searchResults.size()) cout << "Invalid selection. Please try again: ";
							else validChoice = true;
						}

						cout << endl;
						if (bookChoice != 0)
						{
							try
							{
								addToSale(searchResults[bookChoice - 1], booklist, salelist);
							}
							catch (char* error)
							{
								cout << endl << error;
							}

							cout << endl;
							system("pause");
						}

						cout << endl;
					}
					catch (char* error)
					{
						cout << error << endl;
					}
					break;
				}
				case 5:
					break;
				default:
					cout << "You did not enter a valid option (1, 2, 3, 4, or 5). Please try again." << endl;
					system("pause");
				}
				break;
			} while (choice != 5);
			break;
		}
		case 2:
		{
			Checkout(salelist); // takes user to the checkout screen
			salelist.clear(); // empties shopping cart
			writeList(booklist); // saves altered booklist to inventory now that checkout is complete
			break;
		}
		case 3:
			salelist.clear(); // empties shopping cart, then exist cashier menu
			break;
		default:
			cout << "You did not enter a valid option (1, 2, or 3). Please try again." << endl;
			system("pause");
		}
		
		
	}while (choice != 3);
}


void Cashier::addToSale(int location, vector<Book>& booklist, vector<Book>& salelist)
{
	int number = -1, quantity = 0;
	quantity = booklist[location].getQuantity(); // sets local variable quantity to how many of a book is currently on hand


	if (quantity == 0) // no books left
	{
		throw "There are no more copies of that book left in the inventory.";
	}
	else
	{
		cout << "How many copies of '" << booklist[location].getTitle() << "' would you like to add to the cart?\n";

		while (number < 0)
		{
			cin >> number; // user informs program how many will be purchased
			while (!cin){ // if user attempts to enter a non-number
				cin.clear();
				cout << "Invalid input. Please try again: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> number;
			}

			if (number > quantity){ // asks if user simply wants to add the whole stock if user attempts to add to cart more than is available in stock
				if (quantity == 1) cout << endl << "There is only " << quantity << " book left in stock." << endl << "Would you like to add it to the cart anyway?" <<
					endl << "Enter 1 for yes, or 0 for no: ";
				else cout << endl << "There are only " << quantity << " books left in stock." << endl << "Would you like to add them all to the cart anyway?" <<
					endl << "Enter 1 for yes, or 0 for no: ";
				int confirmation;
				bool validChoice = false;
				while (validChoice != true){
					cin >> confirmation;
					if (!cin){
						cin.clear();
						confirmation = -1;
						// defaults choice to -1 if user attemts to enter a non-number
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					if (confirmation < 0 || confirmation > 1) cout << "Invalid choice. Please try again: ";
					// demands that user input only 0 or 1 to continue
					else validChoice = true;
				}
				if (confirmation == 1){
					number = quantity;
				}
				else if (confirmation == 0){
					number = -1;
					cout << "\nHow many copies of '" << booklist[location].getTitle() << "' would you like to add to the cart?\n";
					cin.clear();
					cin.ignore();
				}
			}
			else if (number < 0){
				cout << "\nYou can not add a negative number of books to the cart.\nPlease enter a different number: ";
				cin.clear();
				cin.ignore();
			}
		}

		salelist.push_back(booklist[location]);

		for (unsigned int i = 0; i < salelist.size(); i++)
		{
			if (salelist[i].getISBN() == booklist[location].getISBN())
				salelist[i].sQuantity = number;
		}

		booklist[location].sQuantity = (quantity - number);
		
		if (number == 1) cout << endl << number << " copy of " << booklist[location].getTitle() << " added to cart." << endl;
		else cout << endl << number << " copies of " << booklist[location].getTitle() << " added to cart." << endl;
	}
}

void Cashier::subFromSale(int location, vector<Book>& booklist, vector<Book>& salelist)
{
	unsigned int number = 0, quantity = 0;
	quantity = salelist[location].getQuantity();

	cout << "How many of '" << salelist[location].getTitle() << "' would you like to remove?\n";
	cin >> number;

	if (number > quantity)
	{
		number = quantity;
	}

	for (unsigned int i = 0; i < booklist.size(); i++)
	{
		if (salelist[location].getISBN() == booklist[i].getISBN())
			booklist[i].sQuantity += number;
	}

	salelist[location].sQuantity -= number;
	if (salelist[location].sQuantity == 0) salelist.erase(salelist.begin() + location);

	writeList(booklist);
}

void Cashier::Checkout(vector<Book> salelist)
{
	double total = 0;

	time_t rawtime;
	struct tm * timeinfo;
	char current[80] = "";

	system("cls");

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(current, 80, "%m/%d/%y %I:%M%p", timeinfo);
	for (int i = 0; i < 80; i++)
		cout << current[i];

	cout << "\nSerendipity Booksellers\nCashier Menu - Checkout\n"; // prints out a reciept for user

	cout << setw(4) << "Qty" << setw(16) << "ISBN" << setw(30) << "Title" << setw(10) << "Price" << setw(10) << "Total";
	cout << "\n========================================================================\n";

	for (unsigned int i = 0; i < salelist.size(); i++)
	{
		total += (salelist[i].getRetail()*salelist[i].getQuantity());
		cout << setw(4) << salelist[i].getQuantity() << setw(16) << salelist[i].getISBN();
		cout << setw(30) << salelist[i].getTitle() << "     $" << setw(10) << setprecision(2) << fixed << left << salelist[i].getRetail();
		cout << "$" << setw(10) << setprecision(2) << left << (salelist[i].getRetail()*salelist[i].getQuantity()) << endl;
	}

	cout << endl << "Subtotal: " << setprecision(2)  << total << endl;
	cout << "Tax: " << setprecision(2) << (taxrate*total);
	cout << endl << "Total: " << setprecision(2) << (total + (taxrate*total)) << endl;
	cout << endl << "Thank you for shopping at Serendipity!\n\n";

	system("pause");
}