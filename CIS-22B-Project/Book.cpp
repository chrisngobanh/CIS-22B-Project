#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include <vector>

using namespace std;

// Book constructor
Book::Book(char isbn[], char title[], char author[], char publisher[], unsigned int quantity, double wholesale, double retail, time_t date)
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

char* Book::getISBN()
{
	return sISBN;
}

char* Book::getTitle()
{
	return sTitle;
}

char* Book::getAuthor()
{
	return sAuthor;
}

char* Book::getPublisher()
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

/*
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
*/
//using friend class to set sQuantity and sRetail instead of mutator functions

// prints book object to output for user to see
void Book::print(bool isCash)
{
	cout << "ISBN: " << sISBN << endl;
	cout << "Title: " << sTitle << endl;
	cout << "Author: " << sAuthor << endl;
	cout << "Publisher: " << sPublisher << endl;
	cout << "Quantity: " << sQuantity << endl;
	if (isCash == false) printf("Wholesale Price: $%.2f\n", sWholesale);
	printf("Retail Price: $%.2f\n", sRetail);
	if (isCash == false){
		char buffer[100] = "";
		struct tm *timeinfo;
		timeinfo = localtime(&sDate);
		strftime(buffer, 100, "Date Added: %m/%d/%Y", timeinfo);
		puts(buffer);
	}
}

Book::~Book()
{
}