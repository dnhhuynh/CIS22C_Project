#ifndef Cash_Register_H
#define Cash_Register_H
#include "Library.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

class Register : public Library
{
private:
	double subtotal;
	double total;
	double tax;
	double change;

public:
	void addToTransaction(Library &library);
	void processTransaction();
	double getSubtotal();
	double getTotal();
	double getTax();
	double getChange(double payment);
};

#endif