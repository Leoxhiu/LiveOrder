#include <iostream>
#include <thread>

#include "PurchaseReport.h"
#include "Screen.h"
#include "ReportGeneration.h"
#include "MonthlyPurchaseReport.h"


using namespace std;

PurchaseReport::PurchaseReport(int accountType) { // 0 = admin, 1 = executive

	if (accountType == 0) {

		adminInterface(accountType);
	}
	else if (accountType == 1)
	{

		executiveInterface(accountType);

	}

}


void PurchaseReport::adminInterface(int accountType) { // 0 = admin, 1 = executive

	cout << "============================" << endl;
	cout << " Purchase Report Generation " << endl;
	cout << "============================" << endl <<
		"1. Yearly" << endl <<
		"2. Monthly" << endl <<
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
		// generate yearly purchase report
		break;
	}
	case 2: {
		Screen::clearScreen();
		MonthlyPurchaseReport MonthlyPurchaseReport(accountType);
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
		PurchaseReport PurchaseReport(accountType);

	}

	}

}

void PurchaseReport::executiveInterface(int accountType) { // 0 = admin, 1 = executive

	cout << "============================" << endl;
	cout << " Purchase Report Generation " << endl;
	cout << "============================" << endl <<
		"1. Monthly" << endl <<
		endl <<
		"2. << Back" << endl
		<< endl;

	int option;
	cin >> option;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	switch (option) {
	case 1: {
		Screen::clearScreen();
		MonthlyPurchaseReport MonthlyPurchaseReport(accountType);
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
		PurchaseReport PurchaseReport(accountType);

	}

	}
}