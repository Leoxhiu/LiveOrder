#pragma once
#include "UserDA.h"

using namespace std;

class ExecutiveRegistration
{
	public:
		ExecutiveRegistration();

		bool emailExist(string email, UserDA userDA);  // check email if exist in database
		bool inputValidation(string email, string password, string name, string phoneNumber);

		void keepLaunch(string message);

		// Regex
		bool emailValidation(const string& email);
		bool nameValidation(const string& name); // No number and no space in name
		bool phoneNumberValidation(const string& phoneNumber); // only for mobile
};

