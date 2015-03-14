#define _CRT_SECURE_NO_WARNINGS

#include "Inventory.h"
#include "Book.h"
#include <vector>
#include <fstream>

using namespace std;

void Inventory::inventoryMenu()
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

		cout << "Serendipity Booksellers" << endl << "Inventory Database" << endl;
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
				
				cout << "Serendipity Booksellers" << endl << "How would you like to look up a book?" << endl;
				cout << "1. ISBN" << endl;
				cout << "2. Title" << endl;
				cout << "3. Author" << endl;
				cout << "4. Publisher" << endl;
				cout << "5. Return to the Inventory Menu." << endl;
				cout << "Enter your Choice: ";
				cin >> choice;
				cout << endl;

				switch (choice){
				case 1:
				{
					unsigned int isbn;
					cout << "ISBN: ";
					cin >> isbn;
					if (!cin){
						cin.clear();
						isbn = 0;
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					vector<int> searchResults = lookUpBookISBN(isbn, booklist);
					if (searchResults.size() == 0){
						cout << "No books found using search criteria." << endl;
						system("pause");
					}
					else system("pause");
					break;
				}
				case 2:
				{
					char title[100];
					cout << "Title: ";
					cin.ignore();
					cin.getline(title, 100);
					vector<int> searchResults = lookUpBookTitle(title, booklist);
					if (searchResults.size() == 0){
						cout << "No books found using search criteria." << endl;
						system("pause");
					}
					else system("pause");
					break;
				}
				case 3:
				{
					char author[100];
					cout << "Author: ";
					cin.ignore();
					cin.getline(author, 100);
					vector<int> searchResults = lookUpBookAuthor(author, booklist);
					if (searchResults.size() == 0){
						cout << "No books found using search criteria." << endl;
						system("pause");
					}
					else system("pause");
					break;
				}
				case 4:
				{
					char publisher[100];
					cout << "Publisher: ";
					cin.ignore();
					cin.getline(publisher, 100);
					vector<int> searchResults= lookUpBookPublisher(publisher, booklist);
					if (searchResults.size() == 0){
						cout << "No books found using search criteria." << endl;
						system("pause");
					}
					else system("pause");
					break;
				}
				case 5:
					break;
				default:
					cout << "You did not enter a valid option (1, 2, 3, 4, or 5). Please try again." << endl;
					system("pause");
					break;
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

				cout << "Serendipity Booksellers" << endl << "What book would you like to edit? Search the book by" << endl;
				cout << "1. ISBN" << endl;
				cout << "2. Title" << endl;
				cout << "3. Author" << endl;
				cout << "4. Publisher" << endl;
				cout << "5. Return to the Inventory Menu." << endl;
				cout << "Enter your Choice: ";
				cin >> choice;
				cout << endl;

				switch (choice){
				case 1:
				{
					unsigned int isbn;
					cout << "ISBN: ";
					cin >> isbn;
					if (!cin){
						cin.clear();
						isbn = 0;
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}

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

				cout << "Serendipity Booksellers" << endl << "What book would you like to delete? Search the book by" << endl;
				cout << "1. ISBN" << endl;
				cout << "2. Title" << endl;
				cout << "3. Author" << endl;
				cout << "4. Publisher" << endl;
				cout << "5. Return to the Inventory Menu." << endl;
				cout << "Enter your Choice: ";
				cin >> choice;
				cout << endl;

				switch (choice){
				case 1:
				{
					unsigned int isbn;
					cout << "ISBN: ";
					cin >> isbn;
					if (!cin){
						cin.clear();
						isbn = 0;
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}

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

vector<int> Inventory::lookUpBookISBN(unsigned int isbn, vector<Book>& booklist)
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

	return foundBooks;
}

void Inventory::addBook(vector<Book>& booklist)
{
	system("CLS");

	unsigned int isbn, quantity;
	char title[100], author[100], publisher[100]; // , dateAdded[100] = "";
	double wholesaleCost = 0;
	double retailPrice = 0;
	time_t rawtime;
	time(&rawtime);

	struct tm * timeInfo;
	char current[80] = "";
	timeInfo = localtime(&rawtime);
	strftime(current, 80, "%m/%d/%Y %I:%M%p", timeInfo);
	puts(current);

	cout << "Serendipity Booksellers" << endl << "Please enter the following information." << endl << "(Enter only '0' to return to the Inventory Menu)" << endl << endl;
	cout << "ISBN: ";
	cin >> isbn;
	if (isbn != 0)
	{
		cout << "Title: ";
		cin.ignore();
		cin.getline(title, 100);
		cout << "Author: ";
		cin.getline(author, 100);
		cout << "Publisher: ";
		cin.getline(publisher, 100);
		cout << "Quantity-On-Hand: ";
		cin >> quantity;
		cout << "Wholesale Cost: ";
		cin >> wholesaleCost;
		cout << "Retail Price: ";
		cin >> retailPrice;
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
	int choice;
	do{
		cout << "Serendipity Booksellers" << endl << "Which information would you like to edit?" << endl;
		cout << "1. ISBN" << endl;
		cout << "2. Title" << endl;
		cout << "3. Author" << endl;
		cout << "4. Publisher" << endl;
		cout << "5. Quantity-On-Hand" << endl;
		cout << "6. Retail Price" << endl;
		cout << "7. Return to the previous menu." << endl;
		cout << "Enter your Choice: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
		{
			unsigned int isbn;
			cout << "Enter the new ISBN: ";
			cin >> isbn;
			cin.clear();
			bookList[location].setISBN(isbn);
			writeList(bookList);
			cout << endl << "ISBN has been successfully edited. New book information:" << endl << endl;
			bookList[location].print();
			cout << endl;
			break;
		}
		case 2:
		{
			char title[100];
			cout << "Enter the new title: ";
			cin.ignore();
			cin.getline(title, 100);
			bookList[location].setTitle(title);
			writeList(bookList);
			cout << endl << "Title has been successfully edited. New book information:" << endl << endl;
			bookList[location].print();
			break;
		}
		case 3:
		{
			char author[100];
			cout << "Enter the new author: ";
			cin.ignore();
			cin.getline(author, 100);
			bookList[location].setAuthor(author);
			writeList(bookList);
			cout << endl << "Author has been successfully edited. New book information:" << endl << endl;
			bookList[location].print();
			cout << endl;
			break;
		}
		case 4:
		{
			char publisher[100];
			cout << "Enter the new publisher: ";
			cin.ignore();
			cin.getline(publisher, 100);
			bookList[location].setPublisher(publisher);
			writeList(bookList);
			cout << endl << "Publisher has been successfully edited. New book information:" << endl << endl;
			bookList[location].print();
			cout << endl;
			break;
		}
		case 5:
		{
			unsigned int quantity;
			cout << "Enter the new quantity-on-hand: ";
			cin >> quantity;
			cin.clear();
			bookList[location].setQuantity(quantity);
			writeList(bookList);
			cout << endl << "Quantity-on-hand has been successfully edited. New book information:" << endl << endl;
			bookList[location].print();
			cout << endl;
			break;
		}
		case 6:
		{
			double retail;
			cout << "Enter the new retail price: ";
			cin >> retail;
			cin.clear();
			bookList[location].setRetail(retail);
			writeList(bookList);
			cout << endl << "Retail price has been successfully edited. New book information:" << endl << endl;
			bookList[location].print();
			cout << endl;
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
	int numBooks;
	vector<Book> booklist;
	vector<Book> *a;
	ifstream ifs("bookList.txt", ios::in | ios::binary);

	if (ifs)
	{
		ifs.read(reinterpret_cast<char *>(&numBooks), sizeof(numBooks));

		a = new vector<Book>;

		if (a == nullptr)
		{
			cout << "Memory could not be allocated..." << endl << endl;
			system("pause");
			exit(-1);
		}

		for (int i = 0; i < numBooks; i++)
		{
			Book newbook;
			ifs.read(reinterpret_cast<char *>(&newbook), sizeof(newbook));
			booklist.push_back(newbook);

		}
	}
	ifs.close();
	return booklist;
}

void Inventory::writeList(vector<Book> list)
{
	ofstream ofs("bookList.txt", ios::out | ios::binary);
	int numBooks = list.size();
	ofs.write(reinterpret_cast<char *>(&numBooks), sizeof(numBooks));
	for (int i = 0; i < numBooks; i++)
	{
		ofs.write(reinterpret_cast<char *>(&list[i]), sizeof(list[i]));
	}
	ofs.close();
}