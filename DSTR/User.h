#pragma once
#include <string>

using namespace std;

class User
{
public:
	int id;
	string email;
	string password;
	string name;
	string phoneNumber;
	int type; // account type (0 = admin, 1 = executive)

	User() {};
	User(int id, string email, string password, string name, string phoneNumber, int type) 
		: id(id), email(email), password(password), name(name), phoneNumber(phoneNumber), type(type) {};
};

