#pragma once

#include "Item.h"
#include "LinkedList.h"

using namespace std;

class ItemDA
{
	private:
		const string filepath = "item.txt"; // relative database

	public:

		ItemDA() {};

		// public functions here
		LinkedList<Item>* importItem(); // Import item data to linked list

		void displayList(LinkedList<Item>* items);

	private:
		// private functions (connect to database)
		void importFrom(LinkedList<Item>* items); // Import item from database
		void exportTo(LinkedList<Item>* items); // Export item to database
};

