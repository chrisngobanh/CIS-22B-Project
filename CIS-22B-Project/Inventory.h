#pragma once

class Inventory
{
private:
	unsigned int ISBN;
	string title, author, publisher;
	unsigned int date, quantity;
	double wholesale, retail;

public:
	Inventory();
	~Inventory();
};