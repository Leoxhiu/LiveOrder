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

	printElement("Supplier ID", 15);
	printElement("Name", 20);
	printElement("Phone Number", 20);
	printElement("Email", 25);
	cout << endl;

	for (int i = 0; i < supplierData->getLength(); i++) {
		Supplier* supplier = supplierData->getData(i);
		printElement(supplier->id, 15);
		printElement(supplier->name, 20);
		printElement(supplier->phoneNumber, 20);
		printElement(supplier->email, 25);
		cout << endl;
	}
}

void SupplierDA::sortSupplierbyID(sortMethod method) {
	DynamicArray<Supplier>* supplierData = getSupplierData();
	
	if (method == sortMethod::ascending) {

		int i, j;
		for (i = 0; i < supplierData->getLength() - 1; i++)

			// Last i elements are already 
			// in place
			for (j = 0; j < supplierData->getLength() - i - 1; j++)
				if (supplierData->getData(j)->id > supplierData->getData(j + 1)->id)
					swap(supplierData->data[j], supplierData->data[j + 1]);

	}
	else if (method == sortMethod::descending) {

		int i, j;
		for (i = 0; i < supplierData->getLength() - 1; i++)

			// Last i elements are already 
			// in place
			for (j = 0; j < supplierData->getLength() - i - 1; j++)
				if (supplierData->getData(j)->id < supplierData->getData(j + 1)->id)
					swap(supplierData->data[j], supplierData->data[j + 1]);

	}

}


SupplierDA::find SupplierDA::findSupplierByID(int id) {

	DynamicArray<Supplier>* supplierData = getSupplierData();

	int low = 0, high = supplierData->getLength() - 1;
	int mid;

	// This below check covers all cases , so need to check
	// for mid=lo-(hi-lo)/2
	while (high - low> 1) {
		int mid = (high + low) / 2;
		if (supplierData->getData(mid)->id < id) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}
	if (supplierData->getData(low)->id == id) {
		return find::found;
	}
	else if (supplierData->getData(high)->id == id) {
		return find::found;
	}
	else {
		return find::notFound;
	}

}

Supplier SupplierDA::getSupplierByID(int id) {

	DynamicArray<Supplier>* supplierData = getSupplierData();
	Supplier supplier;
	for (int i = 0; i < supplierData->getLength(); i++)
		if (supplierData->getData(i)->id == id)
			supplier = *supplierData->getData(i);
			return supplier;

	return supplier;
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