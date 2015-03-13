#define _CRT_SECURE_NO_WARNINGS

#include "Inventory.h"
#include "Book.h"
#include <vector>
#include <fstream>
#include <ctime>
#include <iostream>

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
	Book i, t;
	//	bool validFunction;

	Inventory inventory;
	do
	{
		system("CLS");

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
			do{
				cout << "How would you like to look up a book?" << endl;
				cout << "1. Title" << endl;
				cout << "2. ISBN" << endl;
				cout << "3. Return to the Inventory Menu." << endl;
				cout << "Enter your Choice: ";
				cin >> choice;
				cout << endl;

				switch (choice)
				{
				case 1:
					cout << "Title: ";
					cin.ignore();
					cin.getline(title, 100);

					t = lookUpBook(title);
					break;
				case 2:
					cout << "ISBN: ";
					cin >> isbn;

					i = lookUpBookISBN(isbn);
					break;
				default:
					break;
				}
				switch (choice)
				{
				case 1:
					cout << "Title: ";
					cin.ignore();
					cin.getline(title, 100);
					cout << "Search results:" << endl << endl;
					lookUpBook(title);
					break;
				case 2:
					cout << "ISBN: ";
					cin >> isbn;
					cout << "Search results:" << endl << endl;
					lookUpBookISBN(isbn);
					break;
				case 3:
					break;
				default:
					cout << "You did not enter a valid option(1, 2, or 3). Please try again." << endl;
					break;
				}
			} while (choice != 3);

			break;

		case 2:
		{
				  inventory.addBook();
		}

			break;


		case 3:
		{
				  int choice;
				  char title[100];
				  unsigned int isbn;
				  do{
					  cout << "What book would you like to edit? Search the book by" << endl;
					  cout << "1. 'Title'" << endl;
					  cout << "2. 'ISBN'" << endl;
					  cout << "(Enter '3' to return to the Inventory Menu." << endl;
					  cout << "Enter your Choice: ";
					  cin >> choice;
					  cout << endl;

					  switch (choice)
					  {
					  case 1:
						  cout << "Title: ";
						  cin.ignore();
						  cin.getline(title, 100);
						  cout << "Current information of the book:" << endl << endl;
						  lookUpBook(title);
						  editBook(title);
						  break;
					  case 2:
						  cout << "ISBN: ";
						  cin >> isbn;
						  cout << "Current information of the book:" << endl << endl;
						  lookUpBookISBN(isbn);
						  editBook(title);
						  break;
					  case 3:
						  break;
					  default:
						  cout << "You did not enter a valid option(1, 2, or 3). Please try again." << endl;
						  break;
					  }
				  } while (choice != 3);

				  break;

		}


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
	for (unsigned int i = 0; i < booklist.size(); i++){
		for (unsigned int j = i + 1; j < booklist.size(); j++)
		{
			if (booklist[i].getTitle() > booklist[j].getTitle()){
				Book temp = booklist[i];
				booklist[i] = booklist[j];
				booklist[j] = temp;
			}
		}
	}
}

Book Inventory::lookUpBook(char title[])
{
	vector<Book> booklist = readList();

	//sortByName(booklist);

	//vector<int> foundBooks;
	for (unsigned int i = 0; i < booklist.size(); i++)
	{
		if (title == booklist[i].getTitle())
		{
			//foundBooks.push_back(i);
			booklist[i].print();
			cout << endl;
			return booklist[i];
		}
	}
}

Book Inventory::lookUpBookISBN(unsigned int isbn)
{
	vector<Book> booklist = readList();

	cout << "Search results:" << endl << endl;

	for (unsigned int i = 0; i < booklist.size(); i++)
	{
		if (isbn == booklist[i].getISBN())
		{
			for (int i = 0; i < booklist.size(); i++){
				if (isbn == booklist[i].getISBN()){
					booklist[i].print();
					cout << endl;
					return booklist[i];
				}
			}
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


void Inventory::addBook()
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
	//cout << dateAdded;

	cout << "Please enter the following infornamtion." << endl << "(Enter '0' to return to Inventory Menu.)" << endl;
	cout << "ISBN:" << endl;
	cin >> isbn;
	if (isbn != 0)
	{
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
		cout << "The book has been successfully added." << endl << endl;
	}
}

void Inventory::editBook(char title[])
{
	int choice;
	unsigned int isbn, quantity;
	char title2[100], author[100], publisher[100], dateAdded[100] = "";
	vector<Book> bookList = readList();
	double wholesaleCost = 0;
	double retailPrice = 0;

	do{
		cout << "Which information would you like to edit?" << endl;
		cout << "1. ISBN" << endl;
		cout << "2. Title" << endl;
		cout << "3. Author" << endl;
		cout << "4. Publisher" << endl;
		cout << "5. Quantity-On-Hand" << endl;
		cout << "6. Wholesale Cost" << endl;
		cout << "7. Retail Price" << endl;
		cout << "8. Return to the previous menu." << endl;
		cout << "Enter your Choice: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			cout << "To edit ISBN, please enter the new ISBN: ";
			cin >> isbn;
			for (unsigned int i = 0; i < bookList.size(); i++)
			{
				if (title == bookList[i].getTitle())
					bookList[i].setISBN(isbn);
			}
			writeList(bookList);
			cout << endl << "ISBN has been successfully edited: " << endl;
			lookUpBook(title);
			break;
		case 2:
			/*		cout << "To edit title, please enter the new title: ";
			cin >> title2;
			for (unsigned int i = 0; i < bookList.size(); i++)
			{
			if (title == bookList[i].getTitle())
			bookList[i].set
			}
			writeList(bookList);
			cout << endl << "ISBN has been successfully edited: " << endl;
			lookUpBook(title);
			break;*/
		case 3:
		{

		}
			break;
		case 4:
		{

		}
			break;
		case 5:
		{
					/*		cout << "To edit quantity of the book, please enter the new quantity: ";
					cin >> isbn;
					for (unsigned int i = 0; i < bookList.size(); i++)
					{
					if (title == bookList[i].getTitle())
					bookList[i].setISBN(isbn);
					}
					writeList(bookList);
					cout << endl << "ISBN has been successfully edited: " << endl;
					lookUpBook(title);
					*/
		}
			break;
		case 6:
			break;
		case 7:
		{

		}
			break;
		case 8:
		{

		}
			break;


		default:
			cout << "You did not enter a valid option(1, 2, 3, 4, 5, 6, 7, or 8). Please try again." << endl << endl;
		}
	} while (choice != 8);
}
