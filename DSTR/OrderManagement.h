#pragma once

using namespace std;

class OrderManagement
{
	public:
		OrderManagement(int accountType);

		void adminInterface(int accountType);
		void executiveInterface(int accountType);

	private:
		void keepLaunch(string message, int accountType);

		string getCurrentDate();
};

