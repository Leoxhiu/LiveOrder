#include <iostream>
#include <thread>
#include <regex>

#include "MainMenu.h"
#include "ExecutiveRegistration.h"
#include "User.h"
#include "UserDA.h"
#include "Screen.h"

using namespace std;

ExecutiveRegistration::ExecutiveRegistration() {

	UserDA userDA;

	string email, password, name, phoneNumber;

	int id = userDA.getUserData()->getLength() + 1;
	const int type = 1;

	cout << "============================" << endl;
	cout << "    Executive Registration  " << endl;
	cout << "============================\n" << endl;

	cout << "Email address: ";
	cin >> email;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Password: ";
	cin >> password;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Name: ";
	getline(cin,name);

	cout << "Phone Number: ";
	cin >> phoneNumber;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	bool exist = emailExist(email, userDA);
	bool inputValid = false;

	if (exist) {

		cout << "\n-----------------------------" << endl;
		cout << "  Email address exists in database" << endl;
		cout << "-----------------------------" << endl;

		keepLaunch("Try again?...");
	}
	else {
		inputValid = inputValidation(email, password, name, phoneNumber);
	}

	if (inputValid) {
		
		User newExecutive(id, email, password, name, phoneNumber, type);
		userDA.addUser(newExecutive); // put in linked list and store into database

		cout << "\n-----------------------------" << endl;
		cout << "   Registered successfully		" << endl;
		cout << "-----------------------------" << endl;
		keepLaunch("Register again?");
	}
	else {
		keepLaunch("Try again?...");
	}
}

bool ExecutiveRegistration::emailExist(string email, UserDA userDA){

	// exist? 
	UserDA::find result = userDA.findUserByEmail(email);

	if (result == UserDA::find::found) {
		return true;
	}
	else if (result == UserDA::find::notFound) {
		return false;
	}

	return true;
}

bool ExecutiveRegistration::inputValidation(string email, string password, string name, string phoneNumber) {

	bool emailValid, nameValid, phoneNumberValid;

	emailValid = emailValidation(email);
	nameValid = nameValidation(name);
	phoneNumberValid = phoneNumberValidation(phoneNumber);

	if (emailValid && nameValid && phoneNumberValid) {
		return true;
	}
	
	cout << "\n---------Warning----------" << endl;

	if (emailValid == false) {
		cout << "Email addres is invalid" << endl;
	} 

	if (nameValid == false) {
		cout << "Name is invalid" << endl;
	}

	if (phoneNumberValid == false) {
		cout << "Phone number is invalid" << endl;
	}
	cout << "--------------------------" << endl;

	return false;
}

bool ExecutiveRegistration::emailValidation(const string& email) {

	const regex pattern
	("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

	return regex_match(email, pattern);
}

bool ExecutiveRegistration::nameValidation(const string& name) {

	const regex pattern
	("^[a-zA-Z-][a-zA-Z -]*$"); 

	return regex_match(name, pattern);
}

bool ExecutiveRegistration::phoneNumberValidation(const string& phoneNumber) {

	const regex pattern
	("^(01)[0-46-9]*[0-9]{7,8}$");

	return regex_match(phoneNumber, pattern);
}


void ExecutiveRegistration::keepLaunch(string message) {

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
		ExecutiveRegistration ExecutiveRegistration;
		break;
	}
	case 2: {
		Screen::clearScreen();
		MainMenu MainMenu(0);
		break;
	}

	default: {
		cout << "\n-----------------------------" << endl;
		cout << "    Invalid option!            " << endl;
		cout << "-----------------------------" << endl;
		this_thread::sleep_for(std::chrono::seconds(3));
		Screen::clearScreen();
		MainMenu MainMenu(0);
	}
	}

}