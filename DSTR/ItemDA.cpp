#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Item.h"
#include "ItemDA.h"
#include "Table.h"

using namespace std;

// public functions here

LinkedList<Item>* ItemDA::importItem() {
	LinkedList<Item>* items = new LinkedList<Item>;
	importFrom(items);
	return items;
}

void ItemDA::displayList(LinkedList<Item>* items) {

	for (int i = 0; i < items->length; i++) {
		Item* item = items->linearSearch(i);
		printElement(item->id, 10);
		printElement(item->name, 50);
		printElement(item->quantity, 10);
		printElement(item->type, 25);
		printElement(item->price, 20);
		cout << endl;
	}

}


// private functions (connect to database)
void ItemDA::importFrom(LinkedList<Item>* items) {

	ifstream file(this->filepath); // read database (relative path)
	if (file.is_open()) {

		string id, name, quantity, type, price;
		string line;

		while (getline(file, line)) {

			stringstream ss(line);

			getline(ss, id, ',');
			getline(ss, name, ',');
			getline(ss, quantity, ',');
			getline(ss, type, ',');
			getline(ss, price, ',');

			Item item(stoi(id), name, stoi(quantity), type, stod(price));
			items->append(item);
		}

	}
	else {

		cout << "Unable to access database.";
	}

}

void ItemDA::exportTo(LinkedList<Item>* items) {

	fstream file(this->filepath);
	if (file.is_open()) {

		for (int i = 0; i < items->length; i++)
		{
			file << items->linearSearch(i)->id << "," <<
				items->linearSearch(i)->name << "," <<
				items->linearSearch(i)->quantity << "," <<
				items->linearSearch(i)->type << "," <<
				items->linearSearch(i)->price << endl;
		}

	}
	else {
		cout << "File not open";
	}

}