#pragma once

#include "Order.h"
#include "LinkedList.h"

using namespace std;

class OrderDA
{
	private:
		const string filepath = "order.txt"; // relative database

	public:

		OrderDA() {};
		enum class sortBy { itemID, quantity };
		enum class sortMethod { ascending , descending };

		// public functions here
		LinkedList<Order>* getOrderData(); // Return all order data
		void addOrder(Order order); // Register in linked list then store into database

		void displayList(); // Display linked list as table form

		void displayThis(LinkedList<Order>* newList);
		LinkedList<Order>* filterOrderbyCompletion(bool isCompleted);
		LinkedList<Order>* filterOrderbyItemID(int itemId);
		LinkedList<Order>* filterOrderbySupplierID(int supplierId);
		LinkedList<Order>* filterOrderbyStatus(string status);

		void sortOrderByID(LinkedList<Order>* list, int low, int high, sortMethod method); // Sort order by id using quick sort
		void sortOrderByQuantity(Node<Order>** headRef, sortMethod method); // Sort order by quantity using merge sort
		void sortOrderByItemID(Node<Order>** headRef, sortMethod method); // Sort order by item by using merge sort



		void importOrder(); // Import order data to linked list storage

	private:
		// private functions here
		LinkedList<Order>* importFromDatabase(); // Import orders from database into linked list
		void exportToDatabase(); // Export orders to database from linked list

		// functions for quick sort (ID only)
		int partition(LinkedList<Order>* list, int low, int high, Order* pivot, sortMethod method);
		void swap(LinkedList<Order>* list, Node<Order>* low, Node<Order>* high);

		// functions for merge sort
		void FrontBackSplit(Node<Order>* source, Node<Order>** frontRef, Node<Order>** backRef);
		Node<Order>* SortedMerge(Node<Order>* a, Node<Order>* b, sortBy variable, sortMethod method);
};

