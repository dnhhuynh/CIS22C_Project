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


	};
	typedef struct Song* Songptr;

	Songptr head;
	Songptr tail;
	Songptr cursor;
	int length;

public:
	Library();												
	//Library(const Library &Library);							
	~Library();	
	void loadLibrary(string emptyStr);
	void print();
};

#endif