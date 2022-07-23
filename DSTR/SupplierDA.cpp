#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Supplier.h"
#include "SupplierDA.h"
#include "Table.h"
#include "Array.h"
#include "Storage.h";

using namespace std;

// public functions here
//LinkedList<Supplier>* SupplierDA::getSupplierData() {
//	Storage<LinkedList<Supplier>*>* supplierData = supplierData->getInstance(); // find the linked list from storage
//	return supplierData->getData();
//}

Array<Supplier>* SupplierDA::getSupplierData() {
	Storage<Array<Supplier>*>* supplierData = supplierData->getInstance();
	return supplierData->getData();
}

void SupplierDA::addSupplier(Supplier supplier) {
	Array<Supplier>* supplierData = getSupplierData();
	supplierData->add(supplier);
	//exportToDatabase();
}

void SupplierDA::displayList() {

	Array<Supplier>* supplierData = getSupplierData();
	int size = supplierData->getLength();

	for (int i = 0; i < supplierData->getLength(); i++) {
		Supplier* supplier = supplierData->linearSearch(i);
		printElement(supplier->id, 10);
		printElement(supplier->name, 20);
		printElement(supplier->phoneNumber, 20);
		printElement(supplier->email, 25);
		cout << endl;
	}

}

void SupplierDA::extendSupplierDetail(int sid) {
	cout << "Items selled by this supplier: " << endl
		<< "------------------------------------------" << endl;

	switch (sid) {
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

void SupplierDA::chooseSupplier(int sid) {
	Array<Supplier>* supplierData = getSupplierData();
	int size = supplierData->getLength();
	for (int i = 0; i < size; i++) {
		Supplier* supplier = supplierData->linearSearch(i);
		if (supplier[i].id == sid) {
			cout << "============================================" << endl
				<< "Supplier ID: " << supplier[i].id << endl
				<< "Supplier name: " << supplier[i].name << endl
				<< "Supplier contact: " << supplier[i].phoneNumber << endl
				<< "Supplier email: " << supplier[i].email << endl;
			extendSupplierDetail(supplier[i].id);
		}
	}
}

void SupplierDA::sortSupplierbyName() { //bubble sort
	Array<Supplier>* supplierData = getSupplierData();
	int size = supplierData->getLength();
	int tempID;
	string tempName;
	string tempContact;
	string tempEmail;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < ((size - i) - 1); j++) {
			Supplier* supplier = supplierData->linearSearch(i);
			if (supplier[i].name > supplier[j + 1].name) {
				tempID = supplier[j].id;
				tempName = supplier[j].name;
				tempContact = supplier[j].phoneNumber;
				tempEmail = supplier[j].email;
				supplier[j].id = supplier[j + 1].id;
				supplier[j].name = supplier[j + 1].name;
				supplier[j].phoneNumber = supplier[j + 1].phoneNumber;
				supplier[j].email = supplier[j + 1].email;
				supplier[j + 1].id = tempID;
				supplier[j + 1].name = tempName;
				supplier[j + 1].phoneNumber = tempContact;
				supplier[j + 1].email = tempEmail;
			}
		}
	}
}


void SupplierDA::sortSupplierbyId() { //bubble sort
	Array<Supplier>* supplierData = getSupplierData();
	int size = supplierData->getLength();
	int tempID;
	string tempName;
	string tempContact;
	string tempEmail;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < ((size - i) - 1); j++) {
			Supplier* supplier = supplierData->linearSearch(i);
			if (supplier[i].id > supplier[j + 1].id) {
				tempID = supplier[j].id;
				tempName = supplier[j].name;
				tempContact = supplier[j].phoneNumber;
				tempEmail = supplier[j].email;
				supplier[j].id = supplier[j + 1].id;
				supplier[j].name = supplier[j + 1].name;
				supplier[j].phoneNumber = supplier[j + 1].phoneNumber;
				supplier[j].email = supplier[j + 1].email;
				supplier[j + 1].id = tempID;
				supplier[j + 1].name = tempName;
				supplier[j + 1].phoneNumber = tempContact;
				supplier[j + 1].email = tempEmail;
			}
		}
	}
}

void SupplierDA::importSupplier() {

	// create new instance in storage
	Storage<Array<Supplier>*>* supplierData = Storage<Array<Supplier>*>::getInstance();

	// import user data into storage(linked list) from database 
	supplierData->setData(importFromDatabase());
}

// private functions here
Array<Supplier>* SupplierDA::importFromDatabase() {

	Array<Supplier>* supplierData = new Array<Supplier>(5);

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
			supplierData->add(supplier);
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