//============================================================================================================================
//	Class:			CIS 22B 
//	Instructor:		Manish Goel
//	Class hours:	TTh- 3:30 pm - 5:20 pm
//	Room:			AT204
//					Team Project
//	Description:	Implement InventoryBook.cpp
//
//	Written by:		Ryan T. Hong
//	Date:			Feb. 24th, 2015
//============================================================================================================================
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>									//	This is for I/O file
#include <iomanip>									//	This is for alignment
#include <vector>
#include "Books.h"

using namespace std;

//	mutator member function
void Books::setIsbn(string sID)
{
	sIsbn = sID;
}
void Books::setTitle(string sName)
{
	sTitle = sName;
}
void Books::setAuthor(string sWriter)
{
	sAuthor = sWriter;
}
void Books::setDate(string sDate)
{
	sEntryDate = sDate;
}
void Books::setPublisher(string sPub)
{
	sPublisher = sPub;
}
void Books::setBookunits(int units)
{
	iUnits = units;
}
void Books::setWholesale(double dWholeS)
{
	dWholesale = dWholeS;
}
void Books::setRetail(double dRet)
{
	dRetail = dRet;
}

//	Overload member function
void Books::set(string sID, string sName, string sWriter, string sPub, string sDate, int units, double dWholeS, double dRet)
{
	sIsbn = sID;
	sTitle = sName;
	sAuthor = sWriter;
	sEntryDate = sDate;
	sPublisher = sPub;
	iUnits = units;
	dWholesale = dWholeS;
	dRetail = dRet;
}
//	Overload member function
void Books::set(string sID, string sName, string sWriter, string sPub, string sDate, string units, string dWholeS, string dRet)
{
	sIsbn = sID;
	sTitle = sName;
	sAuthor = sWriter;
	sEntryDate = sDate;
	sPublisher = sPub;
	iUnits = static_cast<int>(atof(units.c_str()));
	dWholesale = atof(dWholeS.c_str());
	dRetail = atof(dRet.c_str());
}

//	Accessor member functions
string Books::getISBN() const
{
	return sIsbn;
}

string Books::getTitle() const
{
	return sTitle;
}

string Books::getAuthor() const
{
	return sAuthor;
}

string Books::getDate() const
{
	return sEntryDate;
}

string Books::getPublisher() const
{
	return sPublisher;
}

int Books::getBookunits() const
{
	return iUnits;
}
double Books::getWholesale() const
{
	return dWholesale;
}

double Books::getRetail() const
{
	return dRetail;
}

// Friends Overload operator << and >>
ostream &operator << (ostream &strm, const Books &obj)
{
	strm	<< "ISBN: " << obj.sIsbn << endl
			<< "Title: " << obj.sTitle << endl
			<< "Author: " << obj.sAuthor << endl
			<< "Publisher: " << obj.sPublisher << endl
			<< "Date entry: " << obj.sEntryDate << endl
			<< "Quantity: " << obj.iUnits << endl
			<< "Whole sale cost: $" << obj.dWholesale << endl
			<< "Retail price: $" << obj.dRetail << endl;
	return strm;
}

istream &operator >> (istream &strm, Books &obj)
{
	//	Prompt the user for the ISBN
	cout << "Enter ISBN: ";
	strm >> obj.sIsbn;	
	//	Prompt the user for the quantity of books
	cout << "Enter quantity: ";
	strm >> obj.iUnits;
	//	Prompt the user for the wholesale cost
	cout << "Enter whole sale cost: $";
	strm >> obj.dWholesale;
	//	Prompt the user for the retail price
	cout << "Enter retail price: $";
	strm >> obj.dRetail;

	return strm;
}



















//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//													editFile function
//	This program accepts a reference to an fstream object as an argument. The file is opened for input.  The functions true
//	upon success, false upon failure.
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool Books::editFile(fstream &file, string name)
{
	file.open(name, ios::out);
	if (file.fail())
		return false;
	else
		return true;
}














