#include <iostream>
#include <thread>

#include "Screen.h"
#include "MainMenu.h"
#include "Homepage.h"
#include "ExecutiveRegistration.h"
#include "OrderManagement.h";
#include "ReportGeneration.h"

using namespace std;

MainMenu::MainMenu(int accountType) { // 0 = admin, 1 = executive

	if (accountType == 0) {

		adminInterface(accountType);
	}
	else if (accountType == 1)
	{

		executiveInterface(accountType);

	}

}

void MainMenu::adminInterface(int accountType) { // 0 = admin, 1 = executive

	cout << "============================" << endl;
	cout << "       Admin Interface		 " << endl;
	cout << "============================" << endl;
	cout << "What are you going to do next?" << endl <<
		endl <<
		"1. Executive Registration" << endl <<
		"2. Order Management" << endl <<
		"3. Report Generation" << endl <<
		"4. Logout" << endl
		<< endl;

	int option;
	cin >> option;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	switch (option) {
	case 1: {
		Screen::clearScreen();
		ExecutiveRegistration ExecutiveRegistration;
		break;
	}
	case 2: {
		Screen::clearScreen();
		OrderManagement OrderManagement(accountType);
		break;
	}
	case 3: {
		Screen::clearScreen();
		ReportGeneration ReportGeneration(accountType);
		break;
	}
	case 4: {
		Screen::clearScreen();
		Homepage Homepage;
		break;
	}
	default: {
		cout << "Invalid option!" << endl;
		this_thread::sleep_for(std::chrono::seconds(3));
		Screen::clearScreen();
		MainMenu MainMenu(accountType);

	}

	}

}


void MainMenu::executiveInterface(int accountType) { // 0 = admin, 1 = executive

	cout << "============================" << endl;
	cout << "     Executive Interface	 " << endl;
	cout << "============================" << endl;
	cout << "What are you going to do next?" << endl <<
		endl <<
		"1. Order Management" << endl <<
		"2. Report Generation" << endl <<
		"3. Logout" << endl
		<< endl;

	int option;
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
		ReportGeneration ReportGeneration(accountType);
		break;
	}
	case 3: {
		Screen::clearScreen();
		Homepage Homepage;
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