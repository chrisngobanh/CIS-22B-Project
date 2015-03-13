#include "Inventory.h"
#include "Book.h"
using namespace std;

class Report: public Inventory
{
private:


public:

	void menu();
	void printList(vector<Book>&);
	void sortByName(vector<Book>&);
	void sortByQuantity(vector<Book>&);
	void sortByCost(vector<Book>&);
	void sortByAge(vector<Book>&);

};