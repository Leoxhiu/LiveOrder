#include <iostream>
#include <thread>

#include "Supplier.h"
#include "SupplierDA.h"
#include "ReportGeneration.h"
#include "SupplierReport.h"
#include "Screen.h"

using namespace std;

SupplierReport::SupplierReport(int accountType) {

	SupplierDA supplierDA;

	cout << "============================" << endl;
	cout << " Supplier Report Generation " << endl;
	cout << "============================" << endl << endl;
	
	supplierDA.displayList();

	cout << "What are you going to do next?" << endl <<
		endl <<
		"1. Extend supplier details" << endl <<
		"2. Sort report" << endl <<
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
		cin >> supplierID;

		SupplierDA::find found = supplierDA.findSupplierByID(supplierID);
		if (found == SupplierDA::find::Found) {
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

			switch (supplierID) {
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
		else if (found == SupplierDA::find::NotFound) {
			cout << "Supplier with such ID is not found" << endl;
		}
		break;
	}
	case 2: {
		Screen::clearScreen();
		SupplierReport SupplierReport(accountType);
		break;
	}
	case 3: {
		Screen::clearScreen();
		break;
	}
	default: {
		cout << "\n-----------------------------" << endl;
		cout << "    Invalid option!            " << endl;
		cout << "-----------------------------" << endl;
		this_thread::sleep_for(std::chrono::seconds(3));
		Screen::clearScreen();
		ReportGeneration ReportGeneration(accountType);

	}

	}

}