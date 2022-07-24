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
		enum class sortBy { id, quantity };


		// public functions here
		LinkedList<Order>* getOrderData(); // Return all order data
		void addOrder(Order order); // Register in linked list then store into database

		void displayList(); // Display linked list as table form

		void sortOrderByID(int low, int high);
		void sortOrderByQuantity();
		
		void importOrder(); // Import order data to linked list storage

	private:
		// private functions here
		LinkedList<Order>* importFromDatabase(); // Import orders from database into linked list
		void exportToDatabase(); // Export orders to database from linked list

		// functions for quick sort (ID)
		int partition(LinkedList<Order>* list, int low, int high, Order* pivot);
		void swap(LinkedList<Order>* list, Node<Order>* low, Node<Order>* high);
		Node<Order>* bubbleSwap(Node<Order>* ptr1, Node<Order>* ptr2);
};

