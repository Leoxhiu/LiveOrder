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



	private:
		// private functions (connect to database)
		void importFrom(string filepath, LinkedList<Order>* orders); // Import user from database
		void exportTo(string filepath, LinkedList<Order>* orders); // Export user to database
};

