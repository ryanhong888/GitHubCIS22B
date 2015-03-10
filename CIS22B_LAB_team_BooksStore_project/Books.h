//============================================================================================================================
//	Class:			CIS 22B 
//	Instructor:		Manish Goel
//	Class hours:	TTh- 3:30 pm - 5:20 pm
//	Room:			AT204
//					Team Project
//	Description:	Class InventoryBook.h
//
//	Written by:		Ryan T. Hong
//	Date:			Feb. 24th, 2015
//============================================================================================================================
#ifndef BOOKS_H
#define BOOKS_H
#include <string>
#include <iostream>

using namespace std;

class Books
{
protected:

	string	sIsbn,		//	unique id for books in inventory
			sTitle,			//	Title of book
			sAuthor,		//	Author of book
			sEntryDate,	//	The date the book was added to the inventory
			sPublisher;		//	The company that publishes the book
	int		iUnits;	//	Number of books on hand
	double	dWholesale,	//	Quote buy from Serendipity bookstore
			dRetail;	//	Quote sale to customer

public:
	//	Default constructor
	Books()
	{
		set("", "", "", "", "", 0, 0.0, 0.0);
	}

	//	Overloaded constructor
	Books(string sID, string sName, string sWriter, string sPub, string sDate, int units, double dWholeS, double dRet)
	{
		cout << "Constructor running" << endl;
		set(sID, sName, sWriter, sPub, sDate, units, dWholeS, dRet);
	}
	
	/*Books(Books &obj)
	{
		cout << "Copy constructor running" << endl;
		sIsbn = obj.sIsbn;
		sTitle = obj.sTitle;
		sAuthor = obj.sAuthor;
		sEntryDate = obj.sEntryDate;
		sPublisher = obj.sPublisher;
		iUnits = obj.iUnits;
		dWholesale = obj.dWholesale;
		dRetail = obj.dRetail;
	}*/
	
	virtual ~Books()
	{
		cout << "Destructor running" << endl;
	}

	//	Mutator function
	void setIsbn(string);
	void setTitle(string);
	void setAuthor(string);
	void setDate(string);
	void setPublisher(string);
	void setBookunits(int);
	void setWholesale(double);
	void setRetail(double);

	
	//	Overloaded member function
	void set(string, string, string, string, string, int, double, double);
	//	Overloaded member function
	void set(string, string, string, string, string, string, string, string);
	//	Overloaded member function
	void set(string, string, string, string, string, int, int, double, double);

	//	Accessor functions
	string getISBN() const;

	string getTitle() const;

	string getAuthor() const;

	string getDate() const;

	string getPublisher() const;

	int getBookunits() const;

	double getWholesale() const;

	double getRetail() const;

	// Friends Overload operator << and >> prototypes
	friend ostream &operator << (ostream &, const Books &);
	friend istream &operator >> (istream &, Books &);
	//	Load the unsorted list to vector array
	virtual void loadList(Books [], int);
	virtual void inventoryMenu();
	virtual void editMenu();

	virtual void modifyBook(vector<Books> &, int, int);
	//	Test open file pass or fail
	virtual bool editFile(fstream &, string);
	virtual void loadFile(const vector<Books> &, int);


	virtual void sortISBN(Books Array[], int arraySize);
	virtual void sortTitle(Books Array[], int arraySize);
	virtual void sortAuthor(Books Array[], int arraySize);
	virtual void sortPublisher(Books Array[], int arraySize);
	virtual void sortDate(Books Array[], int arraySize);
	virtual void sortUnits(Books Array[], int arraySize);
	virtual void sortWholesale(Books Array[], int arraySize);
	virtual void sortRetail(Books Array[], int arraySize);

	virtual int searchISBN(Books array[], int numElems, string value);
	virtual int searchTitle(Books array[], int numElems, string value);
	virtual int searchAuthor(Books array[], int numElems, string value);
	virtual int searchPublisher(Books array[], int numElems, string value);
	virtual int searchDate(Books array[], int numElems, string value);
	virtual int searchUnits(Books Array[], int numElems, int value);
	virtual int searchWholesale(Books Array[], int numElems, double value);
	virtual int searchRetail(Books Array[], int numElems, double value);

	virtual void remove(int);
	//	No need to use displayBooks member funtion because I do oveloaded operator << and >>
	//	Display member function
	//void displayBooks() const;
};

#endif

