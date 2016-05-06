#include <iostream>
#include "Store.h"
 
using namespace std;

string emptyStr;

int main()
{
	Store R;

	R.loadStore(emptyStr);
	R.print();
	R.saveStore();

	system("pause");
	return 0;
}