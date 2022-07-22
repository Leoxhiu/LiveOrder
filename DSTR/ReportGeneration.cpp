#include <iostream>
#include <thread>

#include "ReportGeneration.h"
#include "Screen.h"
#include "MainMenu.h"
#include "PurchaseReport.h"
#include "SupplierReport.h"
#include "ItemReport.h"

using namespace std;

ReportGeneration::ReportGeneration(int accountType) {

	if (accountType == 0) {

		adminInterface(accountType);
	}
	else if (accountType == 1)
	{

		executiveInterface(accountType);

	}

}

void ReportGeneration::adminInterface(int accountType) { // 0 = admin, 1 = executive

	cout << "=============================" << endl;
	cout << "      Report Generation	 " << endl;
	cout << "=============================" << endl;
	cout << "Which report do you want?" << endl <<
		endl <<
		"1. Purchase Report" << endl <<
		"2. Supplier Report" << endl <<
		"3. Item Report" << endl <<
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
		PurchaseReport PurchaseReport(accountType);
		break;
	}
	case 2: {
		Screen::clearScreen();
		SupplierReport SupplierReport(accountType);
		break;
	}
	case 3: {
		Screen::clearScreen();
		ItemReport ItemReport(accountType);
		break;
	}
	case 4: {
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
		ReportGeneration ReportGeneration(accountType);

	}

	}

}

void ReportGeneration::executiveInterface(int accountType) { // 0 = admin, 1 = executive

	cout << "============================" << endl;
	cout << "      Report Generation	 " << endl;
	cout << "============================" << endl <<
		"1. Purchase Report" << endl <<
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
		PurchaseReport PurchaseReport(accountType);
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
		ReportGeneration ReportGeneration(accountType);

	}

	}
}