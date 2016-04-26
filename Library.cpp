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
			database.ignore();
			S->insert_price(tempDouble);
			database >> tempInt;
			database.ignore();
			S->insert_year(tempInt);
			

			tail = head = S;
		}
		else
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
			database.ignore();
			S->insert_price(tempDouble);
			database >> tempInt;
			database.ignore();
			S->insert_year(tempInt);
			

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
		cout << left << setw(25) << temp->songName << setw(25) << temp->songArtist <<
			setw(20) << temp->genre << setw(25) << temp->producer << setw(7) << temp->price << setw(7) << temp->year << endl;
		temp = temp->next;
	}
};