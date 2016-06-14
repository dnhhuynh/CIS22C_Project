/*
Danh Huynh
CIS 22C - Data Abstraction and Structures
April 12, 2016

Lab 1 Description: To utilize link lists to store data, modify that data, and retrieve that data.
*/

//Preprocessor Directives
#include <iostream>
#include <cstddef>
#include <iomanip>
#include <string>
#include "Hashtable.h"
#include <fstream>

//Utilizing Standard Namespace
using namespace std;

class List : public HashTable
{
	typedef struct Node* Nodeptr;					//Allows for the use of Nodeptr for structure Node*

	Nodeptr head;									//Pointer Structure Variable to point to first node
	Nodeptr tail;									//Pointer Structure Variable to point to last node
	Nodeptr cursor;									//Pointer Structure Variable to point to a node
	int length;										//Variable to store the number of nodes in list
	double subtotal = 0.0, total, tax, change;

public:
	List();											//Default Constructor for Class List
	~List();										//Destructor for Class List
	void insert_head(string name, string artist, string album, string genre, int year, double price);						//Member Function to create a node with data at the beginning of the list
	void insert_tail(Nodeptr temp);					//Member Function to create a node with data at the end of the list
	void print();									//Member Function to print out all the data within each node in order
	void print(ofstream& log);
	string get_head_title() { return head->title; }
	string get_head_artist() { return head->artist; }
	string get_head_album() { return head->album; }
	string get_head_genre() { return head->genre; }
	int get_head_year() { return head->year; }
	double get_head_price() { return head->price; }
	string get_head();//Member Function to print out the first node and its data
	string get_tail();								//Member Function to print out the last node and its data
	int get_length();								//Member Function to print out the length of the list
	bool is_empty();								//Member Function to determine if the list is empty or not
	double getSubtotal();
	double getTotal();
	double getTax();
	double getChange(double payment);
	void delete_head();
};
