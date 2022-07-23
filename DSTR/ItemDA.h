#pragma once

#include "Item.h"
#include "DynamicArray.h"

using namespace std;

class ItemDA
{
	private:
		const string filepath = "item.txt"; // relative database

	public:

		ItemDA() {};

		// public functions here
		DynamicArray<Item>* getItemData(); // Return all item data
		void addItem(Item item); // Add in dynamic array then store into database

		void displayList(); // Display dynamic array as table form



		void importItem(); // Import item data to dynamic array storage

	private:
		// private functions here
		DynamicArray<Item>* importFromDatabase(); // Import items from database into dynamic array
		void exportToDatabase(); // Export items to database from dynamic array
};

