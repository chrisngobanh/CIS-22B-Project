#define _CRT_SECURE_NO_WARNINGS

#include "Reports.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

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
		cout << "Enter your choice: " << endl;	//ask for choice

		cin >> choice;	//get choice

		if (!cin){
			cin.clear();
			choice = 0;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		cout << endl;

		vector<Book> booklist = readList();	//uses function inherited from parent class
		sortByTitle(booklist);	//sorts the list by name each time, so the "inventory listing" will be sorted by name

		system("CLS");	//clear screen

		switch (choice){
		case 1:
		{
			time(&menutime);
			timeInfo = localtime(&menutime);
			strftime(current, 80, "%m/%d/%Y %I:%M%p", timeInfo);
			puts(current);

			cout << "Serendipity Booksellers" << endl;
			cout << "Reports Menu - Inventory Listing" << endl << endl;

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
			cout << "Reports Menu - Inventory Wholesale Listing" << endl << endl;

			cout << setw(30) << left << "Title";
			cout << setw(10) << left << "Quantity";
			cout << setw(11) << left << "Wholesale";
			cout << setw(5) << left << "Cost";

			cout << endl;

			cout << "---------------------------------------------------------" << endl;
			double total = 0;

			for (unsigned int i = 0; i < booklist.size(); i++)	//print each book's information
			{
				double cost = booklist[i].getWholesale() * booklist[i].getQuantity();

				string tmp = booklist[i].getTitle();

				if (tmp.length() > 25) {
					tmp = tmp.substr(0, 25) + "...";
				}

				cout << setprecision(2) << fixed;
				cout << setw(30) << left << tmp;
				cout << setw(10) << left << booklist[i].getQuantity();
				cout << "$" << setw(10) << left << setprecision(2) << fixed << booklist[i].getWholesale();
				cout << "$" << setw(5) << left << cost;
				cout << endl;

				total += cost;	//add each book's wholesale cost to the total variable
			}
			cout << "---------------------------------------------------------" << endl;
			cout << setw(33) << left << "" << "Total Cost: $" << total << endl << endl;	//display total

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
			cout << "Reports Menu - Inventory Retail Listing" << endl << endl;
					
			cout << setw(30) << left << "Title";
			cout << setw(10) << left << "Quantity";
			cout << setw(11) << left << "Retail";
			cout << setw(5) << left << "Cost";

			cout << endl;

			cout << "---------------------------------------------------------" << endl;

			double total = 0;

			for (unsigned int i = 0; i < booklist.size(); i++)	//print each book's information
			{
				double cost = booklist[i].getRetail() * booklist[i].getQuantity();

				string tmp = booklist[i].getTitle();

				if (tmp.length() > 25) {
					tmp = tmp.substr(0, 25) + "...";
				}

				cout << setprecision(2) << fixed;
				cout << setw(30) << left << tmp;
				cout << setw(10) << left << booklist[i].getQuantity();
				cout << "$" << setw(10) << left << setprecision(2) << fixed << booklist[i].getRetail();
				cout << "$" << setw(5) << left << cost;
				cout << endl;

				total += cost;	//add each book's retail cost to the total variable
			}
			cout << "---------------------------------------------------------" << endl;
			cout << setw(33) << left << "" << "Total Cost: $" << total << endl << endl;

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
			cout << "Reports Menu - Listing by Quantity" << endl << endl;

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
			cout << "Reports Menu - Listing by Cost" << endl << endl;

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
			cout << "Reports Menu - Listing by Age" << endl << endl;
			sortByAge(booklist);
			printList(booklist);

			system("pause");
			break;
		}
		case 7:
			break;
		default:
			cout << "You did not enter a valid option. Please try again." << endl << endl;
			system("pause");
		}
	}
}

/*	The following functions are being inherited from Inventory now
void Report::sortByQuantity(vector<Book>& booklist)
{

	for (size_t i = 0; i < booklist.size(); i++){
		for (size_t j = i + 1; j < booklist.size(); j++)
		{
			if (booklist[i].getQuantity() > booklist[j].getQuantity()){
				Book temp1 = booklist[j], temp2 = booklist[i];
				booklist.erase(booklist.begin() + j);
				if (booklist.begin() + j != booklist.end()) booklist.insert(booklist.begin() + j, temp2);
				else booklist.push_back(temp2);
				booklist.insert(booklist.begin() + i, temp1);
				booklist.erase(booklist.begin() + i + 1);
			}
		}
	}
}

void Report::sortByCost(vector<Book>& booklist)
{

	for (size_t i = 0; i < booklist.size(); i++){
		for (size_t j = i + 1; j < booklist.size(); j++)
		{
			if (booklist[i].getRetail() > booklist[j].getRetail()){
				Book temp1 = booklist[j], temp2 = booklist[i];
				booklist.erase(booklist.begin() + j);
				if (booklist.begin() + j != booklist.end()) booklist.insert(booklist.begin() + j, temp2);
				else booklist.push_back(temp2);
				booklist.insert(booklist.begin() + i, temp1);
				booklist.erase(booklist.begin() + i + 1);
			}
		}
	}
}

void Report::sortByAge(vector<Book>& booklist)
{
	for (size_t i = 0; i < booklist.size(); i++){
		for (size_t j = i + 1; j < booklist.size(); j++)
		{
			if (booklist[i].getDate() > booklist[j].getDate()){
				Book temp1 = booklist[j], temp2 = booklist[i];
				booklist.erase(booklist.begin() + j);
				if (booklist.begin() + j != booklist.end()) booklist.insert(booklist.begin() + j, temp2);
				else booklist.push_back(temp2);
				booklist.insert(booklist.begin() + i, temp1);
				booklist.erase(booklist.begin() + i + 1);
			}
		}
	}
}
*/

void Report::printList(vector<Book>& booklist)
{

	for (unsigned int i = 0; i < booklist.size(); i++)
	{

		booklist[i].print();
		cout << endl << "----------------------------------------------" << endl << endl;
	}

}