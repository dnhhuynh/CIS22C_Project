#ifndef BST_H_
#define BST_H_

#include <cstddef>
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

class BST
{
private:
	struct Node
	{
		string title, artist, genre, album;
		int year;
		double price;
		Node* left;
		Node* right;

		Node() : title(""), artist(""), genre(""), album(""), year(0), price(0), left(NULL), right(NULL){}
		Node(string ntitle, string nartist, string nalbum, string ngenre, int nyear, double nprice) : title(ntitle), artist(nartist), genre(ngenre), album(nalbum), year(nyear), price(nprice), left(NULL), right(NULL){}
	};

	typedef struct Node* Nodeptr;

	Nodeptr root;


	/**Private helper functions*/

	void insert_value(Nodeptr root, string newName, string newArtist, string newAlbum, string newGenre, int newYear, double newPrice, int option);
	//private helper function for insert
	//recursively inserts a value into the BST

	void inOrderPrint(Nodeptr root);
	//private helper function for inOrderPrint
	//recursively prints tree values in order from smallest to largest

	void preOrderPrint(Nodeptr root);
	//private helper function for preOrderPrint
	//recursively prints tree values in preorder


	void postOrderPrint(Nodeptr root);
	//private helper function for postOrderPrint
	//recursively prints tree values according in postorder


public:
	BST();
	//Instantiates a new BST
	//post: a new BST object

	bool is_empty();
	//determines whether the BST is empty

	void insert(string newName, string newArtist, string newAlbum, string newGenre, int newYear, double newPrice, int option);
	//inserts a new value into the BST
	//post: a new value inserted into the BST

	string getRoot();
	//returns the value stored at the root of the BST
	//pre: the BST is not empty

	void inOrderPrint();
	//calls the inOrderPrint function to print out the values
	//stored in the BST


	void preOrderPrint();
	//calls the preOrderPrint function to print out the values
	//stored in the BST

	void postOrderPrint();
	//calls the postOrderPrint function to print out the values
	//stored in the BST

	//more functions to be added here!

	void sort(string emptyStr, int option);
};

BST::BST()
{
	root = NULL;
}


