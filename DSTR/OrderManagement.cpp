#include <iostream>
#include <thread>

#include "OrderManagement.h"

#include "Screen.h"
#include "Order.h"
#include "LinkedList.h"
#include "OrderDA.h"
#include "updateOrder.h"
#include "MainMenu.h"
#include "ItemDA.h"
#include "SupplierDA.h"


using namespace std;

OrderManagement::OrderManagement(int accountType) { // 0 = admin, 1 = executive

	if (accountType == 0) {

		adminInterface(accountType);
	}
	else if (accountType == 1)
	{
		executiveInterface(accountType);
	}

}

void OrderManagement::adminInterface(int accountType) {

	cout << "============================" << endl;
	cout << "       Order Management	 " << endl;
	cout << "============================" << endl;

	cout << endl << "Pending orders..." << endl;

	OrderDA orderDA;
	LinkedList<Order>* orderList;
	orderList = orderDA.filterOrderbyCompletion(false);
	orderDA.displayThis(orderList);

	cout << endl << "What are you going to do next?" << endl <<
		endl <<
		"1. Update order" << endl <<
		"2. Record new order" << endl <<
		"3. Display all order" << endl <<
		endl <<
		"4. << Back" << endl
		<< endl;

	int option;
	cin >> option;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	switch (option) {
	case 1: {
		Screen::clearScreen();
		UpdateOrder UpdateOrder(accountType);
		break;
	}
	case 2: {
		ItemDA itemDA;
		SupplierDA supplierDA;

		int id = orderDA.getOrderData()->getLength() + 1;
		int itemID = 0;
		int supplierID = 0;
		int quantity = 0;
		string date;
		int stat = 0;
		string status;
		bool valid = false;

		while (valid == false) {
			cout << endl << "Item ID: ";
			cin >> itemID;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "Must be numeric input!" << endl;
			}
			else if (itemDA.findItemByID(itemID) == ItemDA::find::notFound){
				cin.clear();
				cin.ignore();
				cout << "Item ID must be in between 1 and 10!" << endl;
			}
			else {
				supplierID = itemDA.getItemByID(itemID).supplierID;
				cout << "Supplier ID is automatically set as " << supplierID << " to match with Item ID of " << itemID << "." << endl;
				valid = true;
				break;
			}
		}

		valid = false;
		while (valid == false) {
			cout << endl << "Quantity: ";
			cin >> quantity;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "Must be numeric input!" << endl;
			}
			else if (quantity < 1) {
				cin.clear();
				cin.ignore();
				cout << "Quantity cannot be 0 or negative number!" << endl;
			}
			else {
				valid = true;
				break;
			}
		}

		date = getCurrentDate();

		valid = false;
		while (valid == false) {
			cout << endl << "Order status: " << endl
				<< "1. trivia" << endl
				<< "2. urgent" << endl;
			cin >> stat;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "Must be numeric input!" << endl;
			}
			else if (stat != 1 && stat != 2) {
				cin.clear();
				cin.ignore();
				cout << "Invalid option!" << endl;
			}
			else {
				if (stat == 1) {
					status = "trivia";
					valid = true;
					break;
				}
				else if (stat == 2) {
					status = "urgent";
					valid = true;
					break;
				}
			}
		}

		Order newOrder(id, itemID, quantity, date, supplierID, status, false);
		orderDA.addOrder(newOrder);

		cout << "\n-----------------------------" << endl;
		cout << "   Recorded successfully     " << endl;
		cout << "-----------------------------" << endl;
		keepLaunch("Continue?", accountType);

		break;
	}
	case 3: {
		orderDA.displayList();
		keepLaunch("Continue?", accountType);
		break;
	}
	case 4: {
		Screen::clearScreen();
		MainMenu MainMenu(accountType);
		break;
	}
	default: {
		cout << "Invalid option!" << endl;
		this_thread::sleep_for(std::chrono::seconds(3));
		Screen::clearScreen();
		OrderManagement OrderManagement(accountType);
	}
	}

}

void OrderManagement::executiveInterface(int accountType) {

	cout << "============================" << endl;
	cout << "       Order Management	 " << endl;
	cout << "============================" << endl;

	cout << endl << "Pending orders..." << endl;

	OrderDA orderDA;
	LinkedList<Order>* orderList;
	orderList = orderDA.filterOrderbyCompletion(false);
	orderDA.displayThis(orderList);

	cout << "What are you going to do next?" << endl <<
		endl <<
		"1. Update Order" << endl <<
		"2. Display all orders" << endl <<
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
		UpdateOrder UpdateOrder(accountType);
		break;
	}
	case 2: {
		orderDA.displayList();
		keepLaunch("Continue?", accountType);
		break;
	}
	case 3: {
		Screen::clearScreen();
		MainMenu MainMenu(accountType);
		break;
	}
	default: {
		cout << "Invalid option!" << endl;
		this_thread::sleep_for(std::chrono::seconds(3));
		Screen::clearScreen();
		OrderManagement OrderManagement(accountType);
	}
	}

}

void OrderManagement::keepLaunch(string message, int accountType) {
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
		OrderManagement OrderManagement(accountType);
		break;
	}
	case 2: {
		Screen::clearScreen();
		MainMenu MainMenu(accountType);
		break;
	}

	default: {
		cout << "\n-----------------------------" << endl;
		cout << "    Invalid option!            " << endl;
		cout << "-----------------------------" << endl;
		this_thread::sleep_for(std::chrono::seconds(3));
		Screen::clearScreen();
		MainMenu MainMenu(accountType);
	}
	}
}

string OrderManagement::getCurrentDate() {
	time_t now = time(0);
	tm tstruct;
	char buffer[80];
	localtime_s(&tstruct, &now);

	strftime(buffer, sizeof(buffer), "%Y-%m-%d", &tstruct);
	return buffer;
}
