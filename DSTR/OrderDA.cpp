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

void OrderDA::sortOrderByID(int low, int high) {
    LinkedList<Order>* orderData = getOrderData();
    if (low < high) {
        auto pivot = orderData->getData(high);
        int pos = partition(orderData, low, high, pivot);
        sortOrderByID(low, pos - 1);
        sortOrderByID(pos + 1, high);
    }
}

//void OrderDA::sortOrderByQuantity() {
//
//    LinkedList<Order>* orderData = getOrderData();
//
//    int swapped;
//
//    Node<Order>* lPtr; // left pointer will always point to the start of the list
//    Node<Order>* rPrt = NULL; // right pointer will always point to the end of the list
//    do
//    {
//        swapped = 0;
//        auto lPtr = orderData->getHead();
//        if (lPtr == nullptr) {
//            break;
//        }
//
//        while (lPtr->next != rPrt)
//        {
//            
//
//            if (lPtr->data.quantity > lPtr->next->data.quantity)
//            {
//                bubbleSwap(lPtr, lPtr->next);
//                swapped = 1;
//            }
//            lPtr = lPtr->next;
//        }
//        //as the largest element is at the end of the list, assign that to rPtr as there is no need to
//        //check already sorted list
//        rPrt = lPtr;
//
//    } while (swapped);
//
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

int OrderDA::partition(LinkedList<Order>* list, int low, int high, Order* pivot) {
    
    int i = low;
    int j = low;
    while (i <= high) {
        auto id = list->getData(i)->id;
        auto pivotid = pivot->id;
        if (id < pivotid) {
            i++;
        }
        else {
            swap(list, list->getNode(i), list->getNode(j));
            i++;
            j++;
        }
    }
    return j - 1;
 
}
void OrderDA::swap(LinkedList<Order>* list, Node<Order>* low, Node<Order>* high) {

    Node<Order>* prev = nullptr;
    Node<Order>* prev2 = nullptr;
    auto l = list->getHead();
    auto r = list->getHead();

    if (l == nullptr) {
        return;
    }
    if (low->data.id == high->data.id) {
        return;
    }

    while (l != nullptr && l->data.id != low->data.id) {
        prev = l;
        l = l->next;
    }

    while (r != nullptr && r->data.id != high->data.id) {
        prev2 = r;
        r = r->next;
    }

    if (l != nullptr && r != nullptr) {
        if (prev != nullptr) {
            prev->next = r;
        }
        else {
            list->head = r;
        }

        if (prev2 != nullptr) {
            prev2->next = l;
        }
        else {
            list->head = l;
        }
        auto temp = l->next;
        l->next = r->next;
        r->next = temp;
    }
    else {
        return;
    }   

}
Node<Order>* OrderDA::bubbleSwap(Node<Order>* ptr1, Node<Order>* ptr2) {
    Node<Order>* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}