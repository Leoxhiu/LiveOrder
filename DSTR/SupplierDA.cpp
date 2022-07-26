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
		return find::Found;
	}
	else if (supplierData->getData(high)->id == id) {
		return find::Found;
	}
	else {
		return find::NotFound;
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


void SupplierDA::extendSupplierDetail(int supplierId) {
	cout << "Items selled by this supplier: " << endl
		<< "------------------------------------------" << endl;

	switch (supplierId) {
	case 1: {
		const int size = 1;
		int iid[size];
		string item_name[size];
		double price[size];
		iid[0] = 1;
		item_name[0] = "dyson air purifier";
		price[0] = 500.8;

		for (int i = 0; i < size; i++) {
			cout << "Item ID: " << iid[i] << endl
				<< "Item Name: " << item_name[i] << endl
				<< "Price per item: " << price[i] << endl
				<< "------------------------------------------" << endl;
		}
		break;
	}
	case 2: {
		const int size = 3;
		int iid[size];
		string item_name[size];
		double price[size];
		iid[0] = 2;
		iid[1] = 6;
		iid[2] = 10;
		item_name[0] = "suamsung bluetooth buds";
		item_name[1] = "samsung family refrigerator";
		item_name[2] = "samsung galaxy book2 pro";
		price[0] = 299.0;
		price[1] = 7988.0;
		price[2] = 3399.0;

		for (int i = 0; i < size; i++) {
			cout << "Item ID: " << iid[i] << endl
				<< "Item Name: " << item_name[i] << endl
				<< "Price per item: " << price[i] << endl
				<< "------------------------------------------" << endl;
		}
		break;
	}
	case 3: {
		const int size = 2;
		int iid[size];
		string item_name[size];
		double price[size];
		iid[0] = 3;
		iid[1] = 8;
		item_name[0] = "lenovo ideapad 5";
		item_name[1] = "lenovo 100 stereo";
		price[0] = 599.0;
		price[1] = 95.3;

		for (int i = 0; i < size; i++) {
			cout << "Item ID: " << iid[i] << endl
				<< "Item Name: " << item_name[i] << endl
				<< "Price per item: " << price[i] << endl
				<< "------------------------------------------" << endl;
		}
		break;
	}
	case 4: {
		const int size = 2;
		int iid[size];
		string item_name[size];
		double price[size];
		iid[0] = 4;
		iid[1] = 7;
		item_name[0] = "asus zenfone 8 flip";
		item_name[1] = "asus zenbook 14x";
		price[0] = 2799.0;
		price[1] = 1699.0;

		for (int i = 0; i < size; i++) {
			cout << "Item ID: " << iid[i] << endl
				<< "Item Name: " << item_name[i] << endl
				<< "Price per item: " << price[i] << endl
				<< "------------------------------------------" << endl;
		}
		break;
	}
	case 5: {
		const int size = 2;
		int iid[size];
		string item_name[size];
		double price[size];
		iid[0] = 5;
		iid[1] = 9;
		item_name[0] = "iphone 13 pro";
		item_name[1] = "apple airpods";
		price[0] = 4899.0;
		price[1] = 889.0;

		for (int i = 0; i < size; i++) {
			cout << "Item ID: " << iid[i] << endl
				<< "Item Name: " << item_name[i] << endl
				<< "Price per item: " << price[i] << endl
				<< "------------------------------------------" << endl;
		}
		break;
	}
	}
}

void SupplierDA::chooseSupplier(int supplierId) {
	DynamicArray<Supplier>* supplierData = getSupplierData();
	int size = supplierData->getLength();

	for (int i = 0; i < supplierData->getLength(); i++) {
		Supplier* supplier = supplierData->getData(i);
		if (supplier->id == supplierId) {
			cout << "============================================" << endl
				<< "Supplier ID: " << supplier->id << endl
				<< "Supplier name: " << supplier->name << endl
				<< "Supplier contact: " << supplier->phoneNumber << endl
				<< "Supplier email: " << supplier->email << endl;
			extendSupplierDetail(supplier->id);
		}	
	}
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