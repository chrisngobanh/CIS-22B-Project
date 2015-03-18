#define _CRT_SECURE_NO_WARNINGS

#include "Reports.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Report::menu() 
{

	//declare array/vector of book objects
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
		cout << "Enter your choice: " << endl;
		cin >> choice;
		if (!cin){
			cin.clear();
			choice = 0;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		cout << endl;

		vector<Book> booklist = readList();
		sortByName(booklist);

		system("CLS");
		switch (choice){
		case 1:
		{
			time(&menutime);
			timeInfo = localtime(&menutime);
			strftime(current, 80, "%m/%d/%Y %I:%M%p", timeInfo);
			puts(current);

			cout << "Serendipity Booksellers" << endl;
			cout << "Reports Menu - Inventory Listing" << endl << endl;

			system("pause");
			printList(booklist);
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

			for (unsigned int i = 0; i < booklist.size(); i++)
			{
				double cost = booklist[i].getWholesale() * booklist[i].getQuantity();
				cout << setw(30) << left << booklist[i].getTitle();
				cout << setw(10) << left << booklist[i].getQuantity();
				cout << "$" << setw(10) << left << booklist[i].getWholesale();
				cout << "$" << setw(5) << left << cost;
				cout << endl;

				total += cost;
			}
			cout << "---------------------------------------------------------" << endl;
			cout << setw(33) << left << "" << "Total Cost: $" << total << endl << endl;

			system("pause");
			break;
	//		inventory.addBook();

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

			for (unsigned int i = 0; i < booklist.size(); i++)
			{

				double cost = booklist[i].getRetail() * booklist[i].getQuantity();
				cout << setw(30) << left << booklist[i].getTitle();
				cout << setw(10) << left << booklist[i].getQuantity();
				cout << "$" << setw(10) << left << booklist[i].getRetail();
				cout << "$" << setw(5) << left << cost;
				cout << endl;

				total += cost;
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
	

void Report::sortByName(vector<Book>& booklist)
{

	for (size_t i = 0; i < booklist.size(); i++){
		for (size_t j = i + 1; j < booklist.size(); j++)
		{
			if (booklist[i].getTitle() > booklist[j].getTitle()){
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

void Report::printList(vector<Book>& booklist)
{

	for (unsigned int i = 0; i < booklist.size(); i++)
	{

		booklist[i].print();
		cout << "----------------------------------------------" << endl << endl;
	}

}