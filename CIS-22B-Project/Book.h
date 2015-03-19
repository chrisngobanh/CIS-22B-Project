#ifndef BOOK_H
#define BOOK_H

#include <cstring>
#include <iostream>
#include <vector>
#include <ctime>
#include <cctype>

using namespace std;

class Book
{
	friend class Inventory;
	friend class Cashier;
private:
	char sISBN[13];
	char sTitle[100];
	char sAuthor[100];
	char sPublisher[100];
	unsigned int sQuantity;
	double sWholesale, sRetail;
	time_t sDate;

public:
	Book(){}
	Book(char isbn[], char title[], char author[], char publisher[], unsigned int quantity, double wholesale, double retail, time_t date); //char date[]);

	char* getISBN();
	char* getTitle();
	char* getAuthor();
	char* getPublisher();
	unsigned int getQuantity();
	double getWholesale();
	double getRetail();
	time_t getDate();

	/*
	void setISBN(char[]);
	void setTitle(char[]);
	void setAuthor(char[]);
	void setPublisher(char[]);
	*/
	//using friend class to set sISBN, sTitle, sAuthor, sPublisher instead of mutator functions

	void print(bool);

	~Book();
};
#endif
