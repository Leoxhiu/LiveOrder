#include <iostream>
#include <thread>

#include "YearlyPurchaseReport.h"
#include "Screen.h"
#include "Order.h"
#include "OrderDA.h"
#include "PurchaseReport.h"

using namespace std;

YearlyPurchaseReport::YearlyPurchaseReport(int accountType) {

	Initialization(accountType);

}

void YearlyPurchaseReport::Initialization(int accountType) {

	cout << "============================" << endl;
	cout << "   Yearly Purchase Report  " << endl;
	cout << "============================" << endl;

	string desiredYear;

	cout << "Desired year: ";
	cin >> desiredYear;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void YearlyPurchaseReport::keepLaunch(string message, int accountType) {
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
		YearlyPurchaseReport YearlyPurchaseReport(accountType);
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