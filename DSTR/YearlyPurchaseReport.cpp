#include <iostream>
#include <thread>

#include "YearlyPurchaseReport.h"
#include "PurchaseReportAction.h"
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

	int desiredYear = -1;
	string date;
	string upperdate;
	OrderDA orderDA;

	cout << "Current year - type in 0" << endl
		<< "Desired year - type in any year" << endl
		<< "Type 2 to go back." << endl;

	do {
		cin >> desiredYear;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (desiredYear == 0) {
			date = getCurrentDate();
			upperdate = getCurrentDate() + "-12-32";
			break;
		}
		else if (desiredYear > 2000 && desiredYear < 3000) {
			date = to_string(desiredYear);
			upperdate = to_string(desiredYear+1);
			break;
		}
		else if (desiredYear == 2) {
			Screen::clearScreen();
			PurchaseReport PurchaseReport(accountType);
			break;
		}
		else {
			cout << "Invalid input!" << endl;
		}
	} while (desiredYear < 0 || desiredYear >= 3000);

	OrderDA::find found = orderDA.filterOrderbyDate(date, upperdate, orderDA.getOrderData());
	if (found == OrderDA::find::NotFound) {
		keepLaunch("Try again?", accountType);
	}
	else if (found == OrderDA::find::Found) {
		OrderReportAction("Continue?", accountType, date, upperdate);
	}

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

void YearlyPurchaseReport::OrderReportAction(string message, int accountType, string date, string upperdate) {
	int option;

	cout << "\n============================" << endl;
	cout << message << endl;
	cout << "1. More actions on purchase report" << endl;
	cout << "2. Stay in Yearly Purchase Report" << endl;
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
		YearlyPurchaseReport YearlyPurchaseReport(accountType);
		break;
	}

	default: {
		cout << "\n-----------------------------" << endl;
		cout << "    Invalid option!            " << endl;
		cout << "-----------------------------" << endl;
		this_thread::sleep_for(std::chrono::seconds(3));
		Screen::clearScreen();
		OrderReportAction(message, accountType, date, upperdate);
	}
	}
}

string YearlyPurchaseReport::getCurrentDate() {
	time_t now = time(0);
	tm tstruct;
	char buffer[80];
	localtime_s(&tstruct, &now);

	strftime(buffer, sizeof(buffer), "%Y", &tstruct);
	return buffer;
}