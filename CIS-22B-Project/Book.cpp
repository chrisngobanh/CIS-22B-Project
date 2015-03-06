#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include <vector>

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

void Book::print()
{
	cout << sISBN << endl;
	cout << sTitle << endl;
	cout << sAuthor << endl;
	cout << sPublisher << endl;
	cout << sQuantity << endl;
	cout << sWholesale << endl;
}

Book::~Book()
{
}