//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//													loadFile function
//	This program accept a const reference vector, and an integer as arguments. The purpost of this file is opened for written
//	data.  
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Books::loadFile(const vector <Books> &array, int size)
{
	string	sSuccess_open_file = "Success open the file.",
		sPath_request = "To specify your file at specific path, please enter similar to the format below.",
		sExample_path = "\"c:\\\\data\\\\studentScore.txt\"",
		sEnter_path = "Please enter your path here: ",
		sError_rd_file = "ERROR: Cannot open the file.",
		sFinish_adding = "Upload file complete.",
		sPath_name;
	int	iNumBooks;
	bool	ReadOK;
	fstream dataFile;

	cout << endl << sPath_request << endl << "\t\t" << sExample_path << endl << endl << sEnter_path;
	cin >> sPath_name;

	ReadOK = editFile(dataFile, sPath_name);
	if (ReadOK)
	{
		cout << sSuccess_open_file << endl << endl;
		for (int i = 0 ; i < size-1; i++)
		{
			dataFile << array[i].sIsbn << endl;
			dataFile << array[i].sTitle << endl;
			dataFile << array[i].sAuthor << endl;
			dataFile << array[i].sPublisher << endl;
			dataFile << array[i].sEntryDate << endl;
			dataFile << array[i].iUnits << endl;
			dataFile << array[i].dWholesale << endl;
			dataFile << array[i].dRetail << endl;
		}	
		dataFile.close();
		cout << endl << sFinish_adding << endl;
	}
	else
	{
		cout << sError_rd_file << endl;
	}
}















//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//														inventoryMenu function
//	This program accept no agrument as well as no return.
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Books::inventoryMenu()
{
	cout << "\t" << "\t" << "*****Welcome to Serendipity's Inventory*****" << endl << endl;
	cout << "\t" << "\t" << "\t" << "MENU" << endl;
	cout << "\t" << "1.  Search by ISBN" << endl << "\t" << "2.  Search by Title" << endl << "\t"
		 << "3.  Search by Author" << endl << "\t" << "4.  Add new book" << endl << "\t" << "5.  List all books" << endl
		 << "\t" << "6.  Enter 'Q' to exit" << endl;
	cout << "Enter your choice here: ";
}













//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//														editMenu function
//	This program accept no agrument as well as no return.
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Books::editMenu()
{

	cout << "\t" << "\t" << "\t" << "EDITOR'S ENTRY MENU" << endl;
	cout << "\t" << "1.  Delete this book" << endl << "\t" << "2.  Change ISBN" << endl << "\t"
		<< "3.  Change title" << endl << "\t" << "4.  Change author" << endl << "\t" << "5.  Change publisher" << endl
		<< "\t" << "6.  Change date entry" << endl << "\t" << "7.  Change book's quantity" << endl << "\t" 
		<< "8.  Change wholesale cost" << endl << "\t" << "9.  Change retail price" << endl << "\t"
		<< "10.  Press 'Q' to exit" << endl;
}













