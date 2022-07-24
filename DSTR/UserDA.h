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
		LinkedList<User>* getUserData(); // Return all users data
		void addUser(User user); // Add in linked list

		void displayList(); // Display linked list as table form

		validate userValidation(string email, string password); // For login validation

		

		find findUserByID(int id); // Find if ID exists by using binary search
		User getUserByID(int id); // Use linear search to get the user by ID

		find findUserByEmail(string email); // Find if email exists
		User getUserByEmail(string email); // Use linear search to get the user by email
		
	


		void importUser(); // Import user data to linked list storage

	private:

		// private functions here
		LinkedList<User>* importFromDatabase(); // Import user from database into linked list
		void exportToDatabase(); // Export user to database from linked list
};