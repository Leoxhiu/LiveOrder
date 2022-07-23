#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Supplier.h"
#include "SupplierDA.h"
#include "LinkedList.h"
#include "Table.h"
#include "Storage.h";

using namespace std;

// public functions here
LinkedList<Supplier>* SupplierDA::getSupplierData() {
	Storage<LinkedList<Supplier>*>* supplierData = supplierData->getInstance(); // find the linked list from storage
	return supplierData->getData();
}

void SupplierDA::addSupplier(Supplier supplier) {
	LinkedList<Supplier>* supplierData = getSupplierData();
	supplierData->append(supplier);
	//exportToDatabase();
}

void SupplierDA::displayList() {

	LinkedList<Supplier>* supplierData = getSupplierData();

	for (int i = 0; i < supplierData->length; i++) {
		Supplier* supplier = supplierData->linearSearch(i);
		printElement(supplier->id, 10);
		printElement(supplier->name, 20);
		printElement(supplier->phoneNumber, 20);
		printElement(supplier->email, 25);
		cout << endl;
	}

}




void SupplierDA::importSupplier() {

	// create new instance in storage
	Storage<LinkedList<Supplier>*>* supplierData = Storage<LinkedList<Supplier>*>::getInstance();

	// import user data into storage(linked list) from database 
	supplierData->setData(importFromDatabase());
}

// private functions here
LinkedList<Supplier>* SupplierDA::importFromDatabase() {

	LinkedList<Supplier>* supplierData = new LinkedList<Supplier>();

	ifstream file(this->filepath); // read database (relative path)
	if (file.is_open()) {

		string id, name, email, phoneNumber;
		string line;

		while (getline(file, line)) {

			stringstream ss(line);

			getline(ss, id, ',');
			getline(ss, name, ',');
			getline(ss, phoneNumber, ',');
			getline(ss, email, ',');

			Supplier supplier(stoi(id), name, phoneNumber, email);
			supplierData->append(supplier);
		}

	}
	else {

		cout << "Unable to access database.";
	}

	return supplierData;

}

void SupplierDA::exportToDatabase() {

	LinkedList<Supplier>* supplierData = getSupplierData();

	fstream file(this->filepath);
	if (file.is_open()) {

		for (int i = 0; i < supplierData->length; i++)
		{
			file << supplierData->linearSearch(i)->id << "," <<
				supplierData->linearSearch(i)->name << "," <<
				supplierData->linearSearch(i)->phoneNumber << "," <<
				supplierData->linearSearch(i)->email << endl;
		}

	}
	else {
		cout << "Unable to access database.";
	}

}