#pragma once

using namespace std;

class PurchaseReportAction {
public:
	PurchaseReportAction(string date, int accountType);

private:
	void keepLaunch(string message, string date, int accountType);
	void Initialization(string date, int accountType);
	void filterReport(string date, int accountType);
	void sortReport(string date, int accountType);
};