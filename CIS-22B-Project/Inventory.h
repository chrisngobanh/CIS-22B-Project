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
	void menu();

	// used by Reports
	void sortByTitle(vector<Book>&);
	void sortByQuantity(vector<Book>&);
	void sortByCost(vector<Book>&);
	void sortByAge(vector<Book>&);

	vector<int> lookUpBookISBN(char[], vector<Book>&, bool);
	vector<int> lookUpBookTitle(char[], vector<Book>&, bool);
	vector<int> lookUpBookAuthor(char[], vector<Book>&, bool);
	vector<int> lookUpBookPublisher(char[], vector<Book>&, bool);

	void addBook(vector<Book>&);
	template<class T1, class T2>
	void setValue(T1&, T2);
	void editBook(int, vector<Book>&);

	vector<Book> readList();
	void writeList(vector<Book>);

	~Inventory(){}


};
#endif
