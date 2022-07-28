#pragma once

using namespace std;

class YearlyPurchaseReport {

public:
	YearlyPurchaseReport(int accountType);

private:
	void initialization(int accountType);
	void keepLaunch(string message, int accountType);
	void orderReportAction(string message, int accountType, string date, string upperdate);
	string getCurrentDate();

};