//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//														loadList function
//	This program accepts an array and integer for arguments.  It loads data from Books, and transfer to vector array.  It also
//	displays the result.
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Books::loadList(Books array[], int iAmount)
{
	char	cInput,
			ch;
	int	iLocation;
	string	sFindIt,
			sBooksInput,
			sInvalid_enter = "You did not enter 1, 2, 3, 4, or 5!",
			sRequest_selection = "Please choose an option or type 'Q' to exit program: ",
			sContinue_test = "Do you want to continue? (Y or N)";
	Books	addBook;
	vector <Books> vbookInfo;
	for (int i = 0; i < iAmount; i++)
	{
		vbookInfo.push_back(array[i]);
		//cout << "Book #" << i + 1 << ":" << endl;
		//	apply overloaded operator << to display book info
		//cout << vbookInfo[i] << endl;
	}
	//	Call inventory menu function
	system("CLS");
	inventoryMenu();
	cin >> cInput;
	while (cInput == '1' || cInput == '2' || cInput == '3' || cInput == '4' || cInput == '5')
	{
		switch (cInput)
		{
		case '1':
			//	sort by ISBN using call sortISBN function
			sortISBN(&vbookInfo[0], iAmount);
			cout << endl << "Please enter ISBN: ";
			cin >> sFindIt;
			//	Call searchISBN function to do binary search by ISBN and return a location of element of array
			iLocation = searchISBN(&vbookInfo[0], iAmount, sFindIt);
			if (iLocation > -1)	//	If the search return a location of ISBN, do following...
			{
				system("CLS");	//	Clear window
				cout << "ISBN search entry #" << iLocation + 1 << ":" << endl;
				//	apply overloaded operator << to display book info
				cout << endl << "\t" << vbookInfo[iLocation] << endl;
				//	Call editMenu function
				editMenu();
				//	Delete or modify book function call
				modifyBook(vbookInfo, iLocation, iAmount);
			}
			else                //	If search return nothing, print entry not found.
			{
				system("CLS");
				cout << "Entry is not found." << endl << endl;
			}
			break;
		case '2':
			//	sort by title using call sortTitle function
			sortTitle(&vbookInfo[0], iAmount);
			cout << endl << "Please enter Title: ";
			cin.ignore();
			getline(cin, sFindIt);
			//	Call searchTitle function to do binary search by title and return a location of element of array
			iLocation = searchTitle(&vbookInfo[0], iAmount, sFindIt);
			if (iLocation > -1)	//	If the search return a location of title, do following...
			{
				system("CLS");
				cout << "Title search entry #" << iLocation + 1 << ":" << endl;
				//	apply overloaded operator << to display book info
				cout << endl << "\t" << vbookInfo[iLocation] << endl;
				//	Call editMenu function
				editMenu();
				//	Delete or modify book function call
				modifyBook(vbookInfo, iLocation, iAmount);
			}
			else               //	If search return nothing, print entry not found.
			{
				system("CLS");
				cout << "Entry is not found." << endl << endl;
			}
			break;
		case '3':
			//	sort by author using call sortAuthor function
			sortAuthor(&vbookInfo[0], iAmount);
			cout << endl << "Please enter Author name (following order First, Middle int., and Last): ";
			cin.ignore();
			getline(cin, sFindIt);
			//	Call searchAuthor function to do binary search by author and return a location of element of array
			iLocation = searchAuthor(&vbookInfo[0], iAmount, sFindIt);
			if (iLocation > -1)	//	If the search return a location of author, do following...
			{
				system("CLS");
				cout << "Author search entry #" << iLocation + 1 << ":" << endl;
				//	apply overloaded operator << to display book info
				cout << endl << "\t" << vbookInfo[iLocation] << endl;
				//	Call editMenu function
				editMenu();
				//	Delete or modify book function call
				modifyBook(vbookInfo, iLocation, iAmount);
			}
			else               //	If search return nothing, print entry not found.
			{
				system("CLS");
				cout << "Entry is not found." << endl << endl;
			}
			break;
		case '4':
			cout << "Please enter following info to add a book: " << endl;
			//	apply overloaded operator >> to input isbn, quantity, wholesale, and retail price into book info
			cin >> addBook;	
			//	Title, author, publisher, and date entry can not use the cin >>; so, overload >> won't work
			cin.ignore();	//	Use ignore newline in the pipe line of cache to apply getline function to get right input
			cout << "Enter title: ";
			getline(cin, sBooksInput);			//	Apply getline to record title
			addBook.setTitle(sBooksInput);		//	Call setTitle to add entry to addBook instance
			cout << "Enter author: ";
			getline(cin, sBooksInput);			//	Apply getline to record author
			addBook.setAuthor(sBooksInput);		//	Call setauthor to add entry to addBook instance
			cout << "Enter publisher: ";
			getline(cin, sBooksInput);			//	Apply getline to record publisher
			addBook.setPublisher(sBooksInput);	//	Call setPublisher to add entry to addBook instance
			cout << "Enter date entry: ";
			getline(cin, sBooksInput);			//	Apply getline to record date entry
			addBook.setDate(sBooksInput);		//	Call setDate to add entry to addBook instance
			vbookInfo.push_back(addBook);		//	Add addBook instance to an element of vbookInfo instance
			break;
		case '5':
			//	Display data of each instances' pointer.
			for (int i = 0; i < vbookInfo.size(); i++)
			{
				cout << "Book #" << i + 1 << ":" << endl;
				//	apply overloaded operator << to display book info
				cout << vbookInfo[i] << endl;
				//bookInfo[i].displayBooks();
			}
			break;
		default: cout << sInvalid_enter << endl;
		}
		inventoryMenu();				//	Call menu function
		cout << endl << sRequest_selection;
		cin >> cInput;	
		//cin.ignore();
	} 
	loadFile(vbookInfo, iAmount);
	system("CLS");
}













