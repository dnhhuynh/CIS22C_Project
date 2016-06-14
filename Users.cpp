#include "User.h"

using namespace std;

void User::setUsername(string name)
{
	username = name;
}

void User::setPassword(string pass)
{
	password = pass;
}

void User::setAdmin(int code)
{
	adminAccess = code;
}

string User::getUsername()
{
	return username;
}

string User::getPassword()
{
	return password;
}

int User::getAdmin()
{
	return adminAccess;
}