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
	printElement("Order ID", 10);
	printElement("Item ID", 10);
	printElement("Quantity", 10);
	printElement("Date", 20);
	printElement("Supplier ID", 15);
	printElement("Status", 15);
	printElement("isCompleted?", 12);
	cout << endl;

    for (int i = 0; i < orderData->getLength(); i++) {
        Order* order = orderData->getData(i);
        printElement(order->id, 10);
        printElement(order->itemID, 10);
        printElement(order->quantity, 10);
        printElement(order->date, 20);
        printElement(order->supplierID, 15);
        printElement(order->status, 15);
        printElement(order->isCompleted, 12);
        cout << endl;
    }

}

Node<Order>* OrderDA::merge(Node<Order>* first, Node<Order>* second, int choice) {
	Node<Order>* merged = new Node<Order>;
	Node<Order>* temp = new Node<Order>;

	merged = temp;

	// while either firstNode or secondNode becomes NULL
	while (first != nullptr && second != nullptr) {
		switch (choice) {
		case 1: { // ascending
			if (first->data.id <= second->data.id) {
				temp->next = first;
				first = first->next;
			}
			else {
				temp->next = second;
				second = second->next;
			}
			temp = temp->next;
		}
		case 2: { //descending
			if (first->data.id > second->data.id) {
				temp->next = first;
				first = first->next;
			}
			else {
				temp->next = second;
				second = second->next;
			}
			temp = temp->next;
		}
		}
	}

	// any remaining Node in firstNode or secondNode gets
	// inserted in the temp List
	while (first != nullptr) {
		temp->next = first;
		first = first->next;
		temp = temp->next;
	}

	while (second != nullptr) {
		temp->next = second;
		second = second->next;
		temp = temp->next;
	}

	return merged->next;
}

Node<Order>* OrderDA::findMiddle(Node<Order>* head) {
	Node<Order>* fast = head->next;
	Node<Order>* slow = head;

	while (!slow->next && (!fast && !fast->next)) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

Node<Order>* OrderDA::mergeSort(Node<Order>* head, int choice) {
	if (head->next == nullptr) {
		return head;
	}

	Node<Order>* mid = new Node<Order>;
	Node<Order>* head2 = new Node<Order>;
	mid = findMiddle(head);
	head2 = mid->next;
	mid->next = nullptr;

	Node<Order>* res = merge(mergeSort(head, choice), mergeSort(head2, choice), choice);

	LinkedList<Order>* tempData = new LinkedList<Order>();
	Order order(res->data.id, res->data.itemID, res->data.quantity,
		res->data.date, res->data.supplierID, res->data.status, res->data.isCompleted);
	tempData->append(order);

	for (int i = 0; i <= tempData->getLength(); i++) {
		Order* order = tempData->getData(i);
		printElement(order->id, 10);
		printElement(order->itemID, 10);
		printElement(order->quantity, 10);
		printElement(order->date, 20);
		printElement(order->supplierID, 15);
		printElement(order->status, 15);
		printElement(order->isCompleted, 12);
		cout << endl;
	}

	return res;
}

void OrderDA::sort() {
	LinkedList<Order>* orderData = getOrderData();
	int choice = 0;
	cout << "Ascending - 1" << endl << "Descending - 2" << endl;
	cin >> choice;

	printElement("Order ID", 10);
	printElement("Item ID", 10);
	printElement("Quantity", 10);
	printElement("Date", 20);
	printElement("Supplier ID", 15);
	printElement("Status", 15);
	printElement("isCompleted?", 12);
	cout << endl;

	mergeSort(orderData->getHead(), choice);
}

//void UserDA::bubbleSort(LinkedList<User>* userData)
//{
//	int i, j;
//	for (i = 0; i < userData->getLength() - 1; i++)
//
//		// Last i elements are already 
//		// in place
//		for (j = 0; j < userData->getLength() - i - 1; j++)
//			if (userData->getData(j)->id > userData->getData(j +1)->id)
//
//				swap(userData, userData->getNode(j +1), userData->getNode(j));
//}

//void swap(LinkedList<User>* userData, Node<User>* low, Node<User>* high) {
//
//	Node<User>* prevNode = nullptr;
//	Node<User>* prevNode2 = nullptr;
//
//	auto left = userData->head;
//}



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

		for (int i = 0; i < orderData->getLength(); i++)
		{
            file << orderData->getData(i)->id << "," <<
                orderData->getData(i)->itemID << "," <<
                orderData->getData(i)->quantity << "," <<
                orderData->getData(i)->date << "," <<
                orderData->getData(i)->supplierID << "," <<
                orderData->getData(i)->status << "," <<
                orderData->getData(i)->isCompleted << endl;
		}

	}
	else {
        cout << "Unable to access database.";
	}

}