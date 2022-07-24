#pragma once

#include "Supplier.h"
#include "DynamicArray.h"

using namespace std;

class SupplierDA
{

	private:
		const string filepath = "supplier.txt"; // relative database

	public:

		SupplierDA() {};

		// public functions here
		DynamicArray<Supplier>* getSupplierData(); // Return all supplier data
		void addSupplier(Supplier supplier); // Add in dynamic array then store into database

		void displayList(); // Display dynamic array as table form

		void sortSupplierbyName();
		int searchSupplierbyID(int l, int r, int x);
		Supplier getSupplierByID(int id); //Get the user by ID


		void importSupplier(); // Import supplier data to dynamic array storage

	private:

		// private functions here
		DynamicArray<Supplier>* importFromDatabase(); // Import suppliers from database into dynamic array
		void exportToDatabase(); // Export suppliers to database from dynamic array
};

