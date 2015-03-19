#define _CRT_SECURE_NO_WARNINGS

#include "Reports.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// main reports menu tree
void Report::menu()
{
	int choice = 0;

	while (choice != 7)
	{
		system("CLS");

		time_t menutime;
		struct tm * timeInfo;
		char current[80] = "";
		time(&menutime);
		timeInfo = localtime(&menutime);
		strftime(current, 80, "%m/%d/%Y %I:%M%p", timeInfo);
		puts(current);

		cout << "Serendipity Booksellers\n";
		cout << "Reports Menu - Main \n\n";
		cout << "What would you like to do?\n";
		cout << "1. Inventory Listing\n";
		cout << "2. Inventory Wholesale Listing\n";
		cout << "3. Inventory Retail Value\n";
		cout << "4. Listing by Quantity\n";
		cout << "5. Listing by Cost\n";
		cout << "6. Listing by Age\n";
		cout << "7. Return to Main Menu\n";
		cout << "Enter your choice: " << endl;	// ask for choice

		cin >> choice;	// get choice

		if (!cin){
			cin.clear();
			choice = 0; // defaults choice to 0 if user attempts to enter a non-number
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		cout << endl;

		vector<Book> booklist = readList();	// uses function inherited from parent Inventory class
		sortByTitle(booklist);	// sorts booklist by title for default use

		system("CLS");

		switch (choice){
		case 1:
		{
			time(&menutime);
			timeInfo = localtime(&menutime);
			strftime(current, 80, "%m/%d/%Y %I:%M%p", timeInfo);
			puts(current);

			cout << "Serendipity Booksellers" << endl;
			cout << "Reports Menu - Inventory Listing" << endl << endl; // displays inventory sorted by name (as mentioned before to be default)
			cout << "----------------------------------------------" << endl << endl;

			printList(booklist);
			system("pause");
			break;
		}
		case 2:
		{
			time(&menutime);
			timeInfo = localtime(&menutime);
			strftime(current, 80, "%m/%d/%Y %I:%M%p", timeInfo);
			puts(current);

			cout << "Serendipity Booksellers" << endl;
			cout << "Reports Menu - Inventory Wholesale Listing" << endl << endl; // displays inventory in a chart calculating wholesale values

			cout << setw(30) << left << "Title";
			cout << setw(10) << left << "Quantity";
			cout << setw(11) << left << "Wholesale";
			cout << setw(5) << left << "Cost";

			cout << endl;

			cout << "---------------------------------------------------------" << endl;
			double total = 0;

			for (unsigned int i = 0; i < booklist.size(); i++)	// prints each book's information
			{
				double cost = booklist[i].getWholesale() * booklist[i].getQuantity(); // calculates the total wholesale cost of a book

				string tmp = booklist[i].getTitle();

				if (tmp.length() > 28) {
					tmp = tmp.substr(0, 25) + "..."; // truncates a book title and appends an ellipses at the end
				}

				cout << setprecision(2) << fixed; // forces all floats and doubles to output with 2 decimal places
				cout << setw(30) << left << tmp; // prints book's name
				cout << setw(10) << left << booklist[i].getQuantity(); // prints book quantity
				cout << "$" << setw(10) << left << setprecision(2) << fixed << booklist[i].getWholesale(); // prints book wholesale cost
				cout << "$" << setw(5) << left << cost; // prints total wholesale cost of a book
				cout << endl;

				total += cost;	// adds each book's wholesale cost to a running total
			}
			cout << "---------------------------------------------------------" << endl;
			cout << setw(33) << left << "" << "Total Cost: $" << total << endl << endl;	// prints total inventory wholesale cost

			system("pause");
			break;

		}
		case 3:
		{
			time(&menutime);
			timeInfo = localtime(&menutime);
			strftime(current, 80, "%m/%d/%Y %I:%M%p", timeInfo);
			puts(current);

			cout << "Serendipity Booksellers" << endl;
			cout << "Reports Menu - Inventory Retail Listing" << endl << endl; // displays inventory in a chart calculating retail values
					
			cout << setw(30) << left << "Title";
			cout << setw(10) << left << "Quantity";
			cout << setw(11) << left << "Retail";
			cout << setw(5) << left << "Cost";

			cout << endl;

			cout << "---------------------------------------------------------" << endl;

			double total = 0;

			for (unsigned int i = 0; i < booklist.size(); i++)	// prints each book's information
			{
				double cost = booklist[i].getRetail() * booklist[i].getQuantity(); // calculates the total retail cost of a book

				string tmp = booklist[i].getTitle();

				if (tmp.length() > 28) {
					tmp = tmp.substr(0, 25) + "..."; // truncates a book title and appends an ellipses at the end
				}

				cout << setprecision(2) << fixed; // forces all floats and doubles to output with 2 decimal places
				cout << setw(30) << left << tmp; // prints book's name
				cout << setw(10) << left << booklist[i].getQuantity(); // prints book's quantity
				cout << "$" << setw(10) << left << setprecision(2) << fixed << booklist[i].getRetail(); // prints book's retail cost
				cout << "$" << setw(5) << left << cost; // prints total retail cost of a book
				cout << endl;

				total += cost;	// adds each book's retail cost to a running total
			}
			cout << "---------------------------------------------------------" << endl;
			cout << setw(33) << left << "" << "Total Cost: $" << total << endl << endl; // prints total inventory retail cost

			system("pause");
			break;
		}
		case 4:
		{
			time(&menutime);
			timeInfo = localtime(&menutime);
			strftime(current, 80, "%m/%d/%Y %I:%M%p", timeInfo);
			puts(current);

			cout << "Serendipity Booksellers" << endl;
			cout << "Reports Menu - Listing by Quantity" << endl << endl; // displays inventory sorted by quantity, fewest to most
			cout << "----------------------------------------------" << endl << endl;

			sortByQuantity(booklist);
			printList(booklist);

			system("pause");
			break;
		}
		case 5:
		{
			time(&menutime);
			timeInfo = localtime(&menutime);
			strftime(current, 80, "%m/%d/%Y %I:%M%p", timeInfo);
			puts(current);

			cout << "Serendipity Booksellers" << endl;
			cout << "Reports Menu - Listing by Cost" << endl << endl; // displays inventory sorted by retail cost, cheapest to priciest
			cout << "----------------------------------------------" << endl << endl;

			sortByCost(booklist);
			printList(booklist);

			system("pause");
			break;
		}
		case 6:
		{
			time(&menutime);
			timeInfo = localtime(&menutime);
			strftime(current, 80, "%m/%d/%Y %I:%M%p", timeInfo);
			puts(current);

			cout << "Serendipity Booksellers" << endl;
			cout << "Reports Menu - Listing by Age" << endl << endl; // displays inventory sorted by age, youngest to oldest
			cout << "----------------------------------------------" << endl << endl;

			sortByAge(booklist);
			printList(booklist);

			system("pause");
			break;
		}
		case 7:
			break;
		default:
			cout << "You did not enter a valid option (1, 2, 3, 4, 5, 6, or 7). Please try again." << endl << endl;
			system("pause");
		}
	}
}

void Report::printList(vector<Book>& booklist) // takes a list of books and prints them one by one
{
	if (booklist.size() == 0){ // if no books are in the inventory file
		cout << "There are no books in the inventory." << endl;
		cout << endl << "----------------------------------------------" << endl << endl;
	}
	else{
		for (unsigned int i = 0; i < booklist.size(); i++) // prints each book
		{
			booklist[i].print(false);
			cout << endl << "----------------------------------------------" << endl << endl;
		}
	}
}