#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
/*The Cashier module allows the computer to act as a cash register. The user enters
information for the books being purchased and the program calculates the sales tax and
the total price. In addition, the books being purchased are automatically subtracted from
the Inventory Database.*/

//not done.

class Cashier
{
private:
	string bookName;
	double bookPrice;
	int quantity;
	const double taxrate = .0875;

public:
	void menu();
	void addBook(char book[]);
//	void Checkout(array or vector???? of books)

};