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
		enum class find { notFound, found };
		enum class sortMethod { ascending, descending };

		// public functions here
		DynamicArray<Item>* getItemData(); // Return all item data
		void addItem(Item item); // Add in dynamic array then store into database

		find findItemByID(int id); // Find if ID exists by using binary search
		Item getItemByID(int id); //Get the item by ID

		void sortItembyID(sortMethod method); // Sort item by ID by using bubble sort
		void sortItembyQuantity(sortMethod method); // Sort item by Quantity by using bubble sort
		void sortItembyPrice(sortMethod method); // Sort item by Price by using bubble sort

		void displayList(); // Display dynamic array as table form

		void displayThis(DynamicArray<Item>* newArray);
		void filterItembySupplierID(int supplierId);
		void filterItembyType(string type);

		void importItem(); // Import item data to dynamic array storage
		DynamicArray<Item>* ReturnItemsbySupplierID(int supplierId);

	private:
		// private functions here
		DynamicArray<Item>* importFromDatabase(); // Import items from database into dynamic array
		void exportToDatabase(); // Export items to database from dynamic array
};

