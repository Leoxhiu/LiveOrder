#include <iostream>
#include <thread>

#include "OrderManagement.h"

#include "Screen.h"
#include "Order.h"
#include "OrderDA.h"
#include "UpdateOrder.h"
#include "LinkedList.h"

UpdateOrder::UpdateOrder(int accountType) {

	if (accountType == 0) {

		adminInterface(accountType);
	}
	else if (accountType == 1)
	{
		executiveInterface(accountType);
	}
}

void UpdateOrder::adminInterface(int accountType) {
	cout << "============================" << endl;
	cout << "       Update Order	     " << endl;
	cout << "============================" << endl;

	cout << endl << "Pending orders..." << endl;

	OrderDA orderDA;
	LinkedList<Order>* orderList;
	orderList = orderDA.filterOrderbyCompletion(false);
	orderDA.displayThis(orderList);

	cout << "Update: " << endl <<
		endl <<
		"1. Status" << endl <<
		endl <<
		"2. Completion" << endl
		<< endl
		<< "3. << back" << endl;

	bool valid = false;
	int option;
	int id;
	int stat;
	int complete;

	cin >> option;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	switch (option) {
	case 1: {
		cout << "Order ID: ";
		cin >> id;
		valid = false;
		while (valid == false) {
			cout << endl << "Updated status: " << endl
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
					OrderDA::find found = orderDA.updateOrder(id, "trivia", false, OrderDA::update::status);
					if (found == OrderDA::find::notFound) {
						cout << "Order with such ID is not found.";
						keepLaunch("Try again?", accountType);
						break;
					}
					else if (found == OrderDA::find::found) {
						cout << "Order with ID of " << id << " has been updated.";
						keepLaunch("Continue?", accountType);
						valid = true;
						break;
					}
				}
				else if (stat == 2) {
					OrderDA::find found = orderDA.updateOrder(id, "urgent", false, OrderDA::update::status);
					if (found == OrderDA::find::notFound) {
						cout << "Order with such ID is not found.";
						keepLaunch("Try again?", accountType);
						break;
					}
					else if (found == OrderDA::find::found) {
						cout << "Order with ID of " << id << " has been updated.";
						keepLaunch("Continue?", accountType);
						valid = true;
						break;
					}
				}
			}
		}
		break;
	}
	case 2: {
		cout << "Order ID: ";
		cin >> id;
		valid = false;
		
		while (valid == false) {
			cout << endl << "Updated completion status: " << endl
				<< "1. Completed" << endl
				<< "2. Not Completed" << endl;
			cin >> complete;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "Must be numeric input!" << endl;
			}
			else if (complete != 1 && complete != 2) {
				cin.clear();
				cin.ignore();
				cout << "Invalid option!" << endl;
			}
			else {
				if (complete == 1) {
					OrderDA::find found = orderDA.updateOrder(id, "trivia", true, OrderDA::update::completion);
					if (found == OrderDA::find::notFound) {
						cout << "Order with such ID is not found.";
						keepLaunch("Try again?", accountType);
						break;
					}
					else if (found == OrderDA::find::found) {
						cout << "Order with ID of " << id << " has been updated.";
						keepLaunch("Continue?", accountType);
						valid = true;
						break;
					}
				}
				else if (complete == 2) {
					OrderDA::find found = orderDA.updateOrder(id, "trivia", false, OrderDA::update::completion);
					if (found == OrderDA::find::notFound) {
						cout << "Order with such ID is not found.";
						keepLaunch("Try again?", accountType);
						break;
					}
					else if (found == OrderDA::find::found) {
						cout << "Order with ID of " << id << " has been updated.";
						keepLaunch("Continue?", accountType);
						valid = true;
						break;
					}
				}
			}
		}
		break;
	}
	case 3: {
		Screen::clearScreen();
		OrderManagement OrderManagement(accountType);
		break;
	}
	default: {
		cout << "Invalid option!" << endl;
		this_thread::sleep_for(std::chrono::seconds(3));
		Screen::clearScreen();
		UpdateOrder UpdateOrder(accountType);
	}
	}
}

