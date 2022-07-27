#include <iostream>
#include <thread>

#include "PurchaseReport.h"
#include "PurchaseReportAction.h"
#include "Screen.h"
#include "Order.h"
#include "OrderDA.h"
#include "LinkedList.h"

using namespace std;

PurchaseReportAction::PurchaseReportAction(string date, string upperdate, int accountType) {
	Initialization(date, upperdate, accountType);
}

void PurchaseReportAction::Initialization(string date, string upperdate, int accountType) {
	cout << "============================" << endl;
	cout << "   Purchase Report Actions  " << endl;
	cout << "============================" << endl;

	OrderDA orderDA;
	orderDA.filterOrderbyDate(date, upperdate, orderDA.getOrderData());
	

	cout << endl << "What are you going to do next?" << endl <<
		endl <<
		"1. Filter purchase report" << endl <<
		"2. Sort purchase report" << endl <<
		endl <<
		"3. << Back to Purchase Report Section" << endl
		<< endl;

	int option;
	cin >> option;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	switch (option) {
	case 1: {
		Screen::clearScreen();
		filterReport(date, upperdate, accountType);
		break;
	}
	case 2: {
		Screen::clearScreen();
		sortReport(date, upperdate, accountType);
		break;
	}
	case 3: {
		Screen::clearScreen();
		PurchaseReport PurchaseReport(accountType);
		break;
	}
	default: {
		cout << "Invalid option!" << endl;
		this_thread::sleep_for(std::chrono::seconds(3));
		Screen::clearScreen();
		PurchaseReportAction PurchaseReportAction(date, upperdate, accountType);
	}
	}

}

void PurchaseReportAction::filterReport(string date, string upperdate, int accountType) {
	cout << "============================" << endl;
	cout << "   Filter Purchase Report   " << endl;
	cout << "============================" << endl;

	OrderDA orderDA;
	orderDA.filterOrderbyDate(date, upperdate, orderDA.getOrderData());
	LinkedList<Order>* tempOrder;

	cout << endl << "Filter by?" << endl <<
		endl <<
		"1. Item ID" << endl <<
		"2. Supplier ID" << endl <<
		"3. Status" << endl <<
		"4. Completion" << endl <<
		endl <<
		"5. << Back" << endl
		<< endl;

	int option;
	cin >> option;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	switch (option) {
	case 1: {
		int ItemID = 0;
		cout << endl << "Desired Item ID (1 until 10):";
		do {
			cin >> ItemID;
			if (ItemID < 1 || ItemID > 10) {
				cout << "Invalid item ID!" << endl;
			}
			else if (ItemID > 0 && ItemID < 11) {
				tempOrder = orderDA.filterOrderbyItemID(ItemID);
				orderDA.filterOrderbyDate(date, upperdate, tempOrder);
				keepLaunch("Continue?", date, upperdate, accountType);
				break;
			}
		} while (ItemID < 1 || ItemID>10);	
		break;
	}
	case 2: {
		int supplierID = 0;
		cout << endl << "Desired Supplier ID (1 until 5):";
		do {
			cin >> supplierID;
			if (supplierID < 1 || supplierID > 5) {
				cout << "Invalid Supplier ID!" << endl;
			}
			else if (supplierID > 0 && supplierID < 6) {
				tempOrder = orderDA.filterOrderbySupplierID(supplierID);
				orderDA.filterOrderbyDate(date, upperdate, tempOrder);
				keepLaunch("Continue?", date, upperdate, accountType);
				break;
			}
		} while (supplierID < 1 || supplierID>5);
		break;
	}
	case 3: {
		int status = 0;
		cout << endl << "Desired Status (1 - trivia, 2 - urgent):";
		do {
			cin >> status;
			if (status != 1 && status != 2) {
				cout << "Invalid input!" << endl;
			}
			else if (status == 1) {
				tempOrder = orderDA.filterOrderbyStatus("trivia");
				orderDA.filterOrderbyDate(date, upperdate, tempOrder);
				keepLaunch("Continue?", date, upperdate, accountType);
				break;
			}
			else if (status == 2) {
				tempOrder = orderDA.filterOrderbyStatus("urgent");
				orderDA.filterOrderbyDate(date, upperdate, tempOrder);
				keepLaunch("Continue?", date, upperdate, accountType);
				break;
			}
		} while (status != 1 && status != 2);
		break;
	}
	case 4: {
		int complete = 0;
		cout << endl << "Desired completion Status (1 - Completed, 2 - Not Completed):";
		do {
			cin >> complete;
			if (complete != 1 && complete != 2) {
				cout << "Invalid input!" << endl;
			}
			else if (complete == 1) {
				tempOrder = orderDA.filterOrderbyCompletion(true);
				orderDA.filterOrderbyDate(date, upperdate, tempOrder);
				keepLaunch("Continue?", date, upperdate, accountType);
				break;
			}
			else if (complete == 2) {
				tempOrder = orderDA.filterOrderbyCompletion(false);
				orderDA.filterOrderbyDate(date, upperdate, tempOrder);
				keepLaunch("Continue?", date, upperdate, accountType);
				break;
			}
		} while (complete != 1 && complete != 2);
		break;
	}
	case 5: {
		Screen::clearScreen();
		PurchaseReportAction PurchaseReportAction(date, upperdate, accountType);
		break;
	}
	default: {
		cout << "Invalid option!" << endl;
		this_thread::sleep_for(std::chrono::seconds(3));
		Screen::clearScreen();
		filterReport(date, upperdate, accountType);
	}
	}
}

