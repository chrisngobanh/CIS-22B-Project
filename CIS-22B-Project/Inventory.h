#pragma once
#include <string>

class Inventory
{
private:
	unsigned int sISBN;
	string sTitle, sAuthor, sPublisher;
	unsigned int sDate, sQuantity;
	double sWholesale, sRetail;

public:
	Inventory(unsigned int isbn, string title, string author, string publisher, unsigned int quantity, double wholesale);
	void setPrice(double retail);
	void addStock(unsigned int addition = 1);
	void subStock(unsigned int subtraction = 1);
	void inventoryMenu();
	~Inventory();
	
};