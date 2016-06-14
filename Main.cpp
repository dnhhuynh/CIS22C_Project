#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Hashtable.h"
#include "BST.h"
#include <iomanip>
#include <string>
#include "List.h"
#include <ctime>

using namespace std;

string emptyStr;

void storeMenu();
void registerMenu(BST*);
void playlistMenu(BST*);
void logMenu();
string currentDateTime();

/*********************************************************************************
								    Main Menu
*********************************************************************************/
int main()
{
	int option, mainMenu = 1;
	BST* Playlist = new BST();

	do
	{
		system("cls");
		cout << "1. View Music Store" << endl
			<< "2. Purchase Songs" << endl
			<< "3. Manage Playlists" << endl
			<< "4. View Transaction Log" << endl
			<< "5. Log Out" << endl
			<< "6. Exit Program" << endl;
		cout << "Select an option (1-6): ";
		cin >> option;
		cin.ignore();

		switch (option)
		{
		case 1:
			storeMenu();
			break;
		case 2:
			registerMenu(Playlist);
			break;
		case 3:
			playlistMenu(Playlist);
			break;
		case 4:
			logMenu();
			break;
		case 5:
			break;
		case 6:
			cout << "Program will now terminate . . ." << endl;
			system("pause");
			mainMenu = 0;
			break;
		default:
			cout << "Option selected isn't valid . . ." << endl;
			break;
		};
	} while (mainMenu == 1);

	return 0;
}

/*********************************************************************************
									Store Menu
*********************************************************************************/
void storeMenu()
{
	string newName, newArtist, newGenre, newAlbum;
	double newPrice;
	int newYear;

	system("cls");
	int option, mainMenu = 1;
	HashTable Store;

	Store.loadStore(emptyStr);
	Store.printTable();

	do
	{
		cout << "1. Sort by Title" << endl
			<< "2. Sort by Artist" << endl
			<< "3. Sort by Album" << endl
			<< "4. Sort by Genre" << endl
			<< "5. Sort by Year of Release" << endl
			<< "6. Sort by Price" << endl
			<< "7. Add to Music Store (Admin)" << endl
			<< "8. Delete from Music Store (Admin)" << endl
			<< "10. Return to Main Menu" << endl;
		cout << "Select an option (1-10): ";
		cin >> option;
		cin.ignore();
		system("cls");

		switch (option)
		{
		case 1:
		{
				  BST* B = new BST();
				  B->sort(emptyStr, option);
				  B->inOrderPrint();
				  delete B;
		}
			break;
		case 2:
		{
				  BST* B = new BST();
				  B->sort(emptyStr, option);
				  B->inOrderPrint();
				  delete B;
		}
			break;
		case 3:
		{
				  BST* B = new BST();
				  B->sort(emptyStr, option);
				  B->inOrderPrint();
				  delete B;
		}
			break;
		case 4:
		{
				  BST* B = new BST();
				  B->sort(emptyStr, option);
				  B->inOrderPrint();
				  delete B;
		}
			break;
		case 5:
		{
				  BST* B = new BST();
				  B->sort(emptyStr, option);
				  B->inOrderPrint();
				  delete B;
		}
			break;
		case 6:
		{
				  BST* B = new BST();
				  B->sort(emptyStr, option);
				  B->inOrderPrint();
				  delete B;
		}
			break;
		case 7:
		{
				  cout << "Song Title: ";
				  getline(cin, newName);
				  cout << "Song Artist: ";
				  getline(cin, newArtist);
				  cout << "Song Album: ";
				  getline(cin, newAlbum);
				  cout << "Song Genre: ";
				  getline(cin, newGenre);
				  cout << "Year of Release: ";
				  cin >> newYear;
				  cout << "Song Price: ";
				  cin >> newPrice;
				  cin.ignore();
				  Store.addItem(newName, newArtist, newAlbum, newGenre, newYear, newPrice);
				  Store.saveStore();
				  system("cls");
		}
			break;
		case 8:
		{
				  cout << "Song Title: ";
				  getline(cin, newName);
				  cout << "Song Artist: ";
				  getline(cin, newArtist);
				  Store.removeItem(newName, newArtist);
				  Store.saveStore();
				  system("pause"); 
				  system("cls");
		}
			break;
		case 10:
		{
				  mainMenu = 0;
				  system("pause");
		}
			break;
		default:
			cout << "Option selected isn't valid . . ." << endl;
			break;
		};
	} while (mainMenu == 1);
}

