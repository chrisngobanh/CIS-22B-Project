#define _CRT_SECURE_NO_WARNINGS
#include "Inventory.h"
#include "Book.h"
#include <vector>
#include <fstream>
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

		cout << "Enter your Choice: " << endl << endl;

		cin >> inventoryChoice;


		switch (inventoryChoice)
		{

		case 1:;
			cout << "How would you like to look up a book?" << endl;
			
			break;


		case 2:;
		{
			inventory.addBook();

		}

			break;


		case 3:;




			break;


		case 4:;





			break;


		case 5:


			break;

		default: cout << "You did not enter a valid option 1, 2, 3, 4, 5. Please try again." << endl;



		}
	} while (inventoryChoice != 5);
}
/*
void Inventory::lookUpBook()
{
	char name[100];
	cout << "Enter name of book: ";
	cin.getline(name, 100);
}
*/

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
			cout << "Memory could not be allocated, Exiting program ..." << endl << endl;
			system("pause");
			exit(-1);
		}

		while (!ifs.eof())
		{
			Book newbook;
			ifs.read(reinterpret_cast<char *>(&newbook), sizeof(newbook));
			booklist.push_back(newbook);

		}
		for (int i = 0; i < numBooks; i++)
		{
			booklist[i].print();
			cout << endl;
		}
		system("pause");
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
	char title[100], author[100], publisher[100], dateAdded[100];
	double wholesaleCost = 0;
	//double retailPrice = 0;

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
	/*
	cout << "Date Added:" << endl;
	cin.getline(dateAdded, 100);
	*/
	cout << "Quantity-On-Hand:" << endl;
	cin >> quantity;
	cout << "Wholesale Cost:" << endl;
	cin >> wholesaleCost;
	/*
	cout << "Retail Price:" << endl;
	cin >> retailPrice;*/
	cout << endl;



	Book book(isbn, title, author, publisher, quantity, wholesaleCost);
	
	vector<Book> booklist = readList();

	booklist.push_back(book);
	writeList(booklist);
}