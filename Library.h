#ifndef Library_H
#define Library_H
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

class Library
{
private:
	struct Song
	{
		string songName;
		string songArtist;
		string genre;
		string producer;
		double price;
		int year;
		int position;

		Song* next;
		Song* prev;

		Song() : next(NULL), prev(NULL){}
		Song(string name, string artist, string genre, string producer, double price, int year) :
			songName(name), songArtist(artist), genre(genre), producer(producer), price(price), year(year){}
		
		void insert_name(string newName)
		{
			songName = newName;
		}
		void insert_artist(string newArtist)
		{
			songArtist = newArtist;
		}
		void insert_genre(string newGenre)
		{
			genre = newGenre;
		}
		void insert_producer(string newProducer)
		{
			producer = newProducer;
		}
		void insert_price(double newPrice)
		{
			price = newPrice;
		}
		void insert_year(int newYear)
		{
			year = newYear;
		}
		void insert_position(int newPosition)
		{
			position = newPosition;
		}
	};
	typedef struct Song* Songptr;

	Songptr head;
	Songptr tail;
	Songptr cursor;
	int length;

public:
	//Constructors and Destructors
	Library();												
	//Library(const Library &Library);							
	~Library();	

	//Accessors
	
	//Mutators
	void addToLibrary();
	void deleteFromLibrary();

	//Other Functions
	void loadLibrary(string emptyStr);
	void saveLibrary();
	void print();
	void sortByName();
	void sortByArtist();
	void sortByGenre();
	void sortByPrice();
	void sortByYear();
	void sortByProducer();
	void moveCursor();
	void startCursor();
};

#endif