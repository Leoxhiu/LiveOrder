#include <iostream>
#include <thread>

#include "MonthlyPurchaseReport.h"
#include "PurchaseReportAction.h"
#include "Screen.h"
#include "Order.h"
#include "OrderDA.h"
#include "PurchaseReport.h"

using namespace std;

MonthlyPurchaseReport::MonthlyPurchaseReport(int accountType) {

	initialization(accountType);

}


void MonthlyPurchaseReport::initialization(int accountType) {

	cout << "============================" << endl;
	cout << "   Monthly Purchase Report  " << endl;
	cout << "============================" << endl;

	int desiredMonth = -1;
	string date;
	string upperdate;
	OrderDA orderDA;

	cout << "Current month - type in 0" << endl
		<< "Desired month - type in month in '1 ~ 12'" << endl
		<< "Type 13 to go back." << endl;

	do {
		cin >> desiredMonth;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (desiredMonth == 0) {
			date = getCurrentDate();
			upperdate = getCurrentDate() + "-32";
			break;
		}
		else if (desiredMonth > 0 && desiredMonth < 10) {
			date = "2022-0" + to_string(desiredMonth);
			if (desiredMonth != 9) {
				upperdate = "2022-0" + to_string(desiredMonth+1);
			}
			else if (desiredMonth == 9) {
				upperdate = "2022-10";
			}
			break;
		}
		else if (desiredMonth >= 10 && desiredMonth < 13) {
			date = "2022-" + to_string(desiredMonth);
			upperdate = "2022-" + to_string(desiredMonth+1);
			break;
		}
		else if (desiredMonth == 13) {
			Screen::clearScreen();
			PurchaseReport PurchaseReport(accountType);
		}
		else {
			cout << "Invalid input!" << endl;
		}
	} while (desiredMonth < 0 || desiredMonth >13);
	
	OrderDA::find found = orderDA.filterOrderbyDate(date, upperdate, orderDA.getOrderData());
	if (found == OrderDA::find::notFound) {
		keepLaunch("Try again?", accountType);
	}
	else if (found == OrderDA::find::found) {
		orderReportAction("Continue?", accountType, date, upperdate);
	}
	
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
		keepLaunch(message, accountType);
	}
	}

}

void MonthlyPurchaseReport::orderReportAction(string message, int accountType, string date, string upperdate) {
	int option;

	cout << "\n============================" << endl;
	cout << message << endl;
	cout << "1. More actions on purchase report" << endl;
	cout << "2. Stay in Monthly Purchase Report" << endl;
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
		MonthlyPurchaseReport MonthlyPurchaseReport(accountType);
		break;
	}

	default: {
		cout << "\n-----------------------------" << endl;
		cout << "    Invalid option!            " << endl;
		cout << "-----------------------------" << endl;
		this_thread::sleep_for(std::chrono::seconds(3));
		Screen::clearScreen();
		orderReportAction(message, accountType, date, upperdate);
	}
	}
}

string MonthlyPurchaseReport::getCurrentDate() {
	time_t now = time(0);
	tm tstruct;
	char buffer[80];
	localtime_s(&tstruct, &now);

	strftime(buffer, sizeof(buffer), "%Y-%m", &tstruct);
	return buffer;
}