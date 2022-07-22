#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

#include "User.h"
#include "UserDA.h"
#include "LinkedList.h"
#include "Table.h"
#include "Array.h"

using namespace std;


LinkedList<User>* UserDA::importUser() {
	LinkedList<User>* users = new LinkedList<User>();
	importFrom("user.txt", users);
	return users;
}

LinkedList<User>* UserDA::registerUser(User user) {
	LinkedList<User>* users = importUser();
	users->append(user);
	exportTo("user.txt", users);

	return users;
}

UserDA::validate UserDA::userValidation(string email, string password, LinkedList<User>* users) {
	UserDA::validate result = UserDA::validate::NotFound;
	for (int i = 0; i < users->length; i++)
	{
		if (email == users->get(i)->email) {
			result = UserDA::validate::IncorrectPassword;
			if (password == users->get(i)->password) {
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
		if (email == users->get(i)->email) {
			result = UserDA::find::Found;
			}
		
	}
	return result;
}

User UserDA::getUserByEmail(string email, LinkedList<User>* users) {

	User user;
	for (int i = 0; i < users->length ; i++)
	{
		if (email == users->get(i)->email) {
			
			user.id = users->get(i)->id;
			user.email = users->get(i)->email;
			user.password = users->get(i)->password;
			user.phoneNumber = users->get(i)->phoneNumber;
			user.type = users->get(i)->type;

		}
	}

	return user;
}



void UserDA::displayList(LinkedList<User>* users) {

	LinkedList<User>* temp_users = users;

	for (int i = 0; i < temp_users->length; i++) {
		User* user = temp_users->get(i);
		printElement(user->id, 4);
		printElement(user->email, 25);
		printElement(user->password, 20);
		printElement(user->name, 20);
		printElement(user->phoneNumber, 20);
		cout << endl;
	}
	users = temp_users;
}

void UserDA::importFrom(string filepath, LinkedList<User>* users) {

	ifstream file(filepath); // read database (relative path)
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

void UserDA::exportTo(string filepath, LinkedList<User>* users) {

	fstream file(filepath);
	if (file.is_open()) {

		for (int i = 0; i < users->length; i++)
		{
			file << users->get(i)->id << "," <<
				users->get(i)->email << "," <<
				users->get(i)->password << "," <<
				users->get(i)->name << "," <<
				users->get(i)->phoneNumber << "," <<
				users->get(i)->type << endl;
		}

	}
	else {
		cout << "File not open";
	}

}