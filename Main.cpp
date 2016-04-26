#include "Library.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string emptyStr;

int main()
{
	Library L;
	L.loadLibrary(emptyStr);
	L.print();

	system("pause");
	return 0;
}
