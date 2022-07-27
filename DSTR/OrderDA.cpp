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

OrderDA::find OrderDA::updateOrder(int id, string status, bool complete, update opt) {
    LinkedList<Order>* orderData = getOrderData();
    
    if (opt == update::completion) {
        for (int i = 0; i < orderData->getLength(); i++) {
            Order* order = orderData->getData(i);
            if (order->id == id) {
                order->isCompleted = complete;
                return OrderDA::find::Found;
            }
        }
    }
    else if (opt == update::status) {
        for (int i = 0; i < orderData->getLength(); i++) {
            Order* order = orderData->getData(i);
            if (order->id == id) {
                order->status = status;
                return OrderDA::find::Found;
            }
        }
    }

    return OrderDA::find::NotFound;
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

void OrderDA::calcTotalSales(LinkedList<Order>* list) {
    double cost[10];
    double total = 0;

    cost[0] = 500.8;
    cost[1] = 299.0;
    cost[2] = 599.0;
    cost[3] = 2799.0;
    cost[4] = 4899.0;
    cost[5] = 7988.0;
    cost[6] = 1699.0;
    cost[7] = 95.3;
    cost[8] = 889.0;
    cost[9] = 3399.0;

    for (int i = 0; i < list->getLength(); i++) {
        Order* filtered_order = list->getData(i);
        total = total + (filtered_order->quantity * (cost[filtered_order->itemID - 1]));
    }

    cout << endl << "Total amount spent on this duration: RM" << total << "." << endl;
}

void OrderDA::displayThis(LinkedList<Order>* newList) {
    printElement("Order ID", 10);
    printElement("Item ID", 10);
    printElement("Quantity", 10);
    printElement("Date", 20);
    printElement("Supplier ID", 15);
    printElement("Status", 15);
    printElement("isCompleted?", 12);
    cout << endl;

    for (int i = 0; i < newList->getLength(); i++) {
        Order* filtered_order = newList->getData(i);
        printElement(filtered_order->id, 10);
        printElement(filtered_order->itemID, 10);
        printElement(filtered_order->quantity, 10);
        printElement(filtered_order->date, 20);
        printElement(filtered_order->supplierID, 15);
        printElement(filtered_order->status, 15);
        printElement(filtered_order->isCompleted, 12);
        cout << endl;
    }

}

LinkedList<Order>* OrderDA::filterOrderbyCompletion(bool isCompleted) {
    LinkedList<Order>* incompleteOrder = new LinkedList<Order>;

    OrderDA orderDA;
    for (int i = 0; i < orderDA.getOrderData()->getLength(); i++) {
        if (orderDA.getOrderData()->getData(i)->isCompleted == isCompleted) {

            Order order = *orderDA.getOrderData()->getData(i);
            incompleteOrder->append(order);

        }
    }
    return incompleteOrder;
}

LinkedList<Order>* OrderDA::filterOrderbyItemID(int itemId) {
    LinkedList<Order>* incompleteOrder = new LinkedList<Order>;

    OrderDA orderDA;
    for (int i = 0; i < orderDA.getOrderData()->getLength(); i++) {
        if (orderDA.getOrderData()->getData(i)->itemID == itemId) {

            Order order = *orderDA.getOrderData()->getData(i);
            incompleteOrder->append(order);

        }
    }
    return incompleteOrder;
}


LinkedList<Order>* OrderDA::filterOrderbySupplierID(int supplierId) {
    LinkedList<Order>* incompleteOrder = new LinkedList<Order>;

    OrderDA orderDA;
    for (int i = 0; i < orderDA.getOrderData()->getLength(); i++) {
        if (orderDA.getOrderData()->getData(i)->supplierID == supplierId) {

            Order order = *orderDA.getOrderData()->getData(i);
            incompleteOrder->append(order);

        }
    }
    return incompleteOrder;
}


LinkedList<Order>* OrderDA::filterOrderbyStatus(string status) {
    LinkedList<Order>* incompleteOrder = new LinkedList<Order>;

    OrderDA orderDA;
    for (int i = 0; i < orderDA.getOrderData()->getLength(); i++) {
        if (orderDA.getOrderData()->getData(i)->status == status) {

            Order order = *orderDA.getOrderData()->getData(i);
            incompleteOrder->append(order);

        }
    }
    return incompleteOrder;
}

OrderDA::find OrderDA::filterOrderbyDate(string date, string upperdate, LinkedList<Order>* templist) {
    LinkedList<Order>* incompleteOrder = new LinkedList<Order>;
    bool found = false;
    OrderDA orderDA;
    for (int i = 0; i < templist->getLength(); i++) {
        if (templist->getData(i)->date > date && templist->getData(i)->date < upperdate) {
            Order order = *templist->getData(i);
            incompleteOrder->append(order);
            found = true;
        }
    }
    if (found == false) {
        cout << "No order after " << date << " is found." << endl;
        return OrderDA::find::NotFound;
    }
    else if (found == true) {
        orderDA.displayThis(incompleteOrder);
        orderDA.calcTotalSales(incompleteOrder);
        return OrderDA::find::Found;
    }
}

void OrderDA::sortOrderByID(LinkedList<Order>* list, int low, int high, sortMethod method) {
    if (low < high) {
        auto pivot = list->getData(high);
        int pos = partition(list, low, high, pivot, method);
        sortOrderByID(list, low, pos - 1, method);
        sortOrderByID(list, pos + 1, high, method);
    }
}
void OrderDA::sortOrderByQuantity(Node<Order>** headRef, sortMethod method)
{
    Node<Order>* head = *headRef;
    Node<Order>* a;
    Node<Order>* b;

    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);

    /* Recursively sort the sublists */
    sortOrderByQuantity(&a, method);
    sortOrderByQuantity(&b, method);

    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b, sortBy::quantity, method);
}
void OrderDA::sortOrderByItemID(Node<Order>** headRef, sortMethod method)
{
    Node<Order>* head = *headRef;
    Node<Order>* a;
    Node<Order>* b;

    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);

    /* Recursively sort the sublists */
    sortOrderByItemID(&a, method);
    sortOrderByItemID(&b, method);

    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b, sortBy::itemID, method);
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

