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



	private:
		// private functions (connect to database)
		void importFrom(LinkedList<Supplier>* supplier); // Import supplier from database

};

