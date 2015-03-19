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
		cout << "1. Add a Book to Cart\n";
		cout << "2. Edit Cart\n";
		cout << "3. Proceed to Checkout\n";
		cout << "4. Return to Main Menu\n";
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
				cout << "What book would you like to add to sale? Search the book by" << endl;
				cout << "1. ISBN" << endl;
				cout << "2. Title" << endl;
				cout << "3. Author" << endl;
				cout << "4. Publisher" << endl;
				cout << "5. Return to Previous Menu" << endl;
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
								addToSale(searchResults[bookChoice - 1], booklist);
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
								addToSale(searchResults[bookChoice - 1], booklist);
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
								addToSale(searchResults[bookChoice - 1], booklist);
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
								addToSale(searchResults[bookChoice - 1], booklist);
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
			} while (choice != 5);
			break;
		}
		case 2:
		{
			if (salelist.size() == 0){
				cout << "Your shopping cart is empty!" << endl;
			}
			else{
				system("CLS");

				time(&rawtime);
				timeinfo = localtime(&rawtime);
				strftime(current, 80, "%m/%d/%Y %I:%M%p", timeinfo);
				puts(current);

				cout << "Serendipity Booksellers" << endl << "Cashier Menu - Edit Cart" << endl << endl; // allows user to remove books from shopping cart
				cout << "Currently in your cart:" << endl << endl;

				for (unsigned int i = 0; i < salelist.size(); i++){
					printf("%d.\n", i+1);
					cout << salelist[i].getTitle() << endl << cartQuantity[i] << " in cart" << endl << "$" << salelist[i].getRetail() << " each" << endl << endl;
				}
				
				cout << "Which book do you want to remove some number of from the cart?\nOr enter 0 to return to previous menu: ";

				unsigned int bookChoice;
				bool validChoice = false;
				while (validChoice != true){
					cin >> bookChoice;
					if (!cin){
						cin.clear();
						bookChoice = salelist.size() + 1;
						// defaults choice to more than array size if user attempts to input a non-unsigned int
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					if (bookChoice > salelist.size()) cout << "Invalid selection. Please try again: ";
					else validChoice = true;
				}

				cout << endl;
				if (bookChoice != 0){
					subFromSale(bookChoice - 1, booklist);
					cout << endl;
				}
			}
			system("pause");
			break;
		}
		case 3:
		{
			if (salelist.size() == 0){
				cout << "Your shopping cart is empty!" << endl;
				system("pause");
			}
			else{
				Checkout(); // takes user to the checkout screen
				salelist.clear(); // empties shopping cart
				writeList(booklist); // saves altered booklist to inventory now that checkout is complete
			}
			break;
		}
		case 4:
			if (salelist.size() != 0){
				cout << "You still have books in your shopping cart! Are you sure you want to quit?" << endl << "Enter 1 for yes, or 0 for no: ";
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

				if (confirmation == 1) salelist.clear(); // empties shopping cart before exiting cashier menu
				else choice = 0;
			}
			break;
		default:
			cout << "You did not enter a valid option (1, 2, or 3). Please try again." << endl;
			system("pause");
		}
	} while (choice != 4);
}

// allows user to add a certain number of a chosen book to the cart
void Cashier::addToSale(int location, vector<Book>& booklist)
{
	int number = -1, quantity = 0;
	quantity = booklist[location].getQuantity(); // sets local variable quantity to how many of a book is currently on hand


	if (quantity == 0) // no books left
	{
		throw "There are no more copies of that book left in the inventory.";
	}
	else
	{
		cout << "How many copies of\n'" << booklist[location].getTitle() << "'\nwould you like to add to the cart? ";

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
					cout << "\nHow many copies of '" << booklist[location].getTitle() << "' would you like to add to the cart? ";
					cin.clear();
					cin.ignore();
				}
			}
			else if (number < 0){ // when user attempts to add a negative number of books to the cart
				cout << "\nYou can not add a negative number of books to the cart.\nPlease enter a different number: ";
				cin.clear();
				cin.ignore();
			}
		}

		int inCart = -1;
		for (unsigned int i = 0; i < salelist.size(); i++){
			if (strcmp(salelist[i].getISBN(), booklist[location].getISBN()) == 0) inCart = i;
		}
		if (inCart < 0){
			salelist.push_back(booklist[location]); // notes which new book was added to the cart
			cartQuantity.push_back(number);
			bookLocation.push_back(location);
		}
		else cartQuantity[inCart] += number;

		booklist[location].sQuantity = (quantity - number);
		
		if (number == 1) cout << endl << "Added to cart: " <<  number << " copy of " << booklist[location].getTitle();
		else cout << endl << "Added to cart: " <<  number << " copies of " << booklist[location].getTitle();
	}
}

void Cashier::subFromSale(int location, vector<Book>& booklist)
{
	int number = -1, quantity = cartQuantity[location];

	cout << "How many of '" << salelist[location].getTitle() << "' would you like to remove?\n";
	while (number < 0)
	{
		cin >> number; // user informs program how many will be removed
		while (!cin){ // if user attempts to enter a non-number
			cin.clear();
			cout << "Invalid input. Please try again: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> number;
		}

		if (number >= quantity) number = quantity;
		else if (number < 0){ // when user attempts to remove a negative number of books from the cart
			cout << "\nPlease enter a positive number: ";
			cin.clear();
			cin.ignore();
		}
	}

	booklist[bookLocation[location]].sQuantity += number; // adds back the number of books to inventory list from cart
	cartQuantity[location] -= number; // reduces the number of books in cart

	if (number == 1) cout << endl << "Removed from cart: " << number << " copy of " << salelist[location].getTitle();
	else cout << endl << "Removed from cart: " << number << " copies of " << salelist[location].getTitle();

	if (cartQuantity[location] == 0){ // removes item from cart completely if no more of it is in cart
		salelist.erase(salelist.begin() + location);
		bookLocation.erase(bookLocation.begin() + location);
		cartQuantity.erase(cartQuantity.begin() + location);
	}
}

void Cashier::Checkout()
{
	double total = 0;

	time_t rawtime;
	struct tm * timeinfo;
	char current[80] = "";

	system("CLS");

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(current, 80, "%m/%d/%Y %I:%M%p", timeinfo);
	for (int i = 0; i < 80; i++)
		cout << current[i];

	cout << "Serendipity Booksellers\nCashier Menu - Checkout\n\n"; // prints out a reciept for user
	cout << fixed << right;
	cout << setw(4) << "Qty" << setw(16) << "ISBN" << setw(30) << "Title" << setw(10) << "Price" << setw(10) << "Total";
	cout << "\n========================================================================\n";

	for (unsigned int i = 0; i < salelist.size(); i++)
	{
		total += (salelist[i].getRetail()*cartQuantity[i]);
		cout << setw(4) << cartQuantity[i] << setw(16) << salelist[i].getISBN();
		cout << setw(30) << salelist[i].getTitle() << "     " << "$" << setw(9) << setprecision(2) << fixed << left << salelist[i].getRetail();
		cout << "$" << setw(10) << setprecision(2) << left << (salelist[i].getRetail()*salelist[i].getQuantity()) << endl;
	}

	cout << endl << "Subtotal:\t$" << setprecision(2)  << total << endl;
	cout << "Tax:\t\t$" << setprecision(2) << (taxrate*total);
	cout << endl << "Total:\t\t$" << setprecision(2) << (total + (taxrate*total)) << endl;
	cout << endl << "Thank you for shopping at Serendipity!\n\n";

	system("pause");
}