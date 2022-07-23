#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Supplier.h"
#include "SupplierDA.h"
#include "Table.h"
#include "DynamicArray.h"
#include "Storage.h";

using namespace std;

// public functions here
DynamicArray<Supplier>* SupplierDA::getSupplierData() {
	Storage<DynamicArray<Supplier>*>* supplierData = supplierData->getInstance(); // find the dynamic array from storage
	return supplierData->getData();
}

void SupplierDA::addSupplier(Supplier supplier) {
	DynamicArray<Supplier>* supplierData = getSupplierData();
	supplierData->append(supplier);
	//exportToDatabase();
}

void SupplierDA::displayList() {

	DynamicArray<Supplier>* supplierData = getSupplierData();
	int size = supplierData->getLength();

	for (int i = 0; i < supplierData->getLength(); i++) {
		Supplier* supplier = supplierData->getData(i);
		printElement(supplier->id, 10);
		printElement(supplier->name, 20);
		printElement(supplier->phoneNumber, 20);
		printElement(supplier->email, 25);
		cout << endl;
	}
}

void SupplierDA::sortSupplierbyName() {

}

void SupplierDA::sortSupplierbyId() {

}



void SupplierDA::importSupplier() {

	// create new instance in storage
	Storage<DynamicArray<Supplier>*>* supplierData = Storage<DynamicArray<Supplier>*>::getInstance();

	// import user data into storage(linked list) from database 
	supplierData->setData(importFromDatabase());
}

// private functions here
DynamicArray<Supplier>* SupplierDA::importFromDatabase() {

	DynamicArray<Supplier>* supplierData = new DynamicArray<Supplier>();

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

	DynamicArray<Supplier>* supplierData = getSupplierData();

	fstream file(this->filepath);
	if (file.is_open()) {

		for (int i = 0; i < supplierData->getLength(); i++)
		{
			file << supplierData->getData(i)->id << "," <<
				supplierData->getData(i)->name << "," <<
				supplierData->getData(i)->phoneNumber << "," <<
				supplierData->getData(i)->email << endl;
		}

	}
	else {
		cout << "Unable to access database.";
	}

}