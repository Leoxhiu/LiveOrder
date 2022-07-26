#pragma once

using namespace std;

class OrderManagement
{
	public:
		OrderManagement(int accountType);

		void AdminOrderManagement(int accountType);

		void ExecutiveOrderManagement(int accountType);

	private:
		void keepLaunch(string message, int accountType);

		string getCurrentDate();
};

