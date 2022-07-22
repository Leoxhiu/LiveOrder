#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Supplier.h"
#include "SupplierDA.h"
#include "LinkedList.h"
#include "Table.h"

using namespace std;

// public functions here
LinkedList<Supplier>* SupplierDA::importSupplier(){
	LinkedList<Supplier>* suppliers = new LinkedList<Supplier>;
	importFrom(suppliers);
	return suppliers;
}


void SupplierDA::displayList(LinkedList<Supplier>* suppliers) {

	for (int i = 0; i < suppliers->length; i++) {
		Supplier* supplier = suppliers->linearSearch(i);
		printElement(supplier->id, 4);
		printElement(supplier->name, 20);
		printElement(supplier->phoneNumber, 20);
		printElement(supplier->email, 25);
		cout << endl;
	}
}

// private functions (connect to database)
void SupplierDA::importFrom(LinkedList<Supplier>* suppliers) {

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
			suppliers->append(supplier);
		}

	}
	else {

		cout << "Unable to access database.";
	}

}