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
		LinkedList<Item>* getItemData(); // Return all item data
		void addItem(Item item); // Add in linked list then store into database

		void displayList(); // Display linked list as table form



		void importItem(); // Import item data to linked list storage

	private:
		// private functions here
		LinkedList<Item>* importFromDatabase(); // Import items from database into linked list
		void exportToDatabase(); // Export items to database from linked list
};

