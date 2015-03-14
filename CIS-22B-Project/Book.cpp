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

unsigned int Book::getISBN()
{
	return sISBN;
}

string Book::getTitle()
{
	return sTitle;
}

string Book::getAuthor()
{
	return sAuthor;
}

string Book::getPublisher()
{
	return sPublisher;
}

unsigned int Book::getQuantity()
{
	return sQuantity;
}

double Book::getWholesale()
{
	return sWholesale;
}

double Book::getRetail()
{
	return sRetail;
}

void Book::setISBN(unsigned int isbn)
{
	sISBN = isbn;
}

void Book::setTitle(char title[])
{
	for (int i = 0; i < 100; i++) sTitle[i] = title[i];
}

void Book::setAuthor(char author[])
{
	for (int i = 0; i < 100; i++) sAuthor[i] = author[i];
}

void Book::setPublisher(char publisher[])
{
	for (int i = 0; i < 100; i++) sPublisher[i] = publisher[i];
}

void Book::setQuantity(unsigned int quantity)
{
	sQuantity = quantity;
}

void Book::setRetail(double retail)
{
	sRetail = retail;
}

void Book::print()
{
	cout << "ISBN: " << sISBN << endl;
	cout << "Title: " << sTitle << endl;
	cout << "Author: " << sAuthor << endl;
	cout << "Publisher: " << sPublisher << endl;
	cout << "Quantity: " << sQuantity << endl;
	printf("Wholesale Price: $%.2f\n", sWholesale);
	printf("Retail Price: $%.2f\n", sRetail);
	cout << "Date Added: " << sDate << endl;
}

Book::~Book()
{
}