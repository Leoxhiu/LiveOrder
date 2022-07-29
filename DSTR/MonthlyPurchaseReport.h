#pragma once

using namespace std;

class MonthlyPurchaseReport
{
	
	public:
		MonthlyPurchaseReport(int accountType);
		

	private:
		void keepLaunch(string message, int accountType);
		void orderReportAction(string message, int accountType, string date, string upperdate);
		void initialization(int accountType);
		string getCurrentDate();
};

