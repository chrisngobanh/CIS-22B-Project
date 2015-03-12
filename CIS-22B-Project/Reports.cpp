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

		int numBooks;
		vector<Book> booklist;
		vector<Book> *a;
		ifstream ifs("bookList.txt", ios::in | ios::binary);

		if (ifs)
		{
			ifs.read(reinterpret_cast<char *>(&numBooks), sizeof(numBooks));

			a = new vector<Book>;

			if (a == nullptr)
			{
				cout << "Memory could not be allocated..." << endl << endl;
				system("pause");
				exit(-1);
			}

			for (int i = 0; i < numBooks; i++)
			{
				Book newbook;
				ifs.read(reinterpret_cast<char *>(&newbook), sizeof(newbook));
				booklist.push_back(newbook);

			}
		}
		ifs.close();
		

		switch (choice)
		{

		case 1:
		{
				  cout << "Inventory Listing" << endl << endl;

				  for (unsigned int i = 0; i < booklist.size(); i++)
				  {

					  booklist[i].print();
					  cout << "----------------------------------------------" << endl << endl;
				  }
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
			cout << "Total: " << total << endl << endl;

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
				  cout << "Total: " << total << endl << endl;

				  break;

		}
		case 4:

			cout << "Listing by Quantity" << endl << endl;



			break;


		case 5:
			cout << "Listing by cost" << endl << endl;

			break;

		case 6:
			cout << "Listing by age" << endl << endl;

			break;
		case 7:

			break;

		default: cout << "You did not enter a valid option. Please try again." << endl << endl;



		}
	}// while (choice != 5);
	}
	
