#include "Cash Register.h"

using namespace std;

void Register::addToTransaction(Library &library)
{
	if (length == 0)
	{
		Songptr S = new Song();

		S->insert_name(library.getSongName());
		S->insert_artist(library.getSongArtist());
		S->insert_genre(library.getGenre());
		S->insert_producer(library.getProducer());
		S->insert_price(library.getPrice());
		S->insert_year(library.getYear());
		S->insert_position(length + 1);

		head = tail = cursor = S;
	}
	else
	{
		Songptr S = new Song();

		S->insert_name(library.getSongName());
		S->insert_artist(library.getSongArtist());
		S->insert_genre(library.getGenre());
		S->insert_producer(library.getProducer());
		S->insert_price(library.getPrice());
		S->insert_year(library.getYear());
		S->insert_position(length + 1);

		tail->next = S;
		S->prev = tail;
		tail = S;
	}
	length++;
}

void Register::processTransaction()
{
	double payment;

	cout << left << setw(17) << "Ticket: " << setw(25) << "Song Title"
		<< setw(25) << "Artist" << setw(20) << "Genre" << setw(25) << "Producer"
		<< setw(7) << "Price" << setw(7) << "Year" << endl;

	Songptr temp = head;

	while (temp != NULL)
	{
		cout << right << setw(17) << temp->position << left << setw(25) << temp->songName << setw(25) << temp->songArtist <<
			setw(20) << temp->genre << setw(25) << temp->producer << setw(7) << temp->price << setw(7) << temp->year << endl;
		temp = temp->next;
	}
	
	cout << endl << right << setw(117) << "Subtotal: " << setw(6) << fixed << setprecision(2) << getSubtotal() << endl;
	cout << setw(117) << "Tax: " << setw(6) << getTax() << endl;
	cout << setw(117) << "Total: " << setw(6) << getTotal() << endl;

	cout << setw(117) << "Enter amount of payment: ";
	cin >> payment;
	cin.ignore();

	cout << setw(117) << "Change: " << setw(6) << getChange(payment) << endl;
}

double Register::getSubtotal()
{
	Songptr temp = head;

	subtotal = 0.0;

	while (temp != NULL)
	{
		subtotal += temp->price;
		temp = temp->next;
	}

	return subtotal;
}

double Register::getTotal()
{
	total = tax + subtotal;

	return total;
}

double Register::getTax()
{
	tax = subtotal * 0.0875;

	return tax;
}

double Register::getChange(double payment)
{
	change = payment - total;

	return change;
}