//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//														modifyBook function
//	This program accepts a reference vector array and integer for arguments.  It loads a books data from Books, and allow user
//	to modify or todelete content.
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Books::modifyBook(vector <Books> &array, int element, int size)
{
	char ch;
	string	sInvalid_enter = "You did not enter 1, 2, 3, 4, or 5!",
			sRequest_selection = "Please choose an option or type 'Q' to exit program: ";

	cin >> ch;
	while (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
	{
		switch (ch)
		{
		case '1':
			array[element].sIsbn = "zzzzzzzzzz";			//	Apply getline to record title
			array[element].sTitle = "zzzzzzzzzz";
			array[element].sAuthor = "zzzzzzzzzz";
			array[element].sPublisher = "zzzzzzzzzz";
			array[element].sEntryDate = "zzzzzzzzzz";
			array[element].iUnits = 0;
			array[element].dWholesale = 0.0;
			array[element].dRetail = 0.0;
			//	sort by ISBN using call sortISBN function
			sortISBN(&array[0], size);
			for (int i = 0; i < array.size(); i++)
			{
				cout << "Before remove a book" << endl;
				//	apply overloaded operator << to display book info
				cout << array[i] << endl;
				//bookInfo[i].displayBooks();
			}
			array.pop_back();
			for (int i = 0; i < array.size(); i++)
			{
				cout << "After remove a book" << endl;
				//	apply overloaded operator << to display book info
				cout << array[i] << endl;
				//bookInfo[i].displayBooks();
			}
			break;
		case '2':
			cout << "Current ISBN: " << array[element].getISBN() << endl;
			cout << "Please enter new ISBN: ";
			cin >> array[element].sIsbn;
			cout << array[element] << endl;
			break;
		case '3':
			cout << "Current title: " << array[element].getTitle() << endl;
			cout << "Please enter new title: ";
			cin.ignore();
			getline(cin, array[element].sTitle);
			cout << array[element] << endl;
			break;
		case '4':
			cout << "Current author: " << array[element].getAuthor() << endl;
			cout << "Please enter new author: ";
			cin.ignore();
			getline(cin, array[element].sAuthor);
			cout << array[element] << endl;
			break;
		case '5':
			cout << "Current publisher: " << array[element].getPublisher() << endl;
			cout << "Please enter new title: ";
			cin.ignore();
			getline(cin, array[element].sPublisher);
			cout << array[element] << endl;
			break;
		case '6':
			cout << "Current entry date: " << array[element].getDate() << endl;
			cout << "Please enter new entry date: ";
			cin.ignore();
			getline(cin, array[element].sEntryDate);
			cout << array[element] << endl;
			break;
		case '7':
			cout << "Current quantity: " << array[element].getBookunits() << endl;
			cout << "Please enter new quantity: ";
			cin >> array[element].iUnits;
			cout << array[element] << endl;
			break;
		case '8':
			cout << "Current wholesale cost: " << array[element].getWholesale() << endl;
			cout << "Please enter new wholesale cost: ";
			cin >> array[element].dWholesale;
			cout << array[element] << endl;
			break;
		case '9':
			cout << "Current retail price: " << array[element].getRetail() << endl;
			cout << "Please enter new retail price: ";
			cin >> array[element].dRetail;
			cout << array[element] << endl;
			break;
		default: cout << sInvalid_enter << endl;
		}
		editMenu();
		cout << endl << sRequest_selection;
		cin >> ch;
	}
}












void Books::sortISBN(Books Array[], int arraySize) // Call a different sort function for each member we want the array sorted by
{

	/*for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getISBN() << endl;
	}*/
	int startScan, minIndex;
	Books minValue;

	for (startScan = 0; startScan < (arraySize - 1); startScan++)
	{
		minIndex = startScan;
		minValue = Array[startScan];
		for (int index = startScan + 1; index < arraySize; index++)
		{
			if (Array[index].getISBN() < minValue.getISBN()) // change .getISBN to the getter of the member we want to sort by
			{
				minValue = Array[index];
				minIndex = index;
			}
		}
		Array[minIndex] = Array[startScan];
		Array[startScan] = minValue;

	}

	/*for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getISBN() << endl;
	}*/

}

void Books::sortTitle(Books Array[], int arraySize) // Example for sort by title
{
	/*for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getTitle() << endl;
	}*/

	int startScan, minIndex;
	Books minValue;

	for (startScan = 0; startScan < (arraySize - 1); startScan++)
	{
		minIndex = startScan;
		minValue = Array[startScan];
		for (int index = startScan + 1; index < arraySize; index++)
		{
			if (Array[index].getTitle() < minValue.getTitle()) // changed to .getTitle()
			{
				minValue = Array[index];
				minIndex = index;
			}
		}
		Array[minIndex] = Array[startScan];
		Array[startScan] = minValue;

	}

	/*for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getTitle() << endl;
	}*/

}

void Books::sortAuthor(Books Array[], int arraySize)
{
	/*for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getAuthor() << endl;
	}*/

	int startScan, minIndex;
	Books minValue;

	for (startScan = 0; startScan < (arraySize - 1); startScan++)
	{
		minIndex = startScan;
		minValue = Array[startScan];
		for (int index = startScan + 1; index < arraySize; index++)
		{
			if (Array[index].getAuthor() < minValue.getAuthor())
			{
				minValue = Array[index];
				minIndex = index;
			}
		}
		Array[minIndex] = Array[startScan];
		Array[startScan] = minValue;

	}

	/*for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getAuthor() << endl;
	}*/

}

void Books::sortPublisher(Books Array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getPublisher() << endl;
	}

	int startScan, minIndex;
	Books minValue;

	for (startScan = 0; startScan < (arraySize - 1); startScan++)
	{
		minIndex = startScan;
		minValue = Array[startScan];
		for (int index = startScan + 1; index < arraySize; index++)
		{
			if (Array[index].getPublisher() < minValue.getPublisher())
			{
				minValue = Array[index];
				minIndex = index;
			}
		}
		Array[minIndex] = Array[startScan];
		Array[startScan] = minValue;

	}

	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getPublisher() << endl;
	}

}

