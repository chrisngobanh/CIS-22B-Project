#define _CRT_SECURE_NO_WARNINGS

#include "Inventory.h"

using namespace std;


Inventory::Inventory(unsigned int isbn, string title, string author, string publisher, unsigned int quantity, double wholesale)
{
	sISBN = isbn;
	sTitle = title;
	sAuthor = author;
	sPublisher = publisher;
	sQuantity = quantity;
	sWholesale = wholesale;
}

void Inventory::setPrice(double retail)
{
	sRetail = retail;
}

void Inventory::addStock(unsigned int addition = 1)
{
	sQuantity += addition;
}

void Inventory::subStock(unsigned int subtraction = 1)
{
	sQuantity -= subtraction;
}

Inventory::~Inventory()
{
}