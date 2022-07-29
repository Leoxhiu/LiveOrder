#include <iostream>
#include <thread>

#include "Supplier.h"
#include "SupplierDA.h"
#include "ReportGeneration.h"
#include "SupplierReport.h"
#include "Screen.h"
#include "ItemDA.h"

using namespace std;

SupplierReport::SupplierReport(int accountType) {

	SupplierDA supplierDA;
	ItemDA itemDA;

	cout << "============================" << endl;
	cout << " Supplier Report Generation " << endl;
	cout << "============================" << endl << endl;
	
	supplierDA.displayList();

	cout << "What are you going to do next?" << endl <<
		endl <<
		"1. Extend supplier details" << endl <<
		"2. Sort report by supplier ID" << endl <<
		endl <<
		"3. << Back" << endl
		<< endl;

	int option;
	cin >> option;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	switch (option) {
	case 1: {
		int supplierID = 0;
		cout << "Please input supplier ID: ";
		cin >> supplierID;

		SupplierDA::find found = supplierDA.findSupplierByID(supplierID);
		if (found == SupplierDA::find::found) {
			for (int i = 0; i < supplierDA.getSupplierData()->getLength(); i++) {
				Supplier* supplier = supplierDA.getSupplierData()->getData(i);
				if (supplier->id == supplierID) {
					cout << "============================================" << endl
						<< "Supplier ID: " << supplier->id << endl
						<< "Supplier name: " << supplier->name << endl
						<< "Supplier contact: " << supplier->phoneNumber << endl
						<< "Supplier email: " << supplier->email << endl;
				}
			}
			cout << "------------------------------------------" << endl
				<< "Items selled by this supplier: " << endl
				<< "------------------------------------------" << endl;

			for (int i = 0; i < itemDA.getItemData()->getLength(); i++) {
				if (itemDA.getItemByID(i).supplierID == supplierID)
				{
					cout << "Item ID: " << itemDA.getItemByID(i).id << endl
						<< "Item Name: " << itemDA.getItemByID(i).name << endl
						<< "Item Type: " << itemDA.getItemByID(i).type << endl
						<< "Price per item (RM): " << itemDA.getItemByID(i).price << endl
						<< "------------------------------------------" << endl;
				}
				
			}
		
		}
		else if (found == SupplierDA::find::notFound) {
			cout << "Supplier with such ID is not found" << endl;
		}
		
		int opt = 0;
		do {
			cout << endl << "Input 1 to continue: ";
			cin >> opt;
			if (opt == 1) {
				Screen::clearScreen();
				SupplierReport supplierReport(accountType);
				break;
			}
			else if (opt != 0 && opt != 1) {
				cin.ignore();
				cout << "\n-----------------------------" << endl;
				cout << "        Invalid input!       " << endl;
				cout << "-----------------------------" << endl;
			}
		} while (opt != 1);
		break;

	}
	case 2: {
		
		int opt;
		int cont = 0;
		cout << "1. Ascending order" << endl <<
				"2. Descending Order" << endl;
		do {
			opt = 0;
			cin >> opt;
			switch (opt) {
			case 1: {
				supplierDA.sortSupplierbyID(SupplierDA::sortMethod::ascending);
				supplierDA.displayList();
				
				cout << "Enter 1 to continue: ";
				cin >> cont;
				if (cont == 1) {
					Screen::clearScreen();
					SupplierReport supplierReport(accountType);
					break;
				}
				else {
					cin.ignore();
				}
			}
			case 2: {
				supplierDA.sortSupplierbyID(SupplierDA::sortMethod::descending);
				supplierDA.displayList();

				cout << "Enter 1 to continue: ";
				cin >> cont;
				if (cont == 1) {
					Screen::clearScreen();
					SupplierReport supplierReport(accountType);
					break;
				}
				else {
					cin.ignore();
				}
			}
			default: {
				cin.ignore();
				cout << "\n-----------------------------" << endl;
				cout << "        Invalid input!       " << endl;
				cout << "-----------------------------" << endl;
			}
			}
		} while (opt != 1 && opt != 2);
		break;
	}
	case 3: {
		Screen::clearScreen();
		ReportGeneration ReportGeneration(accountType);
		break;
	}
	default: {
		cout << "\n-----------------------------" << endl;
		cout << "        Invalid input!       " << endl;
		cout << "-----------------------------" << endl;
		this_thread::sleep_for(std::chrono::seconds(3));
		Screen::clearScreen();
		SupplierReport SupplierReport(accountType);

	}

	}

}