#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include <vector>

using namespace std;

Book::Book(char isbn[], char title[], char author[], char publisher[], unsigned int quantity, double wholesale, double retail, time_t date) //char date[])
{
	strcpy(sISBN, isbn);
	strcpy(sTitle, title);
	strcpy(sAuthor, author);
	strcpy(sPublisher, publisher);
	sRetail = retail;
	sQuantity = quantity;
	sWholesale = wholesale;
	sDate = date;
}

string Book::getISBN()
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

time_t Book::getDate()
{
	return sDate;
}

void Book::setISBN(char isbn[])
{
	strcpy(sISBN, isbn);
}

void Book::setTitle(char title[])
{
	strcpy(sTitle, title);
}

void Book::setAuthor(char author[])
{
	strcpy(sAuthor, author);
}

void Book::setPublisher(char publisher[])
{
	strcpy(sPublisher, publisher);
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
	char buffer[100] = "";
	struct tm *timeinfo;
	timeinfo = localtime(&sDate);
	strftime(buffer, 100, "Date Added: %m/%d/%Y", timeinfo);
	puts(buffer);
}

Book::~Book()
{
}