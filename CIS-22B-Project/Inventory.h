#include <string>
#include <iostream>
#include "Book.h"

using namespace std;
class Inventory
{
private:
	// Need a way to hold multiple Book objects than can change in size (linked lists? vectors?)

public:
	Inventory(){}
	void setPrice(Book target, double retail);
	void addStock(Book target, unsigned int addition = 1);
	void subStock(Book target, unsigned int subtraction = 1);
	void inventoryMenu();
	void lookUpBook();
	void addBook();
	void editBook();
	void deleteBook();

	~Inventory(){}
	
};