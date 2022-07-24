#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Item.h"
#include "ItemDA.h"
#include "Table.h"
#include "Storage.h"
#include "DynamicArray.h"

using namespace std;

// public functions here

DynamicArray<Item>* ItemDA::getItemData() {
	Storage<DynamicArray<Item>*>* itemData = itemData->getInstance(); // find the dynamic array from storage
	return itemData->getData();
}

void ItemDA::addItem(Item item) {
    DynamicArray<Item>* itemData = getItemData();
	itemData->append(item);
	//exportToDatabase();
}

void ItemDA::displayList() {

    DynamicArray<Item>* orderData = getItemData();

    for (int i = 0; i < orderData->getLength(); i++) {
        Item* item = orderData->getData(i);
        printElement(item->id, 10);
        printElement(item->name, 50);
        printElement(item->quantity, 10);
        printElement(item->type, 25);
        printElement(item->price, 20);
        cout << endl;
    }
}

ItemDA::find ItemDA::findItemByID(int id) {

    DynamicArray<Item>* itemData = getItemData();

    int low = 0, high = itemData->getLength() - 1;
    int mid;

    // This below check covers all cases , so need to check
    // for mid=lo-(hi-lo)/2
    while (high - low > 1) {
        int mid = (high + low) / 2;
        if (itemData->getData(mid)->id < id) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    if (itemData->getData(low)->id == id) {
        return find::Found;
    }
    else if (itemData->getData(high)->id == id) {
        return find::Found;
    }
    else {
        return find::NotFound;
    }

}
Item ItemDA::getItemByID(int id) {

    DynamicArray<Item>* itemData = getItemData();
    Item item;
    for (int i = 0; i < itemData->getLength(); i++)
        if (itemData->getData(i)->id == id)
            item = *itemData->getData(i);
            return item;

    return item;
}

void ItemDA::sortItembyID(sortMethod method) {
    DynamicArray<Item>* itemData = getItemData();

    if (method == sortMethod::ascending) {

        int i, j;
        for (i = 0; i < itemData->getLength() - 1; i++)

            // Last i elements are already 
            // in place
            for (j = 0; j < itemData->getLength() - i - 1; j++)
                if (itemData->getData(j)->id > itemData->getData(j + 1)->id)
                    swap(itemData->data[j], itemData->data[j + 1]);

    }
    else if
        (method == sortMethod::descending) {

        int i, j;
        for (i = 0; i < itemData->getLength() - 1; i++)

            // Last i elements are already 
            // in place
            for (j = 0; j < itemData->getLength() - i - 1; j++)
                if (itemData->getData(j)->id < itemData->getData(j + 1)->id)
                    swap(itemData->data[j], itemData->data[j + 1]);

    }

}
void ItemDA::sortItembyQuantity(sortMethod method) {
    DynamicArray<Item>* itemData = getItemData();

    if (method == sortMethod::ascending) {

        int i, j;
        for (i = 0; i < itemData->getLength() - 1; i++)

            // Last i elements are already 
            // in place
            for (j = 0; j < itemData->getLength() - i - 1; j++)
                if (itemData->getData(j)->quantity > itemData->getData(j + 1)->quantity)
                    swap(itemData->data[j], itemData->data[j + 1]);

    }
    else if
        (method == sortMethod::descending) {

        int i, j;
        for (i = 0; i < itemData->getLength() - 1; i++)

            // Last i elements are already 
            // in place
            for (j = 0; j < itemData->getLength() - i - 1; j++)
                if (itemData->getData(j)->quantity < itemData->getData(j + 1)->quantity)
                    swap(itemData->data[j], itemData->data[j + 1]);

    }
}
void ItemDA::sortItembyPrice(sortMethod method) {
    DynamicArray<Item>* itemData = getItemData();

    if (method == sortMethod::ascending) {

        int i, j;
        for (i = 0; i < itemData->getLength() - 1; i++)

            // Last i elements are already 
            // in place
            for (j = 0; j < itemData->getLength() - i - 1; j++)
                if (itemData->getData(j)->price > itemData->getData(j + 1)->price)
                    swap(itemData->data[j], itemData->data[j + 1]);

    }
    else if
        (method == sortMethod::descending) {

        int i, j;
        for (i = 0; i < itemData->getLength() - 1; i++)

            // Last i elements are already 
            // in place
            for (j = 0; j < itemData->getLength() - i - 1; j++)
                if (itemData->getData(j)->price < itemData->getData(j + 1)->price)
                    swap(itemData->data[j], itemData->data[j + 1]);

    }
}

void ItemDA::importItem() {
    // create new instance in storage
    Storage<DynamicArray<Item>*>* itemData = Storage<DynamicArray<Item>*>::getInstance();

    // import user data into storage(linked list) from database 
    itemData->setData(importFromDatabase());

}

// private functions here
DynamicArray<Item>* ItemDA::importFromDatabase() {

    DynamicArray<Item>* itemData = new DynamicArray<Item>();

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

    DynamicArray<Item>* itemData = getItemData();

    fstream file(this->filepath);
    if (file.is_open()) {

        for (int i = 0; i < itemData->getLength(); i++)
        {
            file << itemData->getData(i)->id << "," <<
                itemData->getData(i)->name << "," <<
                itemData->getData(i)->quantity << "," <<
                itemData->getData(i)->type << "," <<
                itemData->getData(i)->price << endl;
        }

    }
    else {
        cout << "Unable to access database.";
    }

}