void Books::sortDate(Books Array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getDate() << endl;
	}

	int startScan, minIndex;
	Books minValue;

	for (startScan = 0; startScan < (arraySize - 1); startScan++)
	{
		minIndex = startScan;
		minValue = Array[startScan];
		for (int index = startScan + 1; index < arraySize; index++)
		{
			if (Array[index].getDate() < minValue.getDate())
			{
				minValue = Array[index];
				minIndex = index;
			}
		}
		Array[minIndex] = Array[startScan];
		Array[startScan] = minValue;

	}

	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getDate() << endl;
	}

}



void Books::sortUnits(Books Array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getBookunits() << endl;
	}

	int startScan, minIndex;
	Books minValue;

	for (startScan = 0; startScan < (arraySize - 1); startScan++)
	{
		minIndex = startScan;
		minValue = Array[startScan];
		for (int index = startScan + 1; index < arraySize; index++)
		{
			if (Array[index].getBookunits() < minValue.getBookunits())
			{
				minValue = Array[index];
				minIndex = index;
			}
		}
		Array[minIndex] = Array[startScan];
		Array[startScan] = minValue;

	}

	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getBookunits() << endl;
	}

}

void Books::sortWholesale(Books Array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getWholesale() << endl;
	}

	int startScan, minIndex;
	Books minValue;

	for (startScan = 0; startScan < (arraySize - 1); startScan++)
	{
		minIndex = startScan;
		minValue = Array[startScan];
		for (int index = startScan + 1; index < arraySize; index++)
		{
			if (Array[index].getWholesale() < minValue.getWholesale())
			{
				minValue = Array[index];
				minIndex = index;
			}
		}
		Array[minIndex] = Array[startScan];
		Array[startScan] = minValue;

	}

	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getWholesale() << endl;
	}

}

