#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class User {
protected:
	string username;
	string password;
	int adminAccess;
public:
	void setUsername(string);
	void setPassword(string);
	void setAdmin(int);
	string getUsername();
	string getPassword();
	int getAdmin();
};

#endif