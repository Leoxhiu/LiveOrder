#pragma once

using namespace std;

class YearlyPurchaseReport {

public:
	YearlyPurchaseReport(int accountType);

private:
	void Initialization(int accountType);
	void keepLaunch(string message, int accountType);
	void OrderReportAction(string message, int accountType, string date);
	string getCurrentDate();

};