#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include <vector>

using namespace std;

Book::Book(unsigned int isbn, char title[], char author[], char publisher[], unsigned int quantity, double wholesale, double retail, char date[])
{
	sISBN = isbn;
	for (int i = 0; i < 100; i++)
	{
		sTitle[i] = title[i];
		sAuthor[i] = author[i];
		sPublisher[i] = publisher[i];
		sDate[i] = date[i];
	}
	sRetail = retail;
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
	cout << "ISBN: " << sISBN << endl;
	cout << "Title: " << sTitle << endl;
	cout << "Author: " << sAuthor << endl;
	cout << "Publisher: " << sPublisher << endl;
	cout << "Quantity: " << sQuantity << endl;
	cout << "Wholesale Price: " << sWholesale << endl;
	cout << "Retail Price: " << sRetail << endl;
	cout << "Date Added: " << sDate << endl;
}

string Book::getTitle()
{
	return sTitle;
}

Book::~Book()
{
}