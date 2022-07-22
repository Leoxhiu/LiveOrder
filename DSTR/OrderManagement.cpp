#include <iostream>
#include <thread>

#include "OrderManagement.h"
#include "Screen.h"
#include "MainMenu.h"

using namespace std;

OrderManagement::OrderManagement(int accountType) {

	cout << "============================" << endl;
	cout << "       Order Management	 " << endl;
	cout << "============================\n" << endl;
	cout << "What are you going to do next?" << endl <<
		endl <<
		"1. Check order" << endl <<
		"2. Display order" << endl <<
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
		//CheckOrder CheckOrder(accountType);
		break;
	}
	case 2: {
		//DisplayOrder DisplayOrder(accountType);
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
		//ExecutiveRegistration ExecutiveRegistration;
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
