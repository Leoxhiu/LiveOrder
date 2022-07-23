#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "OrderDA.h"
#include "Order.h"
#include "LinkedList.h"
#include "Table.h"

using namespace std;

// public functions here
LinkedList<Order>* OrderDA::importOrder() {
	LinkedList<Order>* orders = new LinkedList<Order>;
	importFrom(orders);
	return orders;
}

void OrderDA::displayList(LinkedList<Order>* orders) {

	for (int i = 0; i < orders->length; i++) {
		Order* order = orders->linearSearch(i);
		printElement(order->id, 4);
		printElement(order->itemID, 25);
		printElement(order->quantity, 20);
		printElement(order->date, 20);
		printElement(order->supplierID, 20);
		printElement(order->status, 20);
		printElement(order->isCompleted, 20);
		cout << endl;
	}
}

// private functions (connect to database)
void OrderDA::importFrom(LinkedList<Order>* orders) {

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
			orders->append(order);
		}

	}
	else {

		cout << "Unable to access database.";
	}

}

void OrderDA::exportTo(LinkedList<Order>* orders) {



}