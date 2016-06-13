#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

class HashTable {

public:
	HashTable();

	//~HashTable(); 
	//Will write as part of Lab 6

	int hash(string key);
	//returns the hash value for the given key
	//the hash value is the sum of 
	//the ASCII values of each character % the table size

	void addItem(string name, string artist, string album, string genre, int year, double price);
	//inserts a new item into the table
	// calls the hash function on the key title to determine the correct bucket

	void removeItem(string name, string key); 
	//removes the item with the given key

	int numItemsAtIndex(int index);
	//Helper function to printTable
	//Counts the number of items in each bucket

	void printTable();
	//prints the first item of each bucket
	//includes the number of items stored at that bucket

	void printBucket(int index);
	//Prints all items stored at a single bucket

	int findAuthor(string title);
	//Searches for an author in the table using the key
	//returns the index under which the author is stored
	//returns -1 if the author is not found

	void loadStore(string emptyStr);

	void saveStore();
private:

	struct Node
	{
		string title, artist, genre, album;
		int year; 
		double price;
		Node* next;
		Node() : title(""), artist(""), genre(""), album(""), year(0), price(0.0), next(NULL){}
		Node(string ntitle, string nartist, string nalbum, string ngenre, int nyear, double nprice) : title(ntitle), artist(nartist), genre(ngenre), album(nalbum), year(nyear), price(nprice), next(NULL){}
	};

	typedef struct Node* Nodeptr;

	static const int TABLE_SIZE = 100;
	Nodeptr Table[TABLE_SIZE];

};
#endif /* HASHTABLE_H_ */