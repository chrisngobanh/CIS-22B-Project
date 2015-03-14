#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Book
{
private:
	unsigned int sISBN;
	char sTitle[100];
	char sAuthor[100];
	char sPublisher[100];
	// char sDate[100];
	unsigned int sQuantity;
	double sWholesale, sRetail;
	time_t sDate;

public:
	Book(){}
	Book(unsigned int isbn, char title[], char author[], char publisher[], unsigned int quantity, double wholesale, double retail, time_t date); //char date[]);

	unsigned int getISBN();
	string getTitle();
	string getAuthor();
	string getPublisher();
	unsigned int getQuantity();
	double getWholesale();
	double getRetail();
	time_t getDate();

	void setISBN(unsigned int);
	void setTitle(char[]);
	void setAuthor(char[]);
	void setPublisher(char[]);
	void setQuantity(unsigned int);
	void setRetail(double);

	void print();

	~Book();
};
#endif
