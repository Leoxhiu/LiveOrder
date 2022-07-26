#include <iostream>
#include <thread>

#include "MonthlyPurchaseReport.h"
#include "Screen.h"
#include "Order.h"
#include "OrderDA.h"
#include "PurchaseReport.h"

using namespace std;

MonthlyPurchaseReport::MonthlyPurchaseReport(int accountType) {

	Initialization(accountType);

}


void MonthlyPurchaseReport::Initialization(int accountType) {

	cout << "============================" << endl;
	cout << "   Monthly Purchase Report  " << endl;
	cout << "============================" << endl;

	string desiredMonth;

	cout << "Desired month: ";
	cin >> desiredMonth;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');



}

void MonthlyPurchaseReport::keepLaunch(string message, int accountType) {
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
		MonthlyPurchaseReport MonthlyPurchaseReport(accountType);
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
		PurchaseReport PurchaseReport(accountType);
	}
	}

}