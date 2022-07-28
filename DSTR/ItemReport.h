#pragma once

using namespace std;

class ItemReport
{
	public:
		ItemReport(int accountType);

	private:
		void initialization(int accountType);
		void filterItem(int accountType);
		void sortItem(int accountType);
		void keepLaunchSort(string message, int accountType);
		void keepLaunchFilter(string message, int accountType);
};

