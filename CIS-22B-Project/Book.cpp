#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include <vector>
#include <fstream>

using namespace std;

Book::Book(unsigned int isbn, char title[], char author[], char publisher[], unsigned int quantity, double wholesale)
{
	sISBN = isbn;
	for (int i = 0; i < 100; i++)
	{
		sTitle[i] = title[i];
		sAuthor[i] = author[i];
		sPublisher[i] = publisher[i];
	}
	sQuantity = quantity;
	sWholesale = wholesale;
}

void Book::setPrice(double retail)
{
	sRetail = retail;
}

void Book::addStock(unsigned int addition)
{
	sQuantity += addition;
}

void Book::subStock(unsigned int subtraction)
{
	sQuantity -= subtraction;
}
/*								almost done i think
vector<Book> Book::readList()
{
	int numBooks;
	Book *books;

	ifstream ifs("BookList.txt", ios::binary);

	if (ifs)
	{
		ifs.read(reinterpret_cast<char *>(&numBooks), sizeof(numBooks));
		books = new Book[numBooks];
		if (books == nullptr)
		{
			cout << "Memory could not be allocated, Exiting program ..." << endl << endl;
			system("pause");
			exit(-1);
		}

		for (int i = 0; i < numBooks; i++)
		{
			ifs.read(reinterpret_cast<char *>(&books[i]), sizeof(books[i]));
			books[i].print(books[i]);
		}
		
	}
}

void Book::writeList(vector<Book> list)
{

	ofstream ofs("BookList.txt", ios::binary);
	for (int i = 0; i < list.size; i++)
	{
		ofs.write(reinterpret_cast<char *>(&list[i]), sizeof(list[i]));
	}
}*/

void Book::print(Book book)
{
	cout << book.sISBN << endl;
	cout << book.sTitle << endl;
	cout << book.sAuthor << endl;
	cout << book.sPublisher << endl;
	cout << book.sQuantity << endl;
	cout << book.sWholesale << endl;
}

Book::~Book()
{
}