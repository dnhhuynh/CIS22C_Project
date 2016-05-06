#ifndef STORE_H_
#define STORE_H_

#include <cstddef>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class Store
{
private:
	struct Song
	{
		string songName, songArtist, songAlbum, songGenre;
		double price;
		int year;
		Song* left;
		Song* right;

		Song() : left(NULL), right(NULL){}
		Song(string name, string artist, string album, string genre, 
			double newprice, int newyear) : left(NULL), right(NULL), 
			songName(name), songArtist(artist), songAlbum(album), 
			songGenre(genre), price(newprice), year(newyear){}
	};

	typedef struct Song* Songptr;

	Songptr root;


	/**Private helper functions*/

	void insert_value(Songptr root, string name, string artist, string album, string genre, double price, int year);

	//private helper function for insert

	//recursively inserts a value into the BST

	void print(Songptr root);

	//private helper function for inOrderPrint

	//recursively prints tree values in order from smallest to largest

	void saveStore(Songptr root);

public:
	Store();

	//Instantiates a new BST

	//post: a new BST object

	bool is_empty();

	//determines whether the BST is empty

	void insert(string name, string artist, string album, string genre, double price, int year);

	//inserts a new value into the BST

	//post: a new value inserted into the BST

	string getRoot();

	//returns the value stored at the root of the BST

	//pre: the BST is not empty

	void print();

	//calls the inOrderPrint function to print out the values

	//stored in the BST

	void loadStore(string emptyStr);

	void saveStore();
};

#endif