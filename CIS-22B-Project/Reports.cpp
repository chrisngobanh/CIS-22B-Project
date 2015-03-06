#define _CRT_SECURE_NO_WARNINGS

#include "Reports.h"
#include <iostream>

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

		
		

		switch (choice)
		{

		case 1:;
			cout << "Inventory Listing" << endl << endl;

			break;


		case 2:;
		{						
				   cout << "Inventory Wholesale Listing" << endl << endl;

	//		inventory.addBook();

		}

			break;


		case 3:;

			cout << "Inventory Retail Listing" << endl << endl;



			break;


		case 4:;

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
	