/*********************************************************************************
								  Register Menu
*********************************************************************************/
void registerMenu(BST* Playlist)
{
	system("cls");
	string newName, newArtist;
	double payment;
	int mainMenu = 1, option;
	HashTable Store;
	ofstream log;
	List* L = new List();
	log.open("log.txt", ios::app);

	Store.loadStore(emptyStr);
	Store.printTable();

	do
	{
		cout << "1. Add Song to Transaction" << endl
			<< "2. Process Transaction" << endl
			<< "3. Return to Main Menu" << endl;
		cout << "Select an option (1-3): ";
		cin >> option;
		cin.ignore();
		system("cls");

		switch (option)
		{
		case 1:
		{
				  cout << "Song Title: ";
				  getline(cin, newName);
				  cout << "Song Artist: ";
				  getline(cin, newArtist);
				  
				  if (Store.find(newName, newArtist) == 1 && Playlist->search(newName) == 0)
				  {
					  L->insert_tail(Store.findAuthor(newName, newArtist));
					  cout << "Song was added to ticket . . ." << endl << endl;
				  }
				  else
				  {
					  cout << "Song was not found in the Music Store . . ." << endl << endl;
				  }
		}
			break;
		case 2:
		{
				  if (!L->is_empty())
				  {
					  cout << currentDateTime() << endl;
					  log << currentDateTime() << endl;
					  L->print(); 
					  L->print(log);
					  cout << right << setw(100) << setprecision(2) << fixed <<  "subtotal: " << setw(10) <<L->getSubtotal() << endl;
					  cout << right << setw(100) << "tax: " << setw(10) << L->getTax() << endl;
					  cout << right << setw(100) << "total: " << setw(10) << L->getTotal() << endl;
					  cout << "Cash Payment Amount: ";
					  cin >> payment;
					  cin.ignore();
					  cout << right << setw(100) << "change: " << setw(10) << L->getChange(payment) << endl;

					  log << right << setw(100) << setprecision(2) << fixed << "subtotal: " << setw(10) << L->getSubtotal() << endl;
					  log << right << setw(100) << "tax: " << setw(10) << L->getTax() << endl;
					  log << right << setw(100) << "total: " << setw(10) << L->getTotal() << endl;
					  log << right << setw(100) << "payment: " << setw(10) << payment << endl;
					  log << right << setw(100) << "change: " << setw(10) << L->getChange(payment) << endl << endl;

					  while (!L->is_empty())
					  {
						  Playlist->insert(L->get_head_title(), L->get_head_artist(), L->get_head_album(), L->get_head_genre(), L->get_head_year(), L->get_head_price(), 1);
						  L->delete_head();
					  }
				  }
				  else
				  {
					  cout << "Ticket is currently empty . . ." << endl;
				  }
		}
			break;
		case 3:
		{
				  mainMenu = 0;
		}
			break;
		default:
			cout << "Option selected isn't valid . . ." << endl;
			break;
		}
	} while (mainMenu == 1);

	delete L;
	log.close();
}

/*********************************************************************************
								  Playlist Menu
*********************************************************************************/
void playlistMenu(BST* Playlist)
{
	Playlist->inOrderPrint();

	system("pause");
}

/*********************************************************************************
							   Transaction Log Menu
*********************************************************************************/
void logMenu()
{
	string line;

	ifstream log;
	log.open("log.txt");
	if (log.fail())
	{
		cout << "Log is current empty . . . " << endl;
		return;
	}

	cout << endl << "Transaction Log: " << endl;
	while (!log.eof())
	{
		getline(log, line);
		cout << line << endl;
	}

	system("pause");
}

string currentDateTime() 
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

	return buf;
}