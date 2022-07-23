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
		LinkedList<Supplier>* importSupplier(); // Import supplier data to LinkedList
		void displayList(LinkedList<Supplier>* suppliers);


	private:
		// private functions (connect to database)
		void importFrom(LinkedList<Supplier>* supplier); // Import supplier from database
		void exportTo(LinkedList<Supplier>* suppliers); // Export supplier to database
};

