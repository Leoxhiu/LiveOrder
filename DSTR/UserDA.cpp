#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Storage.h"
#include "User.h"
#include "UserDA.h"
#include "LinkedList.h"
#include "Table.h"

using namespace std;

// public functions here
LinkedList<User>* UserDA::getUserData() {
	Storage<LinkedList<User>*>* userData = userData->getInstance(); // find the linked list from storage
	return userData->getData();
}

void UserDA::addUser(User user) {
	LinkedList<User>* userData = getUserData();
	userData->append(user);
	//exportToDatabase();
}

UserDA::validate UserDA::userValidation(string email, string password) {
	LinkedList<User>* userData = getUserData();
	UserDA::validate result = UserDA::validate::NotFound;

	for (int i = 0; i < userData->getLength(); i++)
	{
		if (email == userData->linearSearch(i)->email) {
			result = UserDA::validate::IncorrectPassword;
			if (password == userData->linearSearch(i)->password) {
				result = UserDA::validate::Successful;

			}
		}
	}
	return result;
}

UserDA::find UserDA::findUserByEmail(string email) {
	LinkedList<User>* userData = getUserData();
	UserDA::find result = UserDA::find::NotFound;

	for (int i = 0; i < userData->getLength(); i++)
	{
		if (email == userData->linearSearch(i)->email) {
			result = UserDA::find::Found;
			}
		
	}
	return result;
}

User UserDA::getUserByEmail(string email) {

	User user;
	LinkedList<User>* users = getUserData();

	for (int i = 0; i < users->getLength(); i++)
	{
		if (email == users->linearSearch(i)->email) {

			user.id = users->linearSearch(i)->id;
			user.email = users->linearSearch(i)->email;
			user.password = users->linearSearch(i)->password;
			user.name = users->linearSearch(i)->name;
			user.phoneNumber = users->linearSearch(i)->phoneNumber;
			user.type = users->linearSearch(i)->type;

		}
	}

	return user;
}

void UserDA::displayList() {

	LinkedList<User>* users = getUserData();

	for (int i = 0; i < users->getLength(); i++) {
		User* user = users->linearSearch(i);
		printElement(user->id, 4);
		printElement(user->email, 25);
		printElement(user->password, 20);
		printElement(user->name, 20);
		printElement(user->phoneNumber, 15);
		printElement(user->type, 5);
		cout << endl;
	}
}




void UserDA::importUser() {

	// create new instance in storage
	Storage<LinkedList<User>*>* userData = Storage<LinkedList<User>*>::getInstance();

	// import user data into storage(linked list) from database 
	userData->setData(importFromDatabase());

}

// private functions here
LinkedList<User>* UserDA::importFromDatabase() {

	LinkedList<User>* userData = new LinkedList<User>();

	ifstream file(this->filepath); // read database (relative path)
	if (file.is_open()) {

		string id, email, password, name, phoneNumber, type;
		string line;

		while (getline(file, line)) {

			stringstream ss(line);

			getline(ss, id, ',');
			getline(ss, email, ',');
			getline(ss, password, ',');
			getline(ss, name, ',');
			getline(ss, phoneNumber, ',');
			getline(ss, type, ',');

			User user(stoi(id), email, password, name, phoneNumber, stoi(type));
			userData->append(user);
		}

	}
	else {

		cout << "Unable to access database.";
	}

	return userData;

}

void UserDA::exportToDatabase() {

	LinkedList<User>* userData = getUserData();

	fstream file(this->filepath);
	if (file.is_open()) {

		for (int i = 0; i < userData->getLength(); i++)
		{
			file << userData->linearSearch(i)->id << "," <<
				userData->linearSearch(i)->email << "," <<
				userData->linearSearch(i)->password << "," <<
				userData->linearSearch(i)->name << "," <<
				userData->linearSearch(i)->phoneNumber << "," <<
				userData->linearSearch(i)->type << endl;
		}

	}
	else {
		cout << "Unable to access database.";
	}

}