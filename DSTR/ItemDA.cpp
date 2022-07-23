#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Item.h"
#include "ItemDA.h"
#include "Table.h"
#include "Storage.h"

using namespace std;

// public functions here

LinkedList<Item>* ItemDA::getItemData() {
	Storage<LinkedList<Item>*>* itemData = itemData->getInstance(); // find the linked list from storage
	return itemData->getData();
}

void ItemDA::addItem(Item item) {
	LinkedList<Item>* itemData = getItemData();
	itemData->append(item);
	//exportToDatabase();
}

void ItemDA::displayList() {

    LinkedList<Item>* orderData = getItemData();

    for (int i = 0; i < orderData->length; i++) {
        Item* item = orderData->linearSearch(i);
        printElement(item->id, 10);
        printElement(item->name, 50);
        printElement(item->quantity, 10);
        printElement(item->type, 25);
        printElement(item->price, 20);
        cout << endl;
    }
}



void ItemDA::importItem() {
    // create new instance in storage
    Storage<LinkedList<Item>*>* itemData = Storage<LinkedList<Item>*>::getInstance();

    // import user data into storage(linked list) from database 
    itemData->setData(importFromDatabase());

}


// private functions here
LinkedList<Item>* ItemDA::importFromDatabase() {

    LinkedList<Item>* itemData = new LinkedList<Item>();

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
            itemData->append(item);
        }

    }
    else {

        cout << "Unable to access database.";
    }

    return itemData;

}

void ItemDA::exportToDatabase() {

    LinkedList<Item>* itemData = getItemData();

    fstream file(this->filepath);
    if (file.is_open()) {

        for (int i = 0; i < itemData->length; i++)
        {
            file << itemData->linearSearch(i)->id << "," <<
                itemData->linearSearch(i)->name << "," <<
                itemData->linearSearch(i)->quantity << "," <<
                itemData->linearSearch(i)->type << "," <<
                itemData->linearSearch(i)->price << endl;
        }

    }
    else {
        cout << "Unable to access database.";
    }

}