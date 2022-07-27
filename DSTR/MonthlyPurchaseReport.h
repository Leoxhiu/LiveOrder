#pragma once

using namespace std;

class MonthlyPurchaseReport
{
	
	public:
		MonthlyPurchaseReport(int accountType);
		

	private:
		void keepLaunch(string message, int accountType);
		void OrderReportAction(string message, int accountType, string date, string upperdate);
		void Initialization(int accountType);
		string getCurrentDate();
};