bool BST::is_empty()
{
	if (root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string BST::getRoot()
{
	if (is_empty())
	{
		cout << "getRoot(): Binary Search Tree is currently empty . . ." << endl;
		exit(1);
	}
	else
	{
		return root->title;
	}
}

void BST::insert(string newName, string newArtist, string newAlbum, string newGenre, int newYear, double newPrice, int option)
{
	if (root == NULL)
	{
		root = new Node(newName, newArtist, newAlbum, newGenre, newYear, newPrice);
	}
	else
	{
		insert_value(root, newName, newArtist, newAlbum, newGenre, newYear, newPrice, option);
	}
}

void BST::insert_value(Nodeptr root, string newName, string newArtist, string newAlbum, string newGenre, int newYear, double newPrice, int option)
{
	switch (option)
	{
	case 1:
		if (newName < root->title)
		{
			if (root->left == NULL)
			{
				root->left = new Node(newName, newArtist, newAlbum, newGenre, newYear, newPrice);
			}
			else
			{
				insert_value(root->left, newName, newArtist, newAlbum, newGenre, newYear, newPrice, option);
			}
		}
		else
		{
			if (root->right == NULL)
			{
				root->right = new Node(newName, newArtist, newAlbum, newGenre, newYear, newPrice);
			}
			else
			{
				insert_value(root->right, newName, newArtist, newAlbum, newGenre, newYear, newPrice, option);
			}
		}
		break;
	case 2:
		if (newArtist < root->artist)
		{
			if (root->left == NULL)
			{
				root->left = new Node(newName, newArtist, newAlbum, newGenre, newYear, newPrice);
			}
			else
			{
				insert_value(root->left, newName, newArtist, newAlbum, newGenre, newYear, newPrice, option);
			}
		}
		else
		{
			if (root->right == NULL)
			{
				root->right = new Node(newName, newArtist, newAlbum, newGenre, newYear, newPrice);
			}
			else
			{
				insert_value(root->right, newName, newArtist, newAlbum, newGenre, newYear, newPrice, option);
			}
		}
		break;
	case 3:
		if (newAlbum < root->album)
		{
			if (root->left == NULL)
			{
				root->left = new Node(newName, newArtist, newAlbum, newGenre, newYear, newPrice);
			}
			else
			{
				insert_value(root->left, newName, newArtist, newAlbum, newGenre, newYear, newPrice, option);
			}
		}
		else
		{
			if (root->right == NULL)
			{
				root->right = new Node(newName, newArtist, newAlbum, newGenre, newYear, newPrice);
			}
			else
			{
				insert_value(root->right, newName, newArtist, newAlbum, newGenre, newYear, newPrice, option);
			}
		}
		break;
	case 4:
		if (newGenre < root->genre)
		{
			if (root->left == NULL)
			{
				root->left = new Node(newName, newArtist, newAlbum, newGenre, newYear, newPrice);
			}
			else
			{
				insert_value(root->left, newName, newArtist, newAlbum, newGenre, newYear, newPrice, option);
			}
		}
		else
		{
			if (root->right == NULL)
			{
				root->right = new Node(newName, newArtist, newAlbum, newGenre, newYear, newPrice);
			}
			else
			{
				insert_value(root->right, newName, newArtist, newAlbum, newGenre, newYear, newPrice, option);
			}
		}
		break;
	case 5:
		if (newYear < root->year)
		{
			if (root->left == NULL)
			{
				root->left = new Node(newName, newArtist, newAlbum, newGenre, newYear, newPrice);
			}
			else
			{
				insert_value(root->left, newName, newArtist, newAlbum, newGenre, newYear, newPrice, option);
			}
		}
		else
		{
			if (root->right == NULL)
			{
				root->right = new Node(newName, newArtist, newAlbum, newGenre, newYear, newPrice);
			}
			else
			{
				insert_value(root->right, newName, newArtist, newAlbum, newGenre, newYear, newPrice, option);
			}
		}
		break;
	case 6:
		if (newPrice < root->price)
		{
			if (root->left == NULL)
			{
				root->left = new Node(newName, newArtist, newAlbum, newGenre, newYear, newPrice);
			}
			else
			{
				insert_value(root->left, newName, newArtist, newAlbum, newGenre, newYear, newPrice, option);
			}
		}
		else
		{
			if (root->right == NULL)
			{
				root->right = new Node(newName, newArtist, newAlbum, newGenre, newYear, newPrice);
			}
			else
			{
				insert_value(root->right, newName, newArtist, newAlbum, newGenre, newYear, newPrice, option);
			}
		}
		break;
	default:
		break;
	};
}

void BST::inOrderPrint()
{
	cout << left << setw(40) << "Song Title: " << setw(30) << "Artist: " << setw(20) << "Album Title: " << setw(20) << "Genre: " << setw(10) << "Year: " << setw(6) << "Price: " << endl;
	inOrderPrint(root);
	cout << endl;
}

void BST::inOrderPrint(Nodeptr root)
{
	if (root != NULL)
	{
		inOrderPrint(root->left);
		cout << left << setw(40) << root->title << setw(30) << root->artist << setw(20) << root->album << setw(20) << root->genre << setw(10) << root->year << setw(6) << right << root->price << endl;
		inOrderPrint(root->right);
	}
}

void BST::preOrderPrint()
{
	preOrderPrint(root);
}

void BST::preOrderPrint(Nodeptr root)
{
	if (root != NULL)
	{
		cout << left << setw(40) << root->title << setw(30) << root->artist << setw(20) << root->album << setw(20) << root->genre << setw(10) << root->year << setw(6) << right << root->price << endl;
		preOrderPrint(root->left);
		preOrderPrint(root->right);
	}
}

void BST::postOrderPrint()
{
	postOrderPrint(root);
}

void BST::postOrderPrint(Nodeptr root)
{
	if (root != NULL)
	{
		postOrderPrint(root->left);
		postOrderPrint(root->right);
		cout << left << setw(40) << root->title << setw(30) << root->artist << setw(20) << root->album << setw(20) << root->genre << setw(10) << root->year << setw(6) << right << root->price << endl;
	}
}

void BST::sort(string emptyStr, int option)
{
	string newName, newArtist, newGenre, newAlbum;
	double newPrice;
	int newYear;

	ifstream database;
	database.open("StoreTest.txt");

	if (database.fail())
	{
		cout << "'Store.txt' cannot be found. Program will now terminate. . .";
		cout << endl << "Press any key to continue. . .";
		getline(cin, emptyStr);
		exit(1);
	}

	while (!database.eof())
	{
		getline(database, newName);
		if (newName == "")
		{
			break;
		}
		getline(database, newArtist);
		getline(database, newAlbum);
		getline(database, newGenre);
		database >> newYear;
		database >> newPrice;
		database.ignore();

		insert(newName, newArtist, newAlbum, newGenre, newYear, newPrice, option);
	}
	database.close();
}

#endif
