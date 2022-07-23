#pragma once

#include "Supplier.h"
#include "Array.h"

using namespace std;

class SupplierDA
{

	private:
		const string filepath = "supplier.txt"; // relative database

	public:

		SupplierDA() {};

		// public functions here
		Array<Supplier>* getSupplierData(); // Return all supplier data
		void addSupplier(Supplier supplier); // Register in linked list then store into database

		void displayList(); // Display linked list as table form

		void extendSupplierDetail(int sid);

		void chooseSupplier(int sid);

		void sortSupplierbyName();

		void sortSupplierbyId();

		void importSupplier(); // Import supplier data to linked list storage

	private:

		// private functions here
		Array<Supplier>* importFromDatabase(); // Import suppliers from database into linked list
		void exportToDatabase(); // Export suppliers to database from linked list
};

