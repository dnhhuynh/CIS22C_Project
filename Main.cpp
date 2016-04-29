#include "Library.h"
#include "Cash Register.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string emptyStr;

int main()
{
	int mainMenu = 1;
	int option;

	Library L;
	Register R;
	L.loadLibrary(emptyStr);
	
	do
	{
		L.print();
		cout << endl;

		cout << "1. Move Cursor Up" << endl
			<< "2. Move Cursor Down" << endl
			<< "3. Add to Transaction" << endl
			<< "4. Process Transaction" << endl
			<< "5. Return to Main Menu" << endl
			<< "Key in the operation you like to use: ";
		cin >> option;
		cin.ignore();
		cout << endl;

		switch (option)
		{
		case 1: 
			L.moveCursorUp();
			break;
		case 2:
			L.moveCursorDown();
			break;
		case 3:
			R.addToTransaction(L);
			cout << "Adding to transaction. Press any key to continue . . .";
			getline(cin, emptyStr);
			break;
		case 4:
			R.processTransaction();
			cout << "Press any key to continue . . .";
			getline(cin, emptyStr);
			break;
		case 5: 
			cout << "Program is terminating . . .";
			mainMenu = 2;
			break;
		default:
			cout << "Input is not valid" << endl;
		}
		system("cls");
	} while (mainMenu == 1);

	system("pause");
	return 0;
}
