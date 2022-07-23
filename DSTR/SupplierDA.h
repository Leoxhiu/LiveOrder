#pragma once

#include "Supplier.h"
#include "LinkedList.h"

using namespace std;

class SupplierDA
{

	private:
		const string filepath = "supplier.txt"; // relative database

	public:

		SupplierDA() {};

		// public functions here
		LinkedList<Supplier>* getSupplierData(); // Return all supplier data
		void addSupplier(Supplier supplier); // Register in linked list then store into database

		void displayList(); // Display linked list as table form



		void importSupplier(); // Import supplier data to linked list storage

	private:

		// private functions here
		LinkedList<Supplier>* importFromDatabase(); // Import suppliers from database into linked list
		void exportToDatabase(); // Export suppliers to database from linked list
};