int OrderDA::partition(LinkedList<Order>* list, int low, int high, Order* pivot, sortMethod method) {
    
    int i = low;
    int j = low;
    while (i <= high) {
        auto id = list->getData(i)->id;
        auto pivotid = pivot->id;
        if (method == sortMethod::ascending) {
            if (id > pivotid) {
                i++;
            }
            else {
                swap(list, list->getNode(i), list->getNode(j));
                i++;
                j++;
            }
        }
        else if (method == sortMethod::descending) {
            if (id < pivotid) {
                i++;
            }
            else {
                swap(list, list->getNode(i), list->getNode(j));
                i++;
                j++;
            }
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

void OrderDA::FrontBackSplit(Node<Order>* source, Node<Order>** frontRef, Node<Order>** backRef)
{
    Node<Order>* fast;
    Node<Order>* slow;
    slow = source;
    fast = source->next;

    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
Node<Order>* OrderDA::SortedMerge(Node<Order>* a, Node<Order>* b, sortBy variable, sortMethod method)
{
    Node<Order>* result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    if (variable == sortBy::quantity) {

        if (method == sortMethod::descending) {

            /* Pick either a or b, and recur */
            if (a->data.quantity >= b->data.quantity) {
                result = a;
                result->next = SortedMerge(a->next, b, variable, method);
            }
            else {
                result = b;
                result->next = SortedMerge(a, b->next, variable, method);
            }
            return (result);

        }
        else if (method == sortMethod::ascending) {

            /* Pick either a or b, and recur */
            if (a->data.quantity <= b->data.quantity) {
                result = a;
                result->next = SortedMerge(a->next, b, variable, method);
            }
            else {
                result = b;
                result->next = SortedMerge(a, b->next, variable, method);
            }
            return (result);

        }

    }
    else if (variable == sortBy::itemID) {

        if (method == sortMethod::descending) {

            /* Pick either a or b, and recur */
            if (a->data.itemID >= b->data.itemID) {
                result = a;
                result->next = SortedMerge(a->next, b, variable, method);
            }
            else {
                result = b;
                result->next = SortedMerge(a, b->next, variable, method);
            }
            return (result);

        }
        else if (method == sortMethod::ascending) {

            /* Pick either a or b, and recur */
            if (a->data.itemID <= b->data.itemID) {
                result = a;
                result->next = SortedMerge(a->next, b, variable, method);
            }
            else {
                result = b;
                result->next = SortedMerge(a, b->next, variable, method);
            }
            return (result);

        }


    }


}