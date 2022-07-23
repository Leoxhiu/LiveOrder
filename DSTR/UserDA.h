#pragma once

#include "LinkedList.h"
#include "User.h"

using namespace std;

class UserDA
{
	private:
		const string filepath = "user.txt"; // relative database

	public:
		UserDA() {};
		enum class validate {NotFound, IncorrectPassword, Successful};
		enum class find { NotFound, Found };


		// public functions here

		LinkedList<User>* importUser(); // Import user data to linked list
		LinkedList<User>* registerUser(User user); // Put in linked list then store into database

		void displayList(LinkedList<User>* users); // Display linked list as table form

		User getUserByEmail(string email, LinkedList<User>* users); // Get full details of user by email


		validate userValidation(string email, string password, LinkedList<User>* users); // For login validation
		find findUserByEmail(string email, LinkedList<User>* users); // To check unique email
	

	private:

		// private functions (connect to database)

		void importFrom(LinkedList<User>* users); // Import user from database
		void exportTo(LinkedList<User>* users); // Export user to database
};