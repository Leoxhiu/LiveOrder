#pragma once
#include <string>

using namespace std;

class Supplier
{
public:
	int id;
	string email;
	string name;
	string phoneNumber;


	Supplier() {};
	Supplier(int id, string name, string phoneNumber, string email)
		: id(id), email(email), phoneNumber(phoneNumber), name(name) {};
};
