#include <iostream>
#include "Hashtable.h"
#include <iomanip>

using namespace std;

string emptyStr;

int main()
{
	HashTable Store;

	Store.loadStore(emptyStr);
	Store.printTable();
	Store.saveStore();

	system("pause");
	return 0;
}