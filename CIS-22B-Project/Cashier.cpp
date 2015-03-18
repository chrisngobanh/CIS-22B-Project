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
	Book book;
	Inventory inventory;
	vector<Book> booklist = inventory.readList(), salelist;
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

		for (int i = 0; i < 80; i++)
			cout << current[i];

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
			choice = 0;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (choice){

		case 1:
		{
			int choice;
			bool validChoice = false;
			do{
				system("CLS");
				cout << "Serendipity Booksellers" << endl << "Cashier Menu - Add Book" << endl << endl;
				cout << "What book would you like to add to sale ? Search the book by" << endl;
				cout << "1. ISBN" << endl;
				cout << "2. Title" << endl;
				cout << "3. Author" << endl;
				cout << "4. Publisher" << endl;
				cout << "5. Return to the Cashier Menu." << endl;
				cout << "Enter your Choice: ";
				cin >> choice;
				cout << endl;

				switch (choice){
				case 1:
				{
					char isbn[13];
					cout << "ISBN: ";
					cin.ignore();
					cin.getline(isbn, 13, '\n');

					vector<int> searchResults = inventory.lookUpBookISBN(isbn, booklist);
					if (searchResults.size() != 0){
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
								cout << endl << "Error: " << error;
							}
							cout << endl;
							system("pause");

						}
						cout << endl;
					}
					else{
						cout << "No books found using search criteria." << endl;
						system("pause");
					}
					break;
				}
				case 2:
				{
					char title[100];
					cout << "Title: ";
					cin.ignore();
					cin.getline(title, 100);
					vector<int> searchResults = inventory.lookUpBookTitle(title, booklist);
					if (searchResults.size() != 0){
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
								cout << endl << "Error: " << error;
							}
							cout << endl;
							system("pause");

						}
						cout << endl;
					}
					else{
						cout << "No books found using search criteria." << endl;
						system("pause");
					}
					break;
				}
				case 3:
				{
					char author[100];
					cout << "Author: ";
					cin.ignore();
					cin.getline(author, 100);
					vector<int> searchResults = inventory.lookUpBookAuthor(author, booklist);
					if (searchResults.size() != 0){
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
								cout << endl << "Error: " << error;
							}

							cout << endl;
							system("pause");
						}
							
						cout << endl;
					}
					else{
						cout << "No books found using search criteria." << endl;
						system("pause");
					}
					break;
				}
				case 4:
				{
					char publisher[100];
					cout << "Publisher: ";
					cin.ignore();
					cin.getline(publisher, 100);
					vector<int> searchResults = inventory.lookUpBookPublisher(publisher, booklist);
					if (searchResults.size() != 0){
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
								cout << endl << "Error: " << error;
							}

							cout << endl;
							system("pause");
						}

						cout << endl;
					}
					else{
						cout << "No books found using search criteria." << endl;
						system("pause");
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
			Checkout(salelist);
			break;
		}
		case 3:
			break;
		default:
			cout << "You did not enter a valid option (1, 2, or 3). Please try again.";
			system("pause");
		}
		
		
	}while (choice != 3);
}


void Cashier::addToSale(int location, vector<Book>& booklist, vector<Book>& salelist)
{
	Inventory inventory;
	unsigned int number = 0, quantity = 0;
	quantity = booklist[location].getQuantity();


	if (quantity == 0)
	{
		throw "There are no more copies of that book left in the inventory.";
	}
	else
	{
		cout << "How many of '" << booklist[location].getTitle() << "' would you like to add?\n";
		cin >> number;

		while (number > quantity)
		{
			cout << "There are less than " << number << " of '" << booklist[location].getTitle() << "' available in the inventory. \nPlease enter a different number: ";
			cin.ignore();
			cin >> number;
		}

		salelist.push_back(booklist[location]);

		for (unsigned int i = 0; i < salelist.size(); i++)
		{
			if (salelist[i].getISBN() == booklist[location].getISBN())
				salelist[i].setQuantity(number);
		}

		booklist[location].setQuantity(quantity - number);

		inventory.writeList(booklist);
	}
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

	cout << "\nSerendipity Booksellers\nCashier Menu - Checkout\n";

	cout << setw(4) << "Qty" << setw(16) << "ISBN" << setw(30) << "Title" << setw(10) << "Price" << setw(10) << "Total";
	cout << "\n========================================================================\n";

	for (unsigned int i = 0; i < salelist.size(); i++)
	{
		total += (salelist[i].getRetail()*salelist[i].getQuantity());
		cout << setw(4) << salelist[i].getQuantity() << setw(16) << salelist[i].getISBN();
		cout << setw(30) << salelist[i].getTitle() << "    $" << setw(10) << setprecision(2) << fixed << left << salelist[i].getRetail();
		cout << "    $" << setw(10) << setprecision(2) << left << (salelist[i].getRetail()*salelist[i].getQuantity()) << endl;
	}

	cout << endl << "Subtotal: " << setprecision(2)  << total << endl;
	cout << "Tax: " << setprecision(2) << (taxrate*total);
	cout << endl << "Total: " << setprecision(2) << (total + (taxrate*total)) << endl;
	cout << endl << "Thank you for shopping at Serendipity!\n\n";

	system("pause");
}