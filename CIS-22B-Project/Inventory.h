#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <iostream>
#include "Book.h"
#include "Menu.h"

using namespace std;
class Inventory: public Menu
{
private:

public:
	void inventoryMenu();

	void sortByName(vector<Book>&);

	vector<int> lookUpBookISBN(char[], vector<Book>&);
	vector<int> lookUpBookTitle(char[], vector<Book>&);
	vector<int> lookUpBookAuthor(char[], vector<Book>&);
	vector<int> lookUpBookPublisher(char[], vector<Book>&);

	void addBook(vector<Book>&);
	void editBook(int, vector<Book>&);

	vector<Book> readList();
	void writeList(vector<Book>);

	~Inventory(){}


};
#endif
