#include "List.h"

/*
Description: Class Default Constructor
Pre: Takes in nothing
Post: Returns nothing
*/
List::List()
{
	length = 0;
	head = NULL;
	tail = NULL;
	cursor = NULL;
};

/*
Description: Class Destructor
Pre: Takes in nothing
Post: Returns nothing
*/
List::~List()
{
	cursor = head;
	Nodeptr temp;
	while (cursor != NULL)
	{
		temp = cursor->next;

		delete cursor;

		cursor = temp;
	}
}

/*
Description: Prints out all nodes and their corresponding data in order
Pre: Takes in nothing
Post: Returns nothing
*/
void List::print()
{
	Nodeptr temp = head; //create a temporary iterator
	cout << left << setw(40) << "Song Title: " << setw(30) << "Artist: " << setw(45) << "Album Title: " << setw(20) << "Genre: " << setw(10) << "Year: " << setw(6) << "Price: " << endl;

	while (temp != NULL) 
	{
		cout << left << setw(40) << temp->title << setw(30) << temp->artist << setw(45) << temp->album << setw(20) << temp->genre << setw(10) << temp->year << setw(6) << right << temp->price << endl;
		temp = temp->next;
	}

	cout << endl << endl;
};

void List::printIndex()
{
	Nodeptr temp = head; //create a temporary iterator
	cout << left << setw(4) << " " << setw(4) << " " << setw(40) << "Song Title: " << setw(30) << "Artist: " << setw(45) << "Album Title: " << setw(20) << "Genre: " << setw(10) << "Year: " << setw(6) << "Price: " << endl;

	while (temp != NULL)
	{
		if (cursor->index == temp->index)
		{
			cout << left << setw(4) << "->";
		}
		else
		{
			cout << left << setw(4) << " ";
		}
		cout << left << setw(4) << temp->index << setw(40) << temp->title << setw(30) << temp->artist << setw(45) << temp->album << setw(20) << temp->genre << setw(10) << temp->year << setw(6) << right << temp->price << endl;
		temp = temp->next;
	}

	cout << endl << endl;
};

void List::print(ofstream& log)
{
	Nodeptr temp = head; //create a temporary iterator
	log << left << setw(40) << "Song Title: " << setw(30) << "Artist: " << setw(45) << "Album Title: " << setw(20) << "Genre: " << setw(10) << "Year: " << setw(6) << "Price: " << endl;

	while (temp != NULL)
	{
		log << left << setw(40) << temp->title << setw(30) << temp->artist << setw(45) << temp->album << setw(20) << temp->genre << setw(10) << temp->year << setw(6) << right << temp->price << endl;
		temp = temp->next;
	}

	log << endl << endl;
};

/*
Description: Creates a new node and moves it to the front of the list
Pre: Takes in data as a parameter
Post: Returns nothing
*/
void List::insert_head(string name, string artist, string album, string genre, int year, double price)
{
	if (length == 0)
	{
		head = new Node(name, artist, album, genre, year, price);
		tail = head;
	}
	else
	{
		Nodeptr N = new Node(name, artist, album, genre, year, price);//create the new node by calling the node constructor
		N->next = head;//set the new node's next field to point to the head
		head = N;//make the head be the new node
	}
	length++;
}

/*
Description: Creates a new node and moves it to the end of the list
Pre: Takes in data as a parameter
Post: Returns nothing
*/
void List::insert_tail(string name, string artist, string album, string genre, int year, double price, int index)
{
	if (length == 0)
	{
		tail = new Node(name, artist, album, genre, year, price, index);
		head = tail;
	}
	else
	{
		Nodeptr N = new Node(name, artist, album, genre, year, price, index);//create the new node by calling the node constructor
		tail->next = N;//set the new node's next field to point to the head
		tail = N;//make the head be the new node
	}
	length++;
}

void List::insert_tail(Nodeptr temp)
{
	if (length == 0)
	{
		tail = new Node(temp);
		head = tail;
	}
	else
	{
		Nodeptr N = new Node(temp);//create the new node by calling the node constructor
		tail->next = N;//set the new node's next field to point to the head
		tail = N;//make the head be the new node
	}
	length++;
}

/*
Description: Retrieves the data stored in the first node
Pre: Takes in nothing
Post: Returns data in the first node
*/
string List::get_head()
{
	return head->title;
}

/*
Description: Retrieves the data stored in the last node
Pre: Takes in nothing
Post: Returns data in the last node
*/
string List::get_tail()
{
	return tail->title;
}

/*
Description: Retrieves the number of nodes in the list
Pre: Takes in nothing
Post: Returns length of the list
*/
int List::get_length()
{
	return length;
}

/*
Description: Determines if the list is empty or not
Pre: Takes in nothing
Post: Returns true if list is empty, fales if list isn't
*/
bool List::is_empty()
{
	if (length == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double List::getSubtotal()
{
	Nodeptr temp = head;

	for (int i = 0; i < length; i++)
	{
		subtotal += temp->price;
		temp = temp->next;
	}

	return subtotal;
}

double List::getTax()
{
	tax = subtotal * .0875;

	return tax;
}

double List::getTotal()
{
	total = tax + subtotal;

	return total;
}

double List::getChange(double payment)
{
	change = payment - total;

	return change;
}

void List::delete_head()
{
	if (is_empty())
	{
		cout << "delete_head(): Current List is Empty..." << endl;
	}
	else
	{
		Nodeptr temp = head;
		head = head->next;
		delete temp;
		length -= 1;
	}
}

int List::search(string name, string artist)
{
	Nodeptr temp = head;
	int found = 0;

	while (temp != NULL && found == 0)
	{
		if (name == temp->title && artist == temp->artist)
		{
			found = 1;
		}
	}

	return found;
}

void List::setCursor()
{
	cursor = head;
}

void List::moveUp()
{
	if (cursor->index == 1)
	{
		return;
	}

	int index = cursor->index - 1;

	setCursor();

	while (cursor != NULL && cursor->index != index)
	{
		cursor = cursor->next;
	}
}

void List::moveDown()
{
	if (cursor != tail)
	{
		cursor = cursor->next;
	}
}

void List::play()
{
	cout << "Playing " << cursor->title << endl << endl;
}

int List::loadLibrary(string name, int counter)
{
	string title, artist, genre, album;
	int year;
	double price;

	ifstream inFile;
	inFile.open(name + ".txt");

	if (inFile.fail())
	{
		return 0;
	}

	while (!inFile.eof())
	{
		getline(inFile, title);
		if (title == "")
		{
			break;
		}
		getline(inFile, artist);
		getline(inFile, album);
		getline(inFile, genre);
		inFile >> year;
		inFile >> price;
		inFile.ignore();

		insert_tail(title, artist, album, genre, year, price, ++counter);
	}

	inFile.close();

	return counter;
}

void List::saveLibrary(string name)
{
	ofstream outFile;
	outFile.open(name + ".txt", ios::trunc);

	Nodeptr temp = head;

	while (temp != NULL)
	{
		outFile << temp->title << endl;
		outFile << temp->artist << endl;
		outFile << temp->album << endl;
		outFile << temp->genre << endl;
		outFile << temp->year << endl;
		outFile << temp->price << endl;

		temp = temp->next;
	}

	outFile.close();
}