#pragma once
#include <string>

using namespace std;

class Item
{
public:
	int id;
	string name;
	int supplierID;
	int quantity;
	string type;
	double price;


	Item() {};
	Item(int id, string name, int supplierId, int quantity, string type, double price)
		: id(id), name(name), supplierID(supplierId), quantity(quantity), type(type), price(price) {};
};

