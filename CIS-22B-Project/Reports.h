#ifndef REPORTS_H
#define REPORTS_H

#include "Inventory.h"
#include "Book.h"
using namespace std;

class Report: public Inventory
{
private:

public:
	void menu();
	void printList(vector<Book>&);
	void sortByQuantity(vector<Book>&);
	void sortByCost(vector<Book>&);
	void sortByAge(vector<Book>&);

};

#endif