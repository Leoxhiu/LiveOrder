#include <iostream>
#include <thread>

#include "Screen.h"
#include "Login.h"
#include "UserDA.h"
#include "Homepage.h"
#include "MainMenu.h"

Login::Login() {

	string email,password;

	cout << "============================" << endl;
	cout << "           Login		     " << endl;
	cout << "============================" << endl;

	cout << "Email address: ";
	cin >> email;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Password: ";
	cin >> password;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	UserDA userDA;
	UserDA::validate result = userDA.userValidation(email, password, userDA.importUser());

	if (result == UserDA::validate::Successful) {

		// if email and password correct, identify user type (0 = admin, 1 = executive)
		User user = userDA.getUserByEmail(email, userDA.importUser());
		Screen::clearScreen();
		MainMenu MainMenu(user.type);
	}
	else if (result == UserDA::validate::IncorrectPassword) {

		cout << "\n-----------------------------" << endl;
		cout << "     Incorrect password.   " << endl;
		cout << "-----------------------------" << endl;
		keepLaunch("Try again?...");

	}
	else {
		cout << "\n-----------------------------" << endl;
		cout << "     Account not found.    " << endl;
		cout <<   "-----------------------------" << endl;
		keepLaunch("Try again?...");
	}
}

void Login::keepLaunch(string message) {

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
		Login login;
		break;
	}
	case 2: {
		Screen::clearScreen();
		Homepage home;
		break;
	}

	default: {
		cout << "\n-----------------------------" << endl;
		cout << "    Invalid option!            " << endl;
		cout << "-----------------------------" << endl;
		this_thread::sleep_for(std::chrono::seconds(3));
		Screen::clearScreen();
		Homepage home;
	}
	}

}