#include "Library.h"


Library::Library()
{
	length = 0;
	head = NULL;
	tail = NULL;
	cursor = NULL;
};

/*
Library::Library(const Library &library) : length(library.length)
{
	if (library.head == NULL)
	{
		head = tail = cursor = NULL;
	}
	else
	{
		head = new Song(library.head->songName);
		Songptr temp = library.head;
		cursor = head;

		while (temp->next != NULL)
		{
			cursor->next = new Song;
			cursor = cursor->next;
			temp = temp->next;
			cursor->songName = temp->songName;
		}
	tail = cursor;
	cursor = NULL;
	}
};
*/

Library::~Library()
{
	cursor = head;
	Songptr temp;
	while (cursor != NULL)
	{
		temp = cursor->next;
		delete cursor;
		cursor = temp;
	}
}

void Library::loadLibrary(string emptyStr)
{
	string tempString;
	double tempDouble;
	int tempInt;

	ifstream database;
	database.open("Library.txt");

	if (database.fail())
	{
		cout << "'library.txt' cannot be found. Program will now terminate. . .";
		cout << endl << "Press any key to continue. . .";
		getline(cin, emptyStr);
		exit(1);
	}

	while (!database.eof())
	{
		if (length == 0)
		{
			Songptr S = new Song();

			getline(database, tempString);
			S->insert_name(tempString);
			getline(database, tempString);
			S->insert_artist(tempString);
			getline(database, tempString);
			S->insert_genre(tempString);
			getline(database, tempString);
			S->insert_producer(tempString);
			database >> tempDouble;
			S->insert_price(tempDouble);
			database >> tempInt;
			database.ignore();
			S->insert_year(tempInt);
			S->insert_position(length + 1);

			tail = head = S;
		}
		else
		{
			Songptr S = new Song();

			database.ignore();
			getline(database, tempString);
			S->insert_name(tempString);
			getline(database, tempString);
			S->insert_artist(tempString);
			getline(database, tempString);
			S->insert_genre(tempString);
			getline(database, tempString);
			S->insert_producer(tempString);
			database >> tempDouble;
			S->insert_price(tempDouble);
			database >> tempInt;
			database.ignore();
			S->insert_year(tempInt);
			S->insert_position(length + 1);

			tail->next = S;
			S->prev = tail;
			tail = S;
		}
		length += 1;
	}
	database.close();
}

void Library::print()
{
	Songptr temp = head;

	while (temp != NULL)
	{
		cout << left << setw(2) << temp->position << setw(25) << temp->songName << setw(25) << temp->songArtist <<
			setw(20) << temp->genre << setw(25) << temp->producer << setw(7) << temp->price << setw(7) << temp->year << endl;
		temp = temp->next;
	}
};

void Library::saveLibrary()
{
	fstream outFile;
	outFile.open("Library.txt", ios::out);

	Songptr S = head;

	for (int i = 0; i < length; i++)
	{
		outFile << S->songName << endl;
		outFile << S->songArtist << endl;
		outFile << S->genre << endl;
		outFile << S->producer << endl;
		outFile << S->price << endl;
		outFile << S->year << endl;
		
		S = S->next;
	}
	outFile.close();
}

void Library::addToLibrary()
{
	string tempString;
	double tempDouble;
	int tempInt;


	if (length == 0)
	{
		Songptr S = new Song();

		cout << "Enter the song name: ";
		getline(cin, tempString);
		S->insert_name(tempString);
		cout << "Enter the song artist: ";
		getline(cin, tempString);
		S->insert_artist(tempString);
		cout << "Enter the genre of the song: ";
		getline(cin, tempString);
		S->insert_genre(tempString);
		cout << "Enter the producer of the song: ";
		getline(cin, tempString);
		S->insert_producer(tempString);
		cout << "Enter the price of the song: ";
		cin >> tempDouble;
		S->insert_price(tempDouble);
		cout << "Enter the year of release of the song: ";
		cin >> tempInt;
		S->insert_year(tempInt);
		S->insert_position(length + 1);

		tail = head = S;
	}
	else
	{
		Songptr S = new Song();

		cout << "Enter the song name: ";
		getline(cin, tempString);
		S->insert_name(tempString);
		cout << "Enter the song artist: ";
		getline(cin, tempString);
		S->insert_artist(tempString);
		cout << "Enter the genre of the song: ";
		getline(cin, tempString);
		S->insert_genre(tempString);
		cout << "Enter the producer of the song: ";
		getline(cin, tempString);
		S->insert_producer(tempString);
		cout << "Enter the price of the song: ";
		cin >> tempDouble;
		S->insert_price(tempDouble);
		cout << "Enter the year of release of the song: ";
		cin >> tempInt;
		S->insert_year(tempInt);
		S->insert_position(length + 1);

		tail->next = S;
		S->prev = tail;
		tail = S;
	}
	length += 1;
}