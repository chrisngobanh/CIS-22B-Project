#define _CRT_SECURE_NO_WARNINGS

#include "Inventory.h"
#include "Book.h"
#include <vector>
#include <fstream>

using namespace std;

void Inventory::menu()
{
	int inventoryChoice = 0;

	Inventory inventory;
	do
	{
		system("CLS");

		time_t menutime;
		struct tm * timeInfo;
		char current[80] = "";
		time(&menutime);
		timeInfo = localtime(&menutime);
		strftime(current, 80, "%m/%d/%Y %I:%M%p", timeInfo);
		puts(current);

		vector<Book> booklist = readList();

		cout << "Serendipity Booksellers" << endl << "Inventory Menu - Main" << endl << endl;
		cout << "What would you like to do?" << endl;
		cout << "1. Look Up a Book" << endl;
		cout << "2. Add a Book" << endl;
		cout << "3. Edit a Book's Record" << endl;
		cout << "4. Delete a Book" << endl;
		cout << "5. Return to the Main Menu" << endl;
		cout << "Enter your Choice: ";
		cin >> inventoryChoice;
		if (!cin){
			cin.clear();
			inventoryChoice = 0;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << endl;

		switch (inventoryChoice){
		case 1:
		{
			int choice;
			do{
				system("CLS");

				time(&menutime);
				timeInfo = localtime(&menutime);
				strftime(current, 80, "%m/%d/%Y %I:%M%p", timeInfo);
				puts(current);
				
				cout << "Serendipity Booksellers" << endl << "Inventory Menu - Look Up Book" << endl << endl;
				cout << "How would you like to look up a book?" << endl;
				cout << "1. ISBN" << endl;
				cout << "2. Title" << endl;
				cout << "3. Author" << endl;
				cout << "4. Publisher" << endl;
				cout << "5. Return to the Inventory Menu." << endl;
				cout << "Enter your Choice: ";
				cin >> choice;
				if (!cin){
					cin.clear();
					choice = 0;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				cout << endl;

				switch (choice){
				case 1:
				{
					char isbn[13];
					cout << "ISBN: ";
					cin.ignore();
					cin.getline(isbn, 13);
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					try
					{
						vector<int> searchResults = lookUpBookISBN(isbn, booklist);
					}
					catch (char* error)
					{
						cout << endl << "Error: " << error << endl;
					}
					
					system("pause");
					break;
				}
				case 2:
				{
					char title[100];

					cout << "Title: ";
					cin.ignore();
					cin.getline(title, 100);
					cin.ignore(numeric_limits<streamsize>::max(), '\n');


					try
					{
						vector<int> searchResults = lookUpBookTitle(title, booklist);
					}
					catch (char* error)
					{
						cout << endl << "Error: " << error << endl;
					}

					system("pause");
					break;
				}
				case 3:
				{
					char author[100];

					cout << "Author: ";
					cin.ignore();
					cin.getline(author, 100);
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					try
					{
						vector<int> searchResults = lookUpBookAuthor(author, booklist);
					}
					catch (char* error)
					{
						cout << endl << "Error: " << error << endl;
					}

					system("pause");
					break;
				}
				case 4:
				{
					char publisher[100];

					cout << "Publisher: ";
					cin.ignore();
					cin.getline(publisher, 100);
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					try
					{
						vector<int> searchResults = lookUpBookPublisher(publisher, booklist);
					}
					catch (char* error)
					{
						cout << endl << "Error: " << error << endl;
					}

					system("pause");
					break;
				}
				case 5:
					break;
				default:
					cout << "You did not enter a valid option (1, 2, 3, 4, or 5). Please try again." << endl;
					system("pause");
				}
			} while (choice != 5);
			break;
		}

		case 2:
			inventory.addBook(booklist);
			break;

		case 3:
		{
			int choice;
			bool validChoice = false;
			do{
				system("CLS");

				time(&menutime);
				timeInfo = localtime(&menutime);
				strftime(current, 80, "%m/%d/%Y %I:%M%p", timeInfo);
				puts(current);

				cout << "Serendipity Booksellers" << endl << "Inventory Menu - Edit Book" << endl << endl;
				cout << "What book would you like to edit? Search the book by" << endl;
				cout << "1. ISBN" << endl;
				cout << "2. Title" << endl;
				cout << "3. Author" << endl;
				cout << "4. Publisher" << endl;
				cout << "5. Return to the Inventory Menu." << endl;
				cout << "Enter your Choice: ";
				cin >> choice;
				if (!cin){
					cin.clear();
					choice = 0;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				cout << endl;

				switch (choice){
				case 1:
				{
					char isbn[13];
					cout << "ISBN: ";
					cin.ignore();
					cin.getline(isbn, 13);
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					vector<int> searchResults = lookUpBookISBN(isbn, booklist);
					if (searchResults.size() != 0){
						cout << "Which book do you want to edit? Or enter 0 to cancel: ";

						unsigned int bookChoice;
						validChoice = false;
						while (validChoice != true){
							cin >> bookChoice;
							if (!cin){
								cin.clear();
								bookChoice = searchResults.size() + 1;
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
							}
							if (bookChoice > searchResults.size()) cout << "Invalid selection. Please try again: ";
							else validChoice = true;
						}

						cout << endl;
						if (bookChoice != 0) editBook(searchResults[bookChoice - 1], booklist);
						cout << endl;
					}
					else{
						cout << "No books found using search criteria." << endl;
						system("pause");
					}
					break;
				}
				case 2:
				{
					char title[100];
					cout << "Title: ";
					cin.ignore();
					cin.getline(title, 100);
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					vector<int> searchResults = lookUpBookTitle(title, booklist);
					if (searchResults.size() != 0){
						cout << "Which book do you want to edit? Or enter 0 to cancel: ";

						unsigned int bookChoice;
						validChoice = false;
						while (validChoice != true){
							cin >> bookChoice;
							if (!cin){
								cin.clear();
								bookChoice = searchResults.size() + 1;
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
							}
							if (bookChoice > searchResults.size()) cout << "Invalid selection. Please try again: ";
							else validChoice = true;
						}

						cout << endl;
						if (bookChoice != 0) editBook(searchResults[bookChoice - 1], booklist);
						cout << endl;
					}
					else{
						cout << "No books found using search criteria." << endl;
						system("pause");
					}
					break;
				}
				case 3:
				{
					char author[100];
					cout << "Author: ";
					cin.ignore();
					cin.getline(author, 100);
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					vector<int> searchResults = lookUpBookAuthor(author, booklist);
					if (searchResults.size() != 0){
						cout << "Which book do you want to edit? Or enter 0 to cancel: ";

						unsigned int bookChoice;
						validChoice = false;
						while (validChoice != true){
							cin >> bookChoice;
							if (!cin){
								cin.clear();
								bookChoice = searchResults.size() + 1;
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
							}
							if (bookChoice > searchResults.size()) cout << "Invalid selection. Please try again: ";
							else validChoice = true;
						}

						cout << endl;
						if (bookChoice != 0) searchResults[bookChoice - 1], booklist;
						cout << endl;
					}
					else{
						cout << "No books found using search criteria." << endl;
						system("pause");
					}
					break;
				}
				case 4:
				{
					char publisher[100];
					cout << "Publisher: ";
					cin.ignore();
					cin.getline(publisher, 100);
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					vector<int> searchResults = lookUpBookPublisher(publisher, booklist);
					if (searchResults.size() != 0){
						cout << "Which book do you want to edit? Or enter 0 to cancel: ";

						unsigned int bookChoice;
						validChoice = false;
						while (validChoice != true){
							cin >> bookChoice;
							if (!cin){
								cin.clear();
								bookChoice = searchResults.size() + 1;
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
							}
							if (bookChoice > searchResults.size()) cout << "Invalid selection. Please try again: ";
							else validChoice = true;
						}

						cout << endl;
						if (bookChoice != 0) editBook(searchResults[bookChoice - 1], booklist);
						cout << endl;
					}
					else{
						cout << "No books found using search criteria." << endl;
						system("pause");
					}
					break;
				}
				case 5:
					break;
				default:
					cout << "You did not enter a valid option (1, 2, 3, 4, or 5). Please try again." << endl;
					system("pause");
				}
			} while (choice != 5);
			break;
		}

		case 4:
		{
			int choice;
			bool validChoice = false;
			do{
				system("CLS");

				time(&menutime);
				timeInfo = localtime(&menutime);
				strftime(current, 80, "%m/%d/%Y %I:%M%p", timeInfo);
				puts(current);

				cout << "Serendipity Booksellers" << endl << "Inventory Menu - Delete Book" << endl << endl;
				cout << "What book would you like to delete? Search the book by" << endl;
				cout << "1. ISBN" << endl;
				cout << "2. Title" << endl;
				cout << "3. Author" << endl;
				cout << "4. Publisher" << endl;
				cout << "5. Return to the Inventory Menu." << endl;
				cout << "Enter your Choice: ";
				cin >> choice;
				if (!cin){
					cin.clear();
					choice = 0;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				cout << endl;

				switch (choice){
				case 1:
				{
					char isbn[13];
					cout << "ISBN: ";
					cin.ignore();
					cin.getline(isbn, 13);
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					vector<int> searchResults = lookUpBookISBN(isbn, booklist);
					if (searchResults.size() != 0){
						cout << "Which book do you want to delete? Or enter 0 to cancel: ";

						unsigned int bookChoice;
						validChoice = false;
						while (validChoice != true){
							cin >> bookChoice;
							if (!cin){
								cin.clear();
								bookChoice = searchResults.size() + 1;
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
							}
							if (bookChoice > searchResults.size()) cout << "Invalid selection. Please try again: ";
							else validChoice = true;
						}

						cout << endl;
						if (bookChoice != 0){
							cout << "Are you sure? This will completely remove the book from the inventory." << endl
								<< "Deletion cannot be reversed!" << endl << "Enter 1 for yes, or 0 for no: ";
							int confirmation;
							validChoice = false;
							while (validChoice != true){
								cin >> confirmation;
								if (!cin){
									cin.clear();
									confirmation = -1;
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
								}
								if (confirmation < 0 || confirmation > 1) cout << "Invalid choice. Please try again: ";
								else validChoice = true;
							}

							booklist.erase(booklist.begin() + searchResults[bookChoice - 1]);
							writeList(booklist);
							cout << endl << "Deletion complete." << endl;
							system("pause");
						}
						cout << endl;
					}
					else{
						cout << "No books found using search criteria." << endl;
						system("pause");
					}
					break;
				}
				case 2:
				{
					char title[100];
					cout << "Title: ";
					cin.ignore();
					cin.getline(title, 100);
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					vector<int> searchResults = lookUpBookTitle(title, booklist);
					if (searchResults.size() != 0){
						cout << "Which book do you want to delete? Or enter 0 to cancel: ";

						unsigned int bookChoice;
						validChoice = false;
						while (validChoice != true){
							cin >> bookChoice;
							if (!cin){
								cin.clear();
								bookChoice = searchResults.size() + 1;
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
							}
							if (bookChoice > searchResults.size()) cout << "Invalid selection. Please try again: ";
							else validChoice = true;
						}

						cout << endl;
						if (bookChoice != 0){
							cout << "Are you sure? This will completely remove the book from the inventory." << endl
								<< "Deletion cannot be reversed!" << endl << "Enter 1 for yes, or 0 for no: ";
							int confirmation;
							validChoice = false;
							while (validChoice != true){
								cin >> confirmation;
								if (!cin){
									cin.clear();
									confirmation = -1;
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
								}
								if (confirmation < 0 || confirmation > 1) cout << "Invalid choice. Please try again: ";
								else validChoice = true;
							}

							booklist.erase(booklist.begin() + searchResults[bookChoice - 1]);
							writeList(booklist);
							cout << endl << "Deletion complete." << endl;
							system("pause");
						}
						cout << endl;
					}
					else{
						cout << "No books found using search criteria." << endl;
						system("pause");
					}
					break;
				}
				case 3:
				{
					char author[100];
					cout << "Author: ";
					cin.ignore();
					cin.getline(author, 100);
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					vector<int> searchResults = lookUpBookAuthor(author, booklist);
					if (searchResults.size() != 0){
						cout << "Which book do you want to delete? Or enter 0 to cancel: ";

						unsigned int bookChoice;
						validChoice = false;
						while (validChoice != true){
							cin >> bookChoice;
							if (!cin){
								cin.clear();
								bookChoice = searchResults.size() + 1;
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
							}
							if (bookChoice > searchResults.size()) cout << "Invalid selection. Please try again: ";
							else validChoice = true;
						}

						cout << endl;
						if (bookChoice != 0){
							cout << "Are you sure? This will completely remove the book from the inventory." << endl
								<< "Deletion cannot be reversed!" << endl << "Enter 1 for yes, or 0 for no: ";
							int confirmation;
							validChoice = false;
							while (validChoice != true){
								cin >> confirmation;
								if (!cin){
									cin.clear();
									confirmation = -1;
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
								}
								if (confirmation < 0 || confirmation > 1) cout << "Invalid choice. Please try again: ";
								else validChoice = true;
							}

							booklist.erase(booklist.begin() + searchResults[bookChoice - 1]);
							writeList(booklist);
							cout << endl << "Deletion complete." << endl;
							system("pause");
						}
						cout << endl;
					}
					else{
						cout << "No books found using search criteria." << endl;
						system("pause");
					}
					break;
				}
				case 4:
				{
					char publisher[100];
					cout << "Publisher: ";
					cin.ignore();
					cin.getline(publisher, 100);
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					vector<int> searchResults = lookUpBookPublisher(publisher, booklist);
					if (searchResults.size() != 0){
						cout << "Which book do you want to delete? Or enter 0 to cancel: ";

						unsigned int bookChoice;
						validChoice = false;
						while (validChoice != true){
							cin >> bookChoice;
							if (!cin){
								cin.clear();
								bookChoice = searchResults.size() + 1;
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
							}
							if (bookChoice > searchResults.size()) cout << "Invalid selection. Please try again: ";
							else validChoice = true;
						}

						cout << endl;
						if (bookChoice != 0){
							cout << "Are you sure? This will completely remove the book from the inventory." << endl
								<< "Deletion cannot be reversed!" << endl << "Enter 1 for yes, or 0 for no: ";
							int confirmation;
							validChoice = false;
							while (validChoice != true){
								cin >> confirmation;
								if (!cin){
									cin.clear();
									confirmation = -1;
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
								}
								if (confirmation < 0 || confirmation > 1) cout << "Invalid choice. Please try again: ";
								else validChoice = true;
							}

							booklist.erase(booklist.begin() + searchResults[bookChoice - 1]);
							writeList(booklist);
							cout << endl << "Deletion complete." << endl;
							system("pause");
						}
						cout << endl;
					}
					else{
						cout << "No books found using search criteria." << endl;
						system("pause");
					}
					break;
				}
				case 5:
					break;
				default:
					cout << "You did not enter a valid option (1, 2, 3, 4, or 5). Please try again." << endl;
					system("pause");
				}
			} while (choice != 5);
			break;
		}
		case 5:
			break;
		default:
			cout << "You did not enter a valid option (1, 2, 3, 4, or 5). Please try again." << endl;
			system("pause");
		}

	} while (inventoryChoice != 5);
}

void Inventory::sortByName(vector<Book>& booklist)
{
	for (unsigned int i = 0; i < booklist.size(); i++){
		for (unsigned int j = i + 1; j < booklist.size(); j++)
		{
			if (booklist[i].getTitle() > booklist[j].getTitle()){
				Book temp = booklist[i];
				booklist[i] = booklist[j];
				booklist[j] = temp;
			}
		}
	}
}


vector<int> Inventory::lookUpBookISBN(char isbn[], vector<Book>& booklist)
{
	cout << "Search results:" << endl << endl;

	vector<int> foundBooks;
	int count = 0;
	for (unsigned int i = 0; i < booklist.size(); i++)
	{
		if (isbn == booklist[i].getISBN())
		{
			foundBooks.push_back(i);
			printf("%d.\n", ++count);
			booklist[i].print();
			cout << endl;
		}
	}
	if (foundBooks.size() == 0){
		throw "No books found using search criteria.";
	}

	return foundBooks;
}

vector<int> Inventory::lookUpBookTitle(char title[], vector<Book>& booklist)
{
	cout << "Search results:" << endl << endl;

	vector<int> foundBooks;
	int count = 0;
	for (unsigned int i = 0; i < booklist.size(); i++)
	{
		if (title == booklist[i].getTitle())
		{
			foundBooks.push_back(i);
			printf("%d.\n", ++count);
			booklist[i].print();
			cout << endl;
		}
	}
	if (foundBooks.size() == 0){
		throw "No books found using search criteria.";
	}

	return foundBooks;
}

vector<int> Inventory::lookUpBookAuthor(char author[], vector<Book>& booklist)
{
	cout << "Search results:" << endl << endl;

	vector<int> foundBooks;
	int count = 0;
	for (unsigned int i = 0; i < booklist.size(); i++)
	{
		if (author == booklist[i].getAuthor())
		{
			foundBooks.push_back(i);
			printf("%d.\n", ++count);
			booklist[i].print();
			cout << endl;
		}
	}
	if (foundBooks.size() == 0){
		throw "No books found using search criteria.";
	}

	return foundBooks;
}

vector<int> Inventory::lookUpBookPublisher(char publisher[], vector<Book>& booklist)
{
	cout << "Search results:" << endl << endl;

	vector<int> foundBooks;
	int count = 0;
	for (unsigned int i = 0; i < booklist.size(); i++)
	{
		if (publisher == booklist[i].getPublisher())
		{
			foundBooks.push_back(i);
			printf("%d.\n", ++count);
			booklist[i].print();
			cout << endl;
		}
	}
	if (foundBooks.size() == 0){
		throw "No books found using search criteria.";
	}

	return foundBooks;
}

void Inventory::addBook(vector<Book>& booklist)
{
	system("CLS");

	bool validChoice = false;
	char isbn[13], title[100], author[100], publisher[100];
	int quantity;
	double wholesaleCost = 0;
	double retailPrice = 0;
	time_t rawtime;
	time(&rawtime);

	struct tm * timeInfo;
	char current[80] = "";
	timeInfo = localtime(&rawtime);
	strftime(current, 80, "%m/%d/%Y %I:%M%p", timeInfo);
	puts(current);

	cout << "Serendipity Booksellers" << endl << "Inventory Menu - Add Book" << endl << endl;
	cout << "Please enter the following information." << endl << "(Enter only '0' to return to the Inventory Menu)" << endl << endl;
	cout << "ISBN: ";
	cin.ignore();
	cin.getline(isbn, 13);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (strcmp(isbn, "0") != 0)
	{
		cout << "Title: ";
		cin.getline(title, 100);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Author: ";
		cin.getline(author, 100);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Publisher: ";
		cin.getline(publisher, 100);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Quantity-On-Hand: ";
		validChoice = false;
		while (validChoice != true){
			cin >> quantity;
			if (!cin){
				cin.clear();
				quantity = -1;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if (quantity < 0) cout << "Invalid input. Please try again: ";
			else validChoice = true;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;
		cout << "Wholesale Cost: ";
		validChoice = false;
		while (validChoice != true){
			cin >> wholesaleCost;
			if (!cin){
				cin.clear();
				wholesaleCost = -1;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if (wholesaleCost < 0) cout << "Invalid input. Please try again: ";
			else validChoice = true;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;
		cout << "Retail Price: ";
		validChoice = false;
		while (validChoice != true){
			cin >> retailPrice;
			if (!cin){
				cin.clear();
				retailPrice = -1;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if (retailPrice < 0) cout << "Invalid input. Please try again: ";
			else validChoice = true;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;

		Book book(isbn, title, author, publisher, quantity, wholesaleCost, retailPrice, rawtime);

		booklist.push_back(book);
		writeList(booklist);
		cout << "The book has been successfully added." << endl;
		system("pause");
	}
}

void Inventory::editBook(int location, vector<Book>& bookList)
{
	bool validChoice;
	int choice;
	do{
		system("CLS");

		time_t menutime;
		struct tm * timeInfo;
		char current[80] = "";
		time(&menutime);
		timeInfo = localtime(&menutime);
		strftime(current, 80, "%m/%d/%Y %I:%M%p", timeInfo);
		puts(current);

		cout << "Serendipity Booksellers" << endl << "Inventory Menu - Edit Book" << endl << endl;
		cout << "Current book information:" << endl << endl;
		bookList[location].print();
		
		cout << endl << "Which information would you like to edit?" << endl;
		cout << "1. ISBN" << endl;
		cout << "2. Title" << endl;
		cout << "3. Author" << endl;
		cout << "4. Publisher" << endl;
		cout << "5. Quantity-On-Hand" << endl;
		cout << "6. Retail Price" << endl;
		cout << "7. Return to the previous menu." << endl;
		cout << "Enter your Choice: ";
		cin >> choice;
		if (!cin){
			cin.clear();
			choice = 0;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << endl;

		switch (choice)
		{
		case 1:
		{
			char isbn[13];
			cout << "Enter the new ISBN: ";
			cin.ignore();
			cin.getline(isbn, 13);
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			bookList[location].setISBN(isbn);
			writeList(bookList);
			cout << endl << "ISBN has been successfully edited." << endl << endl;
			system("pause");
			break;
		}
		case 2:
		{
			char title[100];
			cout << "Enter the new title: ";
			cin.ignore();
			cin.getline(title, 100);
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			bookList[location].setTitle(title);
			writeList(bookList);
			cout << endl << "Title has been successfully edited." << endl << endl;
			system("pause");
			break;
		}
		case 3:
		{
			char author[100];
			cout << "Enter the new author: ";
			cin.ignore();
			cin.getline(author, 100);
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			bookList[location].setAuthor(author);
			writeList(bookList);
			cout << endl << "Author has been successfully edited." << endl << endl;
			system("pause");
			break;
		}
		case 4:
		{
			char publisher[100];
			cout << "Enter the new publisher: ";
			cin.ignore();
			cin.getline(publisher, 100);
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			bookList[location].setPublisher(publisher);
			writeList(bookList);
			cout << endl << "Publisher has been successfully edited." << endl << endl;
			system("pause");
			break;
		}
		case 5:
		{
			int quantity;
			cout << "Enter the new quantity-on-hand: ";
			validChoice = false;
			while (validChoice != true){
				cin >> quantity;
				if (!cin){
					cin.clear();
					quantity = -1;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				if (quantity < 0) cout << "Invalid input. Please try again: ";
				else validChoice = true;
			}
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			bookList[location].setQuantity(quantity);
			writeList(bookList);
			cout << endl << "Quantity-on-hand has been successfully edited." << endl << endl;
			system("pause");
			break;
		}
		case 6:
		{
			double retail;
			cout << "Enter the new retail price: ";
			validChoice = false;
			while (validChoice != true){
				cin >> retail;
				if (!cin){
					cin.clear();
					retail = -1;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				if (retail < 0) cout << "Invalid input. Please try again: ";
				else validChoice = true;
			}
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			bookList[location].setRetail(retail);
			writeList(bookList);
			cout << endl << "Retail price has been successfully edited." << endl << endl;
			system("pause");
			break;
		}
		case 7:
			break;
		default:
			cout << "You did not enter a valid option(1, 2, 3, 4, 5, 6, or 7). Please try again." << endl << endl;
		}
	} while (choice != 7);
}

vector<Book> Inventory::readList()
{
	int numBooks;	//the first thing in the booklist file
	vector<Book> booklist;
	vector<Book> *a;	//just to make sure that the booklist vector is created properly
	ifstream ifs("bookList.txt", ios::in | ios::binary);	//opens input file

	if (ifs)
	{
		ifs.read(reinterpret_cast<char *>(&numBooks), sizeof(numBooks));	//read number of Book objects in the file, stored at beginning of file, into numBooks variable

		a = new vector<Book>;

		if (a == nullptr)	//if memory couldnt be allocated, exits
		{
			cout << "Memory could not be allocated..." << endl << endl;
			system("pause");
			exit(-1);
		}

		for (int i = 0; i < numBooks; i++)	//goes through the file reading the number of Book objects that the file said it containted into the booklist vector
		{
			Book newbook;	//temp Book object
			ifs.read(reinterpret_cast<char *>(&newbook), sizeof(newbook));	//reads a single object from file
			booklist.push_back(newbook);	//puts the Book at the END of the vector

		}
	}
	ifs.close();	//close input file
	return booklist;	//returns vector of Book class objects
}

void Inventory::writeList(vector<Book> list)
{
	ofstream ofs("bookList.txt", ios::out | ios::binary);	//
	int numBooks = list.size();
	ofs.write(reinterpret_cast<char *>(&numBooks), sizeof(numBooks));
	for (int i = 0; i < numBooks; i++)
	{
		ofs.write(reinterpret_cast<char *>(&list[i]), sizeof(list[i]));
	}
	ofs.close();
}