void Books::sortRetail(Books Array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getRetail() << endl;
	}

	int startScan, minIndex;
	Books minValue;

	for (startScan = 0; startScan < (arraySize - 1); startScan++)
	{
		minIndex = startScan;
		minValue = Array[startScan];
		for (int index = startScan + 1; index < arraySize; index++)
		{
			if (Array[index].getRetail() < minValue.getRetail())
			{
				minValue = Array[index];
				minIndex = index;
			}
		}
		Array[minIndex] = Array[startScan];
		Array[startScan] = minValue;

	}

	for (int i = 0; i < arraySize; i++)
	{
		cout << Array[i].getRetail() << endl;
	}

}





int Books::searchISBN(Books array[], int numElems, string value)
{
	int first = 0, last = numElems - 1, middle, position = -1;
	bool found = false;

	array[0].sortISBN(array, numElems);

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (array[middle].getISBN() == value)
		{
			found = true;
			position = middle;
		}
		else if (array[middle].getISBN() > value)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return position;
}

int Books::searchTitle(Books array[], int numElems, string value)
{
	int first = 0, last = numElems - 1, middle, position = -1;
	bool found = false;

	array[0].sortTitle(array, numElems);

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (array[middle].getTitle() == value)
		{
			found = true;
			position = middle;
		}
		else if (array[middle].getTitle() > value)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return position;
}

int Books::searchAuthor(Books array[], int numElems, string value)
{
	int first = 0, last = numElems - 1, middle, position = -1;
	bool found = false;

	array[0].sortAuthor(array, numElems);

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (array[middle].getAuthor() == value)
		{
			found = true;
			position = middle;
		}
		else if (array[middle].getAuthor() > value)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return position;
}

int Books::searchPublisher(Books array[], int numElems, string value)
{
	int first = 0, last = numElems - 1, middle, position = -1;
	bool found = false;

	array[0].sortPublisher(array, numElems);

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (array[middle].getPublisher() == value)
		{
			found = true;
			position = middle;
		}
		else if (array[middle].getPublisher() > value)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return position;
}

int Books::searchDate(Books array[], int numElems, string value)
{
	int first = 0, last = numElems - 1, middle, position = -1;
	bool found = false;

	array[0].sortDate(array, numElems);

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (array[middle].getDate() == value)
		{
			found = true;
			position = middle;
		}
		else if (array[middle].getDate() > value)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return position;
}




int Books::searchUnits(Books Array[], int numElems, int value)
{
	int first = 0, last = numElems - 1, middle, position = -1;
	bool found = false;

	Array[0].sortUnits(Array, numElems);

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (Array[middle].getBookunits() == value)
		{
			found = true;
			position = middle;
		}
		else if (Array[middle].getBookunits() > value)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return position;
}

int Books::searchWholesale(Books Array[], int numElems, double value)
{
	int first = 0, last = numElems - 1, middle, position = -1;
	bool found = false;

	Array[0].sortDate(Array, numElems);

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (Array[middle].getWholesale() == value)
		{
			found = true;
			position = middle;
		}
		else if (Array[middle].getWholesale() > value)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return position;
}

int Books::searchRetail(Books Array[], int numElems, double value)
{
	int first = 0, last = numElems - 1, middle, position = -1;
	bool found = false;

	Array[0].sortDate(Array, numElems);

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (Array[middle].getRetail() == value)
		{
			found = true;
			position = middle;
		}
		else if (Array[middle].getRetail() > value)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}
	return position;
}






void Books::remove(int amount)
{
	iUnits -= amount;
}
//	No need to use displayBooks member funtion because I do oveloaded operator << and >>
/*
void Books::displayBooks() const
{
cout << "ISBN: " << getISBN() << endl;
cout << "Title: " << getTitle() << endl;
cout << "Author: " << getAuthor() << endl;
cout << "Publisher: " << getPublisher() << endl;
cout << "Date Entry: " << getDate() << endl;
cout << "Quantity: " << getBookunits() << endl;
cout << "Whole sale cost: $" << getWholesale() << endl;
cout << "Retail price: $" << getRetail() << endl << endl;
}
*/