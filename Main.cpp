#include <iostream>
#include "Hashtable.h"
#include "BST.h"
#include <iomanip>
#include <string>

using namespace std;

string emptyStr;

void storeMenu();
void registerMenu();
void playlistMenu();
void logMenu();

/*********************************************************************************
								    Main Menu
*********************************************************************************/
int main()
{
	int option, mainMenu = 1;

	do
	{
		system("cls");
		cout << "1. View Music Store" << endl
			<< "2. Purchase Songs" << endl
			<< "3. Manage Playlists" << endl
			<< "4. View Transaction Logs" << endl
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
			registerMenu();
			break;
		case 3:
			playlistMenu();
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
		cout << "Select an option (1-7): ";
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
void registerMenu()
{
	int mainMenu = 1;


	do
	{

	} while (mainMenu == 1);
}

/*********************************************************************************
								  Playlist Menu
*********************************************************************************/
void playlistMenu()
{

}

/*********************************************************************************
							   Transaction Log Menu
*********************************************************************************/
void logMenu()
{

}