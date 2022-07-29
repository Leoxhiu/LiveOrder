#pragma once

using namespace std;

class PurchaseReportAction {
public:
	PurchaseReportAction(string date, string upperdate, int accountType);

private:
	void keepLaunch(string message, string date, string upperdate, int accountType);
	void initialization(string date, string upperdate, int accountType);
	void filterReport(string date, string upperdate, int accountType);
	void sortReport(string date, string update, int accountType);
};