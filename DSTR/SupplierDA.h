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
		enum class find { notFound, found };
		enum class sortMethod { ascending, descending };

		// public functions here
		DynamicArray<Supplier>* getSupplierData(); // Return all supplier data
		void addSupplier(Supplier supplier); // Add in dynamic array then store into database

		
		find findSupplierByID(int id); // Find if ID exists by using binary search
		Supplier getSupplierByID(int id); //Get the supplier by ID
		void sortSupplierbyID(sortMethod method); // Sort supplier by ID by using bubble sort

		void displayList(); // Display dynamic array as table form

		void importSupplier(); // Import supplier data to dynamic array storage

	private:
		// private functions here
		DynamicArray<Supplier>* importFromDatabase(); // Import suppliers from database into dynamic array
		void exportToDatabase(); // Export suppliers to database from dynamic array
};

