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
		LinkedList<Order>* importOrder(); // Import order data to linked list

		void displayList(LinkedList<Order>* orders);

	private:
		// private functions (connect to database)
		void importFrom(LinkedList<Order>* orders); // Import order from database
		void exportTo(LinkedList<Order>* orders); // Export order to database
};

