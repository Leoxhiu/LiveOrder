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
		if (email == userData->getData(i)->email) {
			result = UserDA::validate::IncorrectPassword;
			if (password == userData->getData(i)->password) {
				result = UserDA::validate::Successful;

			}
		}
	}
	return result;
}


// Used for binary search (findUserByID)
Node<User>* middle(Node<User>* start, Node<User>* last)
{
	if (start == nullptr)
		return nullptr;

	Node<User>* slow = start;
	Node<User>* fast = start->next;

	while (fast != last)
	{
		fast = fast->next;
		if (fast != last)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	return slow;
}
UserDA::find UserDA::findUserByID(int id)
{
	LinkedList<User>* userData = getUserData();
	Node<User>* start = userData->getHead();
	Node<User>* last = nullptr;

	do
	{
		// Find middle
		Node<User>* mid = middle(start, last);

		// If middle is empty
		if (mid == nullptr)
			return UserDA::find::NotFound;

		// If value is present at middle
		if (mid->data.id == id)
			return UserDA::find::Found;

		// If value is more than mid
		else if (mid->data.id < id)
			start = mid->next;

		// If the value is less than mid.
		else
			last = mid;

	} while (last == NULL ||
		last != start);

	// value not present
	return UserDA::find::NotFound;
}
User UserDA::getUserByID(int id) {

	LinkedList<User>* userData = getUserData();
	Node<User>* current = userData->getHead(); // Initialize current
	while (current != nullptr)
	{
		if (current->data.id == id)
			return current->data;
		current = current->next;
	}

}

void UserDA::sortUserByID(LinkedList<User>* list, int low, int high) {
	if (low < high) {
		auto pivot = list->getData(high);
		int pos = partition(list, low, high, pivot);
		sortUserByID(list, low, pos - 1);
		sortUserByID(list, pos + 1, high);
	}
}


UserDA::find UserDA::findUserByEmail(string email) {
	LinkedList<User>* userData = getUserData();
	UserDA::find result = UserDA::find::NotFound;

	for (int i = 0; i < userData->getLength(); i++)
	{
		if (email == userData->getData(i)->email) {
			result = UserDA::find::Found;
			}
		
	}
	return result;
}
User UserDA::getUserByEmail(string email)
{
	LinkedList<User>* userData = getUserData();
	Node<User>* current = userData->getHead(); // Initialize current
	while (current != nullptr)
	{
		if (current->data.email == email)
			return current->data;
		current = current->next;
	}

}


void UserDA::displayList() {

	LinkedList<User>* users = getUserData();

	for (int i = 0; i < users->getLength(); i++) {
		User* user = users->getData(i);
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
			file << userData->getData(i)->id << "," <<
				userData->getData(i)->email << "," <<
				userData->getData(i)->password << "," <<
				userData->getData(i)->name << "," <<
				userData->getData(i)->phoneNumber << "," <<
				userData->getData(i)->type << endl;
		}

	}
	else {
		cout << "Unable to access database.";
	}

}

int UserDA::partition(LinkedList<User>* list, int low, int high, User* pivot) {
	int i = low;
	int j = low;
	while (i <= high) {
		auto id = list->getData(i)->id;
		auto pivotid = pivot->id;
		if (id < pivotid) {
			i++;
		}
		else {
			swap(list, list->getNode(i), list->getNode(j));
			i++;
			j++;
		}
	}
	return j - 1;
}
void UserDA::swap(LinkedList<User>* list, Node<User>* low, Node<User>* high) {
	Node<User>* prev = nullptr;
	Node<User>* prev2 = nullptr;
	auto l = list->getHead();
	auto r = list->getHead();

	if (l == nullptr) {
		return;
	}
	if (low->data.id == high->data.id) {
		return;
	}

	while (l != nullptr && l->data.id != low->data.id) {
		prev = l;
		l = l->next;
	}

	while (r != nullptr && r->data.id != high->data.id) {
		prev2 = r;
		r = r->next;
	}

	if (l != nullptr && r != nullptr) {
		if (prev != nullptr) {
			prev->next = r;
		}
		else {
			list->head = r;
		}

		if (prev2 != nullptr) {
			prev2->next = l;
		}
		else {
			list->head = l;
		}
		auto temp = l->next;
		l->next = r->next;
		r->next = temp;
	}
	else {
		return;
	}
}