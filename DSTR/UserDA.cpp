#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "User.h"
#include "UserDA.h"
#include "LinkedList.h"
#include "Table.h"
#include "Array.h"

using namespace std;

// public functions here
LinkedList<User>* UserDA::importUser() {
	LinkedList<User>* users = new LinkedList<User>();
	importFrom(users);
	return users;
}

LinkedList<User>* UserDA::registerUser(User user) {
	LinkedList<User>* users = importUser();
	users->append(user);
	exportTo(users);

	return users;
}

UserDA::validate UserDA::userValidation(string email, string password, LinkedList<User>* users) {
	UserDA::validate result = UserDA::validate::NotFound;
	for (int i = 0; i < users->length; i++)
	{
		if (email == users->linearSearch(i)->email) {
			result = UserDA::validate::IncorrectPassword;
			if (password == users->linearSearch(i)->password) {
				result = UserDA::validate::Successful;

			}
		}
	}
	return result;
}

UserDA::find UserDA::findUserByEmail(string email, LinkedList<User>* users) {

	UserDA::find result = UserDA::find::NotFound;
	for (int i = 0; i < users->length; i++)
	{
		if (email == users->linearSearch(i)->email) {
			result = UserDA::find::Found;
			}
		
	}
	return result;
}

User UserDA::getUserByEmail(string email, LinkedList<User>* users) {

	User user;
	for (int i = 0; i < users->length ; i++)
	{
		if (email == users->linearSearch(i)->email) {
			
			user.id = users->linearSearch(i)->id;
			user.email = users->linearSearch(i)->email;
			user.password = users->linearSearch(i)->password;
			user.phoneNumber = users->linearSearch(i)->phoneNumber;
			user.type = users->linearSearch(i)->type;

		}
	}

	return user;
}

void UserDA::displayList(LinkedList<User>* users) {

	for (int i = 0; i < users->length; i++) {
		User* user = users->linearSearch(i);
		printElement(user->id, 4);
		printElement(user->email, 25);
		printElement(user->password, 20);
		printElement(user->name, 20);
		printElement(user->phoneNumber, 20);
		cout << endl;
	}
}


// private functions (connect to database)
void UserDA::importFrom(LinkedList<User>* users) {

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
			users->append(user);
		}

	}
	else {

		cout << "Unable to access database.";
	}

}

void UserDA::exportTo(LinkedList<User>* users) {

	fstream file(this->filepath);
	if (file.is_open()) {

		for (int i = 0; i < users->length; i++)
		{
			file << users->linearSearch(i)->id << "," <<
				users->linearSearch(i)->email << "," <<
				users->linearSearch(i)->password << "," <<
				users->linearSearch(i)->name << "," <<
				users->linearSearch(i)->phoneNumber << "," <<
				users->linearSearch(i)->type << endl;
		}

	}
	else {
		cout << "File not open";
	}

}