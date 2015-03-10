#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
#include <iostream>
#include "Book.h"

using namespace std;
class Inventory
{
private:

public:
	void setPrice(Book target, double retail);
	void addStock(Book target, unsigned int addition = 1);
	void subStock(Book target, unsigned int subtraction = 1);
	void inventoryMenu();
	void lookUpBookISBN(unsigned int);
	void lookUpBook(char[]);
	void addBook();
	void editBook();
	void deleteBook();
	vector<Book> readList();
	void writeList(vector<Book>);
	void sortByName(vector<Book>&);

	~Inventory(){}
	

};
#endif