void UpdateOrder::executiveInterface(int accountType) {
	cout << "============================" << endl;
	cout << "       Update Order	     " << endl;
	cout << "============================" << endl;

	cout << endl << "Pending orders..." << endl;

	OrderDA orderDA;
	LinkedList<Order>* orderList;
	orderList = orderDA.filterOrderbyCompletion(false);
	orderDA.displayThis(orderList);

	cout << "Update: " << endl <<
		endl <<
		"1. Status" << endl <<
		endl <<
		"2. Completion" << endl
		<< endl
		<< "3. << back" << endl;

	bool valid = false;
	int option;
	int id;
	int stat;
	int complete;

	cin >> option;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	switch (option) {
	case 1: {
		cout << "Order ID: ";
		cin >> id;
		valid = false;
		while (valid == false) {
			cout << endl << "Updated status: " << endl
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
					OrderDA::find found = orderDA.updateOrder(id, "trivia", false, OrderDA::update::status);
					if (found == OrderDA::find::notFound) {
						cout << "Order with such ID is not found.";
						keepLaunch("Try again?", accountType);
						break;
					}
					else if (found == OrderDA::find::found) {
						cout << "Order with ID of " << id << " has been updated.";
						keepLaunch("Continue?", accountType);
						valid = true;
						break;
					}
				}
				else if (stat == 2) {
					OrderDA::find found = orderDA.updateOrder(id, "urgent", false, OrderDA::update::status);
					if (found == OrderDA::find::notFound) {
						cout << "Order with such ID is not found.";
						keepLaunch("Try again?", accountType);
						break;
					}
					else if (found == OrderDA::find::found) {
						cout << "Order with ID of " << id << " has been updated.";
						keepLaunch("Continue?", accountType);
						valid = true;
						break;
					}
				}
			}
		}
		break;
	}
	case 2: {
		cout << "Order ID: ";
		cin >> id;
		valid = false;

		while (valid == false) {
			cout << endl << "Updated completion status: " << endl
				<< "1. Completed" << endl
				<< "2. Not Completed" << endl;
			cin >> complete;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "Must be numeric input!" << endl;
			}
			else if (complete != 1 && complete != 2) {
				cin.clear();
				cin.ignore();
				cout << "Invalid option!" << endl;
			}
			else {
				if (complete == 1) {
					OrderDA::find found = orderDA.updateOrder(id, "trivia", true, OrderDA::update::completion);
					if (found == OrderDA::find::notFound) {
						cout << "Order with such ID is not found.";
						keepLaunch("Try again?", accountType);
						break;
					}
					else if (found == OrderDA::find::found) {
						cout << "Order with ID of " << id << " has been updated.";
						keepLaunch("Continue?", accountType);
						valid = true;
						break;
					}
				}
				else if (complete == 2) {
					OrderDA::find found = orderDA.updateOrder(id, "trivia", false, OrderDA::update::completion);
					if (found == OrderDA::find::notFound) {
						cout << "Order with such ID is not found.";
						keepLaunch("Try again?", accountType);
						break;
					}
					else if (found == OrderDA::find::found) {
						cout << "Order with ID of " << id << " has been updated.";
						keepLaunch("Continue?", accountType);
						valid = true;
						break;
					}
				}
			}
		}
		break;
	}
	case 3: {
		Screen::clearScreen();
		OrderManagement OrderManagement(accountType);
		break;
	}
	default: {
		cout << "Invalid option!" << endl;
		this_thread::sleep_for(std::chrono::seconds(3));
		Screen::clearScreen();
		UpdateOrder UpdateOrder(accountType);
	}
	}
}

void UpdateOrder::keepLaunch(string message, int accountType)
{
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
		UpdateOrder UpdateOrder(accountType);
		break;
	}
	case 2: {
		Screen::clearScreen();
		OrderManagement OrderManagement(accountType);
		break;
	}

	default: {
		cout << "\n-----------------------------" << endl;
		cout << "    Invalid option!            " << endl;
		cout << "-----------------------------" << endl;
		this_thread::sleep_for(std::chrono::seconds(3));
		Screen::clearScreen();
		OrderManagement OrderManagement(accountType);
	}
	}
}
