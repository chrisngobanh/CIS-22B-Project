#include <string>
#include <iostream>

using namespace std;
class Book
{
private:
	unsigned int sISBN;
	string sTitle;
	string sAuthor;
	string sPublisher;
	unsigned int sDate, sQuantity;
	double sWholesale, sRetail;

public:
	Book(){}
	Book(unsigned int isbn, string title, string author, string publisher, unsigned int quantity, double wholesale);
	void setPrice(double retail);
	void addStock(unsigned int addition = 1);
	void subStock(unsigned int subtraction = 1);
	void inventoryMenu();

	~Book();

};