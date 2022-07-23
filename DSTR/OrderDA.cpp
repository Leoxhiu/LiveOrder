#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "OrderDA.h"
#include "Order.h"
#include "LinkedList.h"
#include "Table.h"
#include "Storage.h"

using namespace std;

// public functions here
LinkedList<Order>* OrderDA::getOrderData() {
	Storage<LinkedList<Order>*>* orderData = orderData->getInstance(); // find the linked list from storage
	return orderData->getData();
}

void OrderDA::addOrder(Order order) {
	LinkedList<Order>* orderData = getOrderData();
	orderData->append(order);
	//exportToDatabase();
}

void OrderDA::displayList() {

	LinkedList<Order>* orderData = getOrderData();

    for (int i = 0; i < orderData->length; i++) {
        Order* order = orderData->linearSearch(i);
        printElement(order->id, 10);
        printElement(order->itemID, 10);
        printElement(order->quantity, 10);
        printElement(order->date, 20);
        printElement(order->supplierID, 10);
        printElement(order->status, 15);
        printElement(order->isCompleted, 4);
        cout << endl;
    }

}




void OrderDA::importOrder() {

    // create new instance in storage
    Storage<LinkedList<Order>*>* orderData = Storage<LinkedList<Order>*>::getInstance();

    // import user data into storage(linked list) from database 
    orderData->setData(importFromDatabase());

}

// private functions here
LinkedList<Order>* OrderDA::importFromDatabase() {

	LinkedList<Order>* orderData = new LinkedList<Order>();

	ifstream file(this->filepath); // read database (relative path)
	if (file.is_open()) {

		string id, itemID, quantity, date, supplierID, status, isCompleted;
		string line;

		while (getline(file, line)) {

            stringstream ss(line);

            getline(ss, id, ',');
            getline(ss, itemID, ',');
            getline(ss, quantity, ',');
            getline(ss, date, ',');
            getline(ss, supplierID, ',');
            getline(ss, status, ',');
            getline(ss, isCompleted, ',');

            bool sta;
            istringstream(isCompleted) >> sta;

            Order order(stoi(id), stoi(itemID), stoi(quantity),
                date, stoi(supplierID), status, sta);
            orderData->append(order);
		}

	}
	else {

		cout << "Unable to access database.";
	}

	return orderData;

}

void OrderDA::exportToDatabase() {

	LinkedList<Order>* orderData = getOrderData();

	fstream file(this->filepath);
	if (file.is_open()) {

		for (int i = 0; i < orderData->length; i++)
		{
            file << orderData->linearSearch(i)->id << "," <<
                orderData->linearSearch(i)->itemID << "," <<
                orderData->linearSearch(i)->quantity << "," <<
                orderData->linearSearch(i)->date << "," <<
                orderData->linearSearch(i)->supplierID << "," <<
                orderData->linearSearch(i)->status << "," <<
                orderData->linearSearch(i)->isCompleted << endl;
		}

	}
	else {
        cout << "Unable to access database.";
	}

}