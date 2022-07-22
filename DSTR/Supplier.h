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
	Supplier(int id, string email, string name, string phoneNumber)
		: id(id), email(email), name(name), phoneNumber(phoneNumber) {};
};
