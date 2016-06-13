#include "Hashtable.h"

HashTable::HashTable()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		Table[i] = new Node();
	}
}

/*
HashTable::~HashTable()
{
	Nodeptr temp, temp_next;

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		temp = Table[i];
		while (temp != NULL)
		{
			temp_next = temp->next;
			delete temp;
			temp = temp->next;
		}
		Table[i] = NULL;
	}
}
*/

int HashTable::hash(string key)
{
	int index, sum = 0;

	for (int i = 0; i < key.length(); i++)
	{
		sum += (int)key[i];
	}

	index = sum % TABLE_SIZE;

	return index;
}

void HashTable::addItem(string name, string artist, string album, string genre, int year, double price)
{
	Nodeptr N = new Node(name, artist, album, genre, year, price);

	int index = hash(artist);

	if (Table[index]->artist == "")
	{
		Table[index] = N;
	}
	else
	{
		Nodeptr temp = Table[index];

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = N;
	}
}

void HashTable::removeItem(string name, string key)
{
	int i = hash(key);
	Nodeptr current, previous;
	Nodeptr temp;
	bool found = 0;

	if (Table[i]->title == "")
	{
		cout << "Song was not found . . . " << endl;
	}
	else if (Table[i]->title == name && Table[i]->next == NULL)
	{
		Table[i]->title = Table[i]->artist = Table[i]->album = Table[i]->genre = "";
		Table[i]->year = 0;
		Table[i]->price = 0.0;

		cout << "Song was removed from Music Store . . ." << endl;
	}
	else if (Table[i]->title == name)
	{
		temp = Table[i];
		Table[i] = Table[i]->next;
		delete temp;

		cout << "Song was removed from Music Store . . ." << endl;
	}
	else
	{
		current = Table[i]->next;
		previous = Table[i];

		while (current != NULL && current->title != name)
		{
			previous = current;
			current = current->next;
		}

		if (current == NULL)
		{
			cout << "Song was not found . . . " << endl;
		}
		else
		{
			temp = current;
			current = current->next;
			previous->next = current;
			delete temp;

			cout << "Song was removed from Music Store . . . " << endl;
		}
	}
}

void HashTable::printTable()
{
	cout << left << setw(40) << "Song Title: " << setw(30) << "Artist: " << setw(20) << "Album Title: " << setw(20) << "Genre: " << setw(10) << "Year: " << setw(6) << "Price: " << endl;

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (Table[i]->title != "")
		{
			cout << left << setw(40) << Table[i]->title << setw(30) << Table[i]->artist << setw(20) << Table[i]->album << setw(20) << Table[i]->genre << setw(10) << Table[i]->year << setw(6) << right << Table[i]->price << endl;
		}

		if (Table[i]->next != NULL)
		{
			printBucket(i);
		}
	}

	cout << endl;
}

int HashTable::numItemsAtIndex(int index)
{
	int counter = 0;

	Nodeptr temp = Table[index];

	if (temp->title == "")
	{
		return counter;
	}

	while (temp != NULL)
	{
		counter++;
		temp = temp->next;
	}

	return counter;
}

void HashTable::printBucket(int index)
{
	Nodeptr temp = Table[index]->next;

	while (temp != NULL)
	{
		cout << left << setw(40) << temp->title << setw(30) << temp->artist << setw(20) << temp->album << setw(20) << temp->genre << setw(10) << temp->year << setw(6) << right << temp->price << endl;
		temp = temp->next;
	}
}

int HashTable::findAuthor(string ntitle)
{
	Nodeptr temp = Table[hash(ntitle)];

	while (temp != NULL)
	{
		if (temp->title == ntitle)
		{
			cout << "Author: " << temp->title << endl;
			return hash(ntitle);
		}
		else
		{
			temp = temp->next;
		}
	}

	cout << "Title was not found. . ." << endl;

	return -1;
}

void HashTable::loadStore(string emptyStr)
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
		database >> newYear;
		database >> newPrice;
		database.ignore();

		addItem(newName, newArtist, newAlbum, newGenre, newYear, newPrice);
	}
	database.close();
}

void HashTable::saveStore()
{
	ofstream newDatabase;
	newDatabase.open("StoreTest.txt");

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (Table[i]->title != "")
		{
			newDatabase << Table[i]->title << endl;
			newDatabase << Table[i]->artist << endl;
			newDatabase << Table[i]->album << endl;
			newDatabase << Table[i]->genre << endl;
			newDatabase << Table[i]->year << endl;
			newDatabase << Table[i]->price << endl;
		}

		if (Table[i]->next != NULL)
		{
			Nodeptr temp = Table[i]->next;

			while (temp != NULL)
			{
				newDatabase << temp->title << endl;
				newDatabase << temp->artist << endl;
				newDatabase << temp->album << endl;
				newDatabase << temp->genre << endl;
				newDatabase << temp->year << endl;
				newDatabase << temp->price << endl;
				temp = temp->next;
			}
		}
	}

	newDatabase.close();
}