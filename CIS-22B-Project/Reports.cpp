#define _CRT_SECURE_NO_WARNINGS

#include "Reports.h"
#include <iostream>
#include <fstream>

using namespace std;

void Report::menu() 
{
	system("CLS");

	//declare array/vector of book objects
	int choice = 0;

	while (choice != 7)
	{
		cout << "Serendipity Booksellers\n";
		cout << "Reports\n";
		cout << "1. Inventory Listing\n";
		cout << "2. Inventory Wholesale Listing\n";
		cout << "3. Inventory Retail Value\n";
		cout << "4. Listing by Quantity\n";
		cout << "5. Listing by Cost\n";
		cout << "6. Listing by Age\n";
		cout << "7. Return to Main Menu\n";
		cout << "Enter your choice: " << endl;
		cin >> choice;
		cout << endl;

		vector<Book> booklist = readList();
		sortByName(booklist);

		
		switch (choice)
		{

		case 1:
		{
				  cout << "Inventory Listing" << endl << endl;

				  printList(booklist);
				  break;
		}

		case 2:
		{						
			cout << "Inventory Wholesale Listing" << endl << endl;

			double total = 0;

			for (unsigned int i = 0; i < booklist.size(); i++)
			{

				cout << "Title: " << booklist[i].getTitle() << endl;
				cout << "Quantity: " << booklist[i].getQuantity() << endl;
				cout << "Wholesale Price: " << booklist[i].getWholesale() << endl;
				cout << "----------------------------------------------" << endl << endl;
				total += (booklist[i].getWholesale() * booklist[i].getQuantity());
			}
			cout << "Total: $" << total << endl << endl;

			break;
	//		inventory.addBook();

		}


		case 3:
		{
				  cout << "Inventory Retail Listing" << endl << endl;

				  double total = 0;

				  for (unsigned int i = 0; i < booklist.size(); i++)
				  {

					  cout << "Title: " << booklist[i].getTitle() << endl;
					  cout << "Quantity: " << booklist[i].getQuantity() << endl;
					  cout << "Retail Price: " << booklist[i].getRetail() << endl;
					  cout << "----------------------------------------------" << endl << endl;
					  total += (booklist[i].getRetail() * booklist[i].getQuantity());
				  }
				  cout << "Total: $" << total << endl << endl;

				  break;

		}
		case 4:

			cout << "Listing by Quantity" << endl << endl;

			sortByQuantity(booklist);

			printList(booklist);

			break;


		case 5:
			cout << "Listing by Cost" << endl << endl;

			sortByCost(booklist);
			printList(booklist);
			break;

		case 6:
			cout << "Listing by Age" << endl << endl;

			break;
		case 7:

			break;

		default: cout << "You did not enter a valid option. Please try again." << endl << endl;



		}
	}// while (choice != 5);
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

void Report::printList(vector<Book>& booklist)
{

	for (unsigned int i = 0; i < booklist.size(); i++)
	{

		booklist[i].print();
		cout << "----------------------------------------------" << endl << endl;
	}

}