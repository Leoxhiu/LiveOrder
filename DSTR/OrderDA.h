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

		// public functions here
		LinkedList<Order>* getOrderData(); // Return all order data
		void addOrder(Order order); // Register in linked list then store into database

		void displayList(); // Display linked list as table form



		void importOrder(); // Import order data to linked list storage

	private:
		// private functions here
		LinkedList<Order>* importFromDatabase(); // Import orders from database into linked list
		void exportToDatabase(); // Export orders to database from linked list
};

