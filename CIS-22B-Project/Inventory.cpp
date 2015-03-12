#define _CRT_SECURE_NO_WARNINGS

#include "Inventory.h"
#include "Book.h"
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

void Inventory::setPrice(Book target, double retail)
{
	target.setPrice(retail);
}

void Inventory::addStock(Book target, unsigned int addition)
{
	target.addStock(addition);
}

void Inventory::subStock(Book target, unsigned int subtraction)
{
	target.subStock(subtraction);
}

void Inventory::inventoryMenu()
{
	int inventoryChoice = 0;
//	bool validFunction;

	Inventory inventory;
	do
	{
		//system("CLS");

		cout << "Serendipity Booksellers Inventory Database" << endl;

		cout << "1. Look Up a Book" << endl;

		cout << "2. Add a Book" << endl;

		cout << "3. Edit a Book's Record" << endl;

		cout << "4. Delete a Book" << endl;

		cout << "5. Return to the Main Menu" << endl << endl;

		cout << "Enter your Choice: ";

		cin >> inventoryChoice;
		if (!cin){
			cin.clear();
			inventoryChoice = 0;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}


		switch (inventoryChoice)
		{

		case 1:
			int choice;
			char title[100];
			unsigned int isbn;

			cout << "How would you like to look up a book?" << endl;
			cout << "1. Title" << endl;
			cout << "2. ISBN" << endl;
			cout << "Enter your Choice: ";
			cin >> choice;

			switch (choice)
			{
			case 1:
				cout << "Title: ";
				cin.ignore();
				cin.getline(title, 100);
				lookUpBook(title);
			case 2:
				cout << "ISBN: ";
				cin >> isbn;
				lookUpBookISBN(isbn);
			default: 
				break;
			}

			break;

		case 2:
		{
			inventory.addBook();
		}

			break;


		case 3:




			break;


		case 4:





			break;


		case 5:


			break;

		default: cout << "You did not enter a valid option 1, 2, 3, 4, 5. Please try again." << endl;



		}
	} while (inventoryChoice != 5);
}

void Inventory::sortByName(vector<Book>& booklist)
{
	
	for (int i = 0; i < booklist.size(); i++){
		for (int j = i+1; j < booklist.size(); j++)
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

void Inventory::lookUpBook(char title[])
{
	vector<Book> booklist =	readList();

	//sortByName(booklist);

	cout << "Search results:" << endl << endl;

	//vector<int> foundBooks;
	for (int i = 0; i < booklist.size(); i++){
		if (title == booklist[i].getTitle()){
			//foundBooks.push_back(i);
			booklist[i].print();
			cout << endl;
		}
	}
}

void Inventory::lookUpBookISBN(unsigned int isbn)
{
	vector<Book> booklist = readList();

	cout << "Search results:" << endl << endl;

	for (int i = 0; i < booklist.size(); i++){
		if (isbn == booklist[i].getISBN()){
			booklist[i].print();
			cout << endl;
		}
	}
}

vector<Book> Inventory::readList()
{
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
	return booklist;
}

void Inventory::writeList(vector<Book> list)
{
	ofstream ofs("bookList.txt", ios::out | ios::binary);
	int numBooks = list.size();
	ofs.write(reinterpret_cast<char *>(&numBooks), sizeof(numBooks));
	for (int i = 0; i < numBooks; i++)
	{
		ofs.write(reinterpret_cast<char *>(&list[i]), sizeof(list[i]));
	}
	ofs.close();
}


void Inventory :: addBook()
{
	unsigned int isbn, quantity;
	char title[100], author[100], publisher[100], dateAdded[100] = "";
	double wholesaleCost = 0;
	double retailPrice = 0;

	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(dateAdded, 100, "%m/%d/%y", timeinfo);
	cout << dateAdded;

	cout << "Please enter the following infornamtion." << endl;
	cout << "ISBN:" << endl;
	cin >> isbn;
	cout << "Title:" << endl;
	cin.ignore();
	cin.getline(title, 100);
	cout << "Author:" << endl;
	cin.getline(author, 100);
	cout << "Publisher:" << endl;
	cin.getline(publisher, 100);
	cout << "Quantity-On-Hand:" << endl;
	cin >> quantity;
	cout << "Wholesale Cost:" << endl;
	cin >> wholesaleCost;
	cout << "Retail Price:" << endl;
	cin >> retailPrice;
	cout << endl;



	Book book(isbn, title, author, publisher, quantity, wholesaleCost, retailPrice, dateAdded);
	
	vector<Book> booklist = readList();

	booklist.push_back(book);
	writeList(booklist);
}