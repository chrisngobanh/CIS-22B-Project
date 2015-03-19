#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include"CIS-22B-Project\Cashier.h"
#include"CIS-22B-Project\Inventory.h"
#include"CIS-22B-Project\Book.h"
#include"CIS-22B-Project\Reports.h"
#include<string>
#include<fstream>
#include<ctime>
using namespace std;

void splashScreen();

int main()
{

	splashScreen();

	Cashier cashier;
	Inventory inventory;
	Report report;

	// create pointers for the individual modules
	Menu* cashpoint = &cashier;
	Menu* invpoint = &inventory;
	Menu* reppoint = &report;

	int choice=0;
	fstream bookList;

	bookList.open("booklist.txt", ios::in);	//open booklist for both input and output
	bookList.open("booklist.txt", ios::out);

	while (choice != 4)	//main menu loops until user exits program
	{
		system("CLS");	//clear screen each time user returns to main menu

		time_t rawtime;
		struct tm * timeinfo;	//use ctime to get current date and time
		char current[80] = "";
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(current, 80, "%m/%d/%Y %I:%M%p", timeinfo);	//format the date and time

		for (int i = 0; i < 80; i++)	//display date and time
			cout << current[i];
		cout << "Serendipity Booksellers\n";
		cout << "Main Menu\n\n";
		cout << "What would you like to do?\n";
		cout << "1. Cashier Module\n";
		cout << "2. Inventory Database Module\n";
		cout << "3. Report Module\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		if (!cin){
			cin.clear();
			choice = 0;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}


		while (choice < 1 || choice > 4) //can only enter 1-4
		{
			cout << "You did not enter a valid option (1, 2, 3, or 4). Please try again: ";
			cin >> choice;
			if (!cin){
				cin.clear();	
				choice = 0; // defaults choice to 0 if user attempts to enter a non-number
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		
		switch (choice) // accesses the desired menu by calling the virtual function, demonstrating polymorphism
		{
		case 1:
			cashpoint->menu();
			//open cashier module
			break;
		case 2:
			invpoint->menu();
			//open inventory module
			break;
		case 3:
			reppoint->menu();
			//open report module
			break;
		case 4:
			break;
		}
		
	}
	cout << endl << "Thank you for using Serendipity Booksellers!" << endl;
	system("pause");
	return 0;
}

void splashScreen() {

	cout << "Serendipity Booksellers Program." << endl << endl;
	cout << "Loading..." << endl << endl;

	cout <<"             ..ee$$$$$ee..							";
    cout <<"         .e$*\"\"    $    \"\"*$e.					"<< endl;
	cout <<"       z$\"*.       $         $$c                   "<< endl;   
	cout <<"     z$\"   *.      $       .P  ^$c                 "<< endl;   
	cout <<"    d\"      *      $      z\"     \"b      Come        "<< endl;    
	cout <<"   $\"        b     $     4%       ^$     On        "<< endl;   
	cout <<"  d%         *     $     P         '$    And       "<< endl;  
	cout <<" .$          'F    $    J\"          $r   Slam        "<< endl;  
	cout <<" 4L...........b....$....$...........J$   And		"<< endl;
	cout <<" $F           F    $    $           4$	 Welcome		"<< endl;
	cout <<" 4F          4F    $    4r          4P	 To		"<< endl;
	cout <<" ^$          $     $     b          $%	 The		"<< endl;
	cout <<"  3L       .F      $     'r        JP	 Jam		"<< endl;         
	cout <<"  *c       $       $      3.      z$				"<< endl;
	cout <<"   *b     J\"       $       3r    dP                "<< endl;
	cout <<"     ^$c  z%       $        \"c z$\"				"<< endl;
	cout <<"       \"*$L        $        .d$\"					"<< endl;
	cout <<"          \"*$ee..  $  ..ze$P\" 					"<< endl;
	cout <<"              \"\"*******\"\"						"<< endl;
                                                          



	system("pause");
}