#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Book
{
private:
	unsigned int sISBN;
	char sTitle[100];
	char sAuthor[100];
	char sPublisher[100];
	char sDate[100];
	unsigned int sQuantity;
	double sWholesale, sRetail;

public:
	Book(){}
	Book(unsigned int isbn, char title[], char author[], char publisher[], unsigned int quantity, double wholesale, double retail, char date[]);
	string getTitle();
	void setPrice(double retail);
	void addStock(unsigned int addition = 1);
	void subStock(unsigned int subtraction = 1);
	void print();
	~Book();
};
#endif