void PurchaseReportAction::sortReport(string date, string upperdate, int accountType) {
	cout << "============================" << endl;
	cout << "    Sort Purchase Report    " << endl;
	cout << "============================" << endl;

	OrderDA orderDA;
	orderDA.filterOrderbyDate(date, upperdate, orderDA.getOrderData());

	cout << endl << "Sort by?" << endl <<
		endl <<
		"1. Order ID" << endl <<
		"2. Quantity" << endl <<
		"3. Item ID" << endl <<
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
				LinkedList<Order>* orderData = orderDA.getOrderData();
				orderDA.sortOrderByID(orderData, 0, orderData->getLength() - 1, OrderDA::sortMethod::ascending);
				orderDA.filterOrderbyDate(date, upperdate, orderData);
				keepLaunch("Continue?", date, upperdate, accountType);
				break;
			}
			else if (sortBy == 2) {
				LinkedList<Order>* orderData = orderDA.getOrderData();
				orderDA.sortOrderByID(orderData, 0, orderData->getLength() - 1, OrderDA::sortMethod::descending);
				orderDA.filterOrderbyDate(date, upperdate, orderData);
				keepLaunch("Continue?", date, upperdate, accountType);
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
				LinkedList<Order>* orderData = orderDA.getOrderData();
				orderDA.sortOrderByQuantity(&orderData->head, OrderDA::sortMethod::ascending);
				orderDA.filterOrderbyDate(date, upperdate, orderData);
				keepLaunch("Continue?", date, upperdate, accountType);
				break;
			}
			else if (sortBy == 2) {
				LinkedList<Order>* orderData = orderDA.getOrderData();
				orderDA.sortOrderByQuantity(&orderData->head, OrderDA::sortMethod::descending);
				orderDA.filterOrderbyDate(date, upperdate, orderData);
				keepLaunch("Continue?", date, upperdate, accountType);
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
				LinkedList<Order>* orderData = orderDA.getOrderData();
				orderDA.sortOrderByItemID(&orderData->head, OrderDA::sortMethod::ascending);
				orderDA.filterOrderbyDate(date, upperdate, orderData);
				keepLaunch("Continue?", date, upperdate, accountType);
				break;
			}
			else if (sortBy == 2) {
				LinkedList<Order>* orderData = orderDA.getOrderData();
				orderDA.sortOrderByItemID(&orderData->head, OrderDA::sortMethod::descending);
				orderDA.filterOrderbyDate(date, upperdate, orderData);
				keepLaunch("Continue?", date, upperdate, accountType);
				break;
			}
		} while (sortBy != 1 && sortBy != 2);
		break;
	}
	case 4: {
		Screen::clearScreen();
		PurchaseReport PurchaseReport(accountType);
		break;
	}
	default: {
		cout << "Invalid option!" << endl;
		this_thread::sleep_for(std::chrono::seconds(3));
		Screen::clearScreen();
		sortReport(date, upperdate, accountType);
	}
	}
}

void PurchaseReportAction::keepLaunch(string message, string date, string upperdate, int accountType) {
	int option;

	cout << "\n============================" << endl;
	cout << message << endl;
	cout << "1. yes" << endl;
	cout << "2. Back to purchase report section" << endl;
	cin >> option;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	switch (option) {
	case 1: {
		Screen::clearScreen();
		PurchaseReportAction PurchaseReportAction(date, upperdate, accountType);
		break;
	}
	case 2: {
		Screen::clearScreen();
		PurchaseReport PurchaseReport(accountType);
		break;
	}

	default: {
		cout << "\n-----------------------------" << endl;
		cout << "    Invalid option!            " << endl;
		cout << "-----------------------------" << endl;
		this_thread::sleep_for(std::chrono::seconds(3));
		Screen::clearScreen();
		keepLaunch(message, date, upperdate, accountType);
	}
	}
}