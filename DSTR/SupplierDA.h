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



	private:
		// private functions (connect to database)
		void importFrom(string filepath, LinkedList<Supplier>* supplier); // Import supplier from database

};

