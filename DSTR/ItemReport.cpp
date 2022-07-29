#include <iostream>
#include <thread>

#include "ItemReport.h"
#include "Screen.h"
#include "Item.h"
#include "ItemDA.h"
#include "ReportGeneration.h"

using namespace std;

ItemReport::ItemReport(int accountType) {

	initialization(accountType);
}

void ItemReport::initialization(int accountType) {
	cout << "============================" << endl;
	cout << "   Item Report Generation   " << endl;
	cout << "============================" << endl;

	ItemDA itemDA;
	itemDA.displayList();

	cout << endl << "What do you want to do?" << endl <<
		endl <<
		"1. Filter Item" << endl <<
		"2. Sort Item" << endl <<
		endl <<
		"3. << Back" << endl
		<< endl;

	int option;

	cin >> option;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	switch (option) {
	case 1: {
		Screen::clearScreen();
		filterItem(accountType);
		break;
	}
	case 2: {
		Screen::clearScreen();
		sortItem(accountType);
		break;
	}
	case 3: {
		Screen::clearScreen();
		ReportGeneration ReportGeneration(accountType);
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

void ItemReport::filterItem(int accountType) {
	cout << "============================" << endl;
	cout << "        Filter Item         " << endl;
	cout << "============================" << endl;

	ItemDA itemDA;
	itemDA.displayList();

	cout << endl << "Filter by:" << endl <<
		endl <<
		"1. Supplier ID" << endl <<
		"2. Item Type" << endl <<
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
		cout << endl << "Desired Supplier ID (1 until 5):";
		do {
			cin >> supplierID;
			if (supplierID < 1 || supplierID > 5) {
				cout << "Invalid Supplier ID!" << endl;
			}
			else if (supplierID > 0 && supplierID < 6) {
				itemDA.filterItembySupplierID(supplierID);
				keepLaunchFilter("Continue?", accountType);
				break;
			}
		} while (supplierID < 1 || supplierID>5);
		break;
	}
	case 2: {
		int type = 0;
		cout << endl << "Desired Item Type:" << endl
			<< "1. audio type" << endl
			<< "2. laptop type" << endl
			<< "3. Home appliance type" << endl
			<< "4. Smartphone type" << endl;
		do {
			cin >> type;
			switch (type) {
			case 1: {
				itemDA.filterItembyType("audio");
				keepLaunchFilter("Continue?", accountType);
				break;
			}
			case 2: {
				itemDA.filterItembyType("laptop");
				keepLaunchFilter("Continue?", accountType);
				break;
			}
			case 3: {
				itemDA.filterItembyType("home appliance");
				keepLaunchFilter("Continue?", accountType);
				break;
			}
			case 4: {
				itemDA.filterItembyType("smartphone");
				keepLaunchFilter("Continue?", accountType);
				break;
			}
			default: {
				cout << "Invalid input!" << endl;
			}
			}	
		} while (type < 1 || type > 4);
		break;
	}
	case 3: {
		Screen::clearScreen();
		ItemReport ItemReport(accountType);
		break;
	}
	default: {
		cout << "\n-----------------------------" << endl;
		cout << "    Invalid option!            " << endl;
		cout << "-----------------------------" << endl;
		this_thread::sleep_for(std::chrono::seconds(3));
		Screen::clearScreen();
		filterItem(accountType);
	}
	}
}

void ItemReport::sortItem(int accountType) {
	cout << "============================" << endl;
	cout << "         Sort Item          " << endl;
	cout << "============================" << endl;

	ItemDA itemDA;
	itemDA.displayList();

	cout << endl << "Sort by:" << endl <<
		endl <<
		"1. Item ID" << endl <<
		"2. Quantity" << endl <<
		"3. Price" << endl <<
		endl <<
		"4. << Back" << endl
		<< endl;

	int option;

	cin >> option;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	switch (option) {
	case 1: {
		int sortBy = 0;
		cout << endl << "Sort By (1 - ascending, 2 - descending):";
		do {
			cin >> sortBy;
			if (sortBy != 1 && sortBy != 2) {
				cout << "Invalid input!" << endl;
			}
			else if (sortBy == 1) {
				itemDA.sortItembyID(ItemDA::sortMethod::ascending);
				itemDA.displayList();
				keepLaunchSort("Continue?", accountType);
				break;
			}
			else if (sortBy == 2) {
				itemDA.sortItembyID(ItemDA::sortMethod::descending);
				itemDA.displayList();
				keepLaunchSort("Continue?", accountType);
				break;
			}
		} while (sortBy != 1 && sortBy != 2);
		break;
	}
	case 2: {
		int sortBy = 0;
		cout << endl << "Sort By (1 - ascending, 2 - descending):";
		do {
			cin >> sortBy;
			if (sortBy != 1 && sortBy != 2) {
				cout << "Invalid input!" << endl;
			}
			else if (sortBy == 1) {
				itemDA.sortItembyQuantity(ItemDA::sortMethod::ascending);
				itemDA.displayList();
				keepLaunchSort("Continue?", accountType);
				break;
			}
			else if (sortBy == 2) {
				itemDA.sortItembyQuantity(ItemDA::sortMethod::descending);
				itemDA.displayList();
				keepLaunchSort("Continue?", accountType);
				break;
			}
		} while (sortBy != 1 && sortBy != 2);
		break;
	}
	case 3: {
		int sortBy = 0;
		cout << endl << "Sort By (1 - ascending, 2 - descending):";
		do {
			cin >> sortBy;
			if (sortBy != 1 && sortBy != 2) {
				cout << "Invalid input!" << endl;
			}
			else if (sortBy == 1) {
				itemDA.sortItembyPrice(ItemDA::sortMethod::ascending);
				itemDA.displayList();
				keepLaunchSort("Continue?", accountType);
				break;
			}
			else if (sortBy == 2) {
				itemDA.sortItembyPrice(ItemDA::sortMethod::descending);
				itemDA.displayList();
				keepLaunchSort("Continue?", accountType);
				break;
			}
		} while (sortBy != 1 && sortBy != 2);
		break;
	}
	case 4: {
		Screen::clearScreen();
		ItemReport ItemReport(accountType);
		break;
	}
	default: {
		cout << "\n-----------------------------" << endl;
		cout << "    Invalid option!            " << endl;
		cout << "-----------------------------" << endl;
		this_thread::sleep_for(std::chrono::seconds(3));
		Screen::clearScreen();
		sortItem(accountType);
	}
	}
}

void ItemReport::keepLaunchSort(string message, int accountType) {
	int option;

	cout << "\n============================" << endl;
	cout << message << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cin >> option;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	switch (option) {
	case 1: {
		Screen::clearScreen();
		sortItem(accountType);
		break;
	}
	case 2: {
		Screen::clearScreen();
		ItemReport ItemReport(accountType);
		break;
	}

	default: {
		cout << "\n-----------------------------" << endl;
		cout << "    Invalid option!            " << endl;
		cout << "-----------------------------" << endl;
		this_thread::sleep_for(std::chrono::seconds(3));
		Screen::clearScreen();
		keepLaunchSort(message, accountType);
	}
	}
}

void ItemReport::keepLaunchFilter(string message, int accountType) {
	int option;

	cout << "\n============================" << endl;
	cout << message << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cin >> option;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	switch (option) {
	case 1: {
		Screen::clearScreen();
		filterItem(accountType);
		break;
	}
	case 2: {
		Screen::clearScreen();
		ItemReport ItemReport(accountType);
		break;
	}

	default: {
		cout << "\n-----------------------------" << endl;
		cout << "    Invalid option!            " << endl;
		cout << "-----------------------------" << endl;
		this_thread::sleep_for(std::chrono::seconds(3));
		Screen::clearScreen();
		keepLaunchFilter(message, accountType);
	}
	}
}