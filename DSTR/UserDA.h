#pragma once

#include "LinkedList.h"
#include "User.h"

using namespace std;

class UserDA
{
public:

	UserDA() {};
	enum class validate {NotFound, IncorrectPassword, Successful};
	enum class find { NotFound, Found };

	LinkedList<User>* importUser(); // Import user data to LinkedList
	LinkedList<User>* registerUser(User user); // Put in LinkedList then store into database

	void displayList(LinkedList<User>* users); // Display LinkedList as table form

	User getUserByEmail(string email, LinkedList<User>* users); // Get full details of user by email


	validate userValidation(string email, string password, LinkedList<User>* users); // For login validation
	find findUserByEmail(string email, LinkedList<User>* users); // To check unique email
	


private:
	void importFrom(string filepath, LinkedList<User>* users); // Import from database
	void exportTo(string filepath, LinkedList<User>* users); // Export to database
};