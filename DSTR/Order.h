#pragma once
#include <string>

using namespace std;

class Order
{
public:
	int id;
	int itemID;
	int quantity;
	string date;
	int supplierID;
	string status;
	bool isCompleted;


	Order() {};
	Order(int id, int itemID, int quantity, string date, int supplierID, string status, bool isCompleted)
		: id(id), itemID(itemID), quantity(quantity), date(date), 
		supplierID(supplierID), status(status), isCompleted(isCompleted) {};
};

