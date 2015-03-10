




#include <iostream>
#include <string>
#include <cstring>
#include <fstream>									//	This is for I/O file
#include <iomanip>									//	This is for alignment
#include <vector>
#include <stdlib.h>
//#include "Module1"
#include "Books.h"
//#include "Module3"

using namespace std;


const int MAX_NUM = 8;


//============================================================================================================================
//	Declare all function prototypes here
//============================================================================================================================

bool OpenFile(fstream &, string);			//	Test open file pass or fail
void inventory();							//	Create inventory of Books
void ReadContents(fstream &);				//	Read the file data with a string
void showMenu();











//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//											Main function
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main()
{
	showMenu();

	system("CLS");

	system("PAUSE");

	return 0;
}












void showMenu()
{


	system("CLS"); // clearing the console

	Books bookInv;
	char choice;

	cout << endl << "                    Dank Book Store               " << endl << endl;

	cout << "                    Main Menu:                    " << endl;

	cout << endl << "     1. Cashier Module" << endl;
	cout << "     2. Inventory Database Module" << endl;
	cout << "     3. Report Module" << endl;
	cout << "     4. Exit" << endl;


	cout << endl << "     Enter your choice: ";

	cin >> choice;

	while (choice != '1' && choice != '2' && choice != '3' && choice != '4')
	{
		cout << "     Invalid choice. Try again: ";
		cin >> choice;
	}

	// converting char to int
	//choice = int(choice);

	switch (choice)
	{
	case '1':
	{

	}
		break;
	case '2':
	{
			inventory();
	}
		break;
	case '3':
	{

	}
		break;
	case '4':
	{

	}
		break;
	}
}
















//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//													OpenFile function
//	This program accepts a reference to an fstream object as an argument. The file is opened for input.  The functions true
//	upon success, false upon failure.
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool OpenFile(fstream &file, string name)
{
	file.open(name, ios::in);
	if (file.fail())
		return false;
	else
		return true;
}

















//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//													inventory function
//	This program doesn't have any argument. The purpos of this file is opened for reading data.  
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void inventory()
{
	string	sSuccess_rd_file = "Reading from the file.",
			sPath_request = "To specify your file at specific path, please enter similar to the format below.",
			sExample_path = "\"c:\\\\data\\\\inventory.txt\"",
			sEnter_path = "Please enter your path here: ",
			sError_rd_file = "ERROR: Cannot open the file.",
			sFinish_reading = "Reading is done.",
			sPath_name;
	bool	ReadOK;
	fstream dataFile;
	system("CLS");
	cout << endl << "Please enter the location of the inventory file to load:  ";
	cout << endl << sPath_request << endl << "\t\t" << sExample_path << endl << endl << sEnter_path;
	cin >> sPath_name;

	ReadOK = OpenFile(dataFile, sPath_name);
	if (ReadOK)
	{
		cout << sSuccess_rd_file << endl << endl;
		ReadContents(dataFile);
		dataFile.close();
		cout << endl << sFinish_reading << endl;
	}
	else
	{
		cout << sError_rd_file << endl;
	}
}

















//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//														ReadContents function
//	This program accepts an fstream reference and return Books type.  Use a loop to read each name from the file.
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ReadContents(fstream &file)
{
	int iCount,
		iTotalCount,
		cnt = 0;
	string	sBooksInput,
			sArray[MAX_NUM];
	Books *bookInfo;		//	Create a pointer instance named bookInfo
	vector<string> books;	//	Create a vector books of string type
	vector<Books> vbookInfo;	//	Create a vector bookInfo of Books type

	fstream myFileOut;




	//	Open a writen a file named "myOutput.txt"
	myFileOut.open("myOutput.txt", ios::out);





	if (file)
	{
		// Read an item using $ as a delimiter.
		getline(file, sBooksInput, '\n');
		//	While the last read operation was successful, continue.
		books.push_back(sBooksInput);
		while (file)
		{
			// Display the last item read.
			//cout << sBooksInput << endl;
			myFileOut << sBooksInput << endl;
			// Read an item using $ as a delimiter.
			getline(file, sBooksInput, '\n');
			books.push_back(sBooksInput);
		}
		// Close the file
		myFileOut.close();
	}
	else
		cout << "ERROR: Cannot open file.\n";
	//	Close the file
	file.close();
	iTotalCount = books.size() - 1;	// Find out how many fields in the file
	//cout << iTotalCount << endl;
	iCount = iTotalCount / 8;	//	Find out how many books in the list
	//cout << iCount << endl;
	//cout << "This is an array book of first element: " << books[0] << endl;
	//cout << "This is an array book of second element: " << books[1] << endl;
	//cout << "This is an array book of fifth element: " << books[5] << endl;
	//cout << "This is an array book of 38th element: " << books[38] << endl;
	//cout << "This is an array book of 39th element: " << books[39] << endl;
	//cout << iTotalCount << endl << iCount << endl;

	//	Define dynamic memory allocation for pointer bookInfo
	bookInfo = new Books[iCount];

	//	Assign data to each instances' pointer.
	for (int i = 0; i < iCount, cnt < iTotalCount; i++, cnt += 8)
	{
		bookInfo[i].set(books[cnt], books[cnt + 1], books[cnt + 2], books[cnt + 3], books[cnt + 4], books[cnt + 5], books[cnt + 6], books[cnt + 7]);
	}
	bookInfo[0].loadList(bookInfo, iCount);

	delete[] bookInfo;
	bookInfo = nullptr;
}
	
