#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
using namespace std;

Book::Book(unsigned int isbn, string title, string author, string publisher, unsigned int quantity, double wholesale)
{
	sISBN = isbn;
	sTitle = title;
	sAuthor = author;
	sPublisher = publisher;
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

Book::~Book()
{
}