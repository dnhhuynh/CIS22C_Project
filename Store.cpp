#include "Store.h"

Store::Store()
{
	root = NULL;
};

void Store::loadStore(string emptyStr)
{
	string newName, newArtist, newGenre, newAlbum;
	double newPrice;
	int newYear;

	ifstream database;
	database.open("Store.txt");

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
		database >> newPrice;
		database >> newYear;
		database.ignore();

		insert(newName, newArtist, newAlbum, newGenre, newPrice, newYear);
	}
	database.close();
}

void Store::insert(string name, string artist, string album, string genre, double price, int year)
{
	if (root == NULL)
	{
		root = new Song(name, artist, album, genre, price, year); 
	}
	else
	{
		insert_value(root, name, artist, album, genre, price, year);
	}
}

void Store::insert_value(Songptr root, string name, string artist, string album, string genre, double price, int year)
{
	if (root->songName == name)
	{
		return;
	}
	else if (name < root->songName)
	{
		if (root->left == NULL)
		{
			root->left = new Song(name, artist, album, genre, price, year);
		}
		else
		{
			insert_value(root->left, name, artist, album, genre, price, year);
		}
	}
	else
	{
		if (root->right == NULL)
		{
			root->right = new Song(name, artist, album, genre, price, year);
		}
		else
		{
			insert_value(root->right, name, artist, album, genre, price, year);
		}
	}
}

void Store::print(Songptr root)
{
	if (root != NULL)
	{
		print(root->left);
		cout << left << setw(30) << root->songName << setw(30) << root->songArtist << setw(30) << root->songAlbum <<
			setw(30) << root->songGenre << setw(10) << root->price << setw(10) << root->year << endl;
		print(root->right);
	}
}

void Store::saveStore(Songptr root, fstream &outFile)
{
	if (root != NULL)
	{
		saveStore(root->left, outFile);
		outFile << root->songName << endl << root->songArtist << endl << root->songAlbum <<
			endl << root->songGenre << endl << root->price << endl << root->year << endl;
		saveStore(root->right, outFile);
	}
}

void Store::print()
{
	print(root);
}

void Store::saveStore()
{
	fstream outFile;
	outFile.open("Store.txt", ios::out);

	saveStore(root, outFile);

	outFile.close();
}