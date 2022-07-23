#include <iostream>

#include "MonthlyPurchaseReport.h"

using namespace std;

MonthlyPurchaseReport::MonthlyPurchaseReport(int accountType) {

	Initialization();

}


void MonthlyPurchaseReport::Initialization() {

	cout << "============================" << endl;
	cout << "   Monthly Purchase Report  " << endl;
	cout << "============================" << endl;

	string desiredMonth;

	cout << "Desired month: ";
	cin >> desiredMonth;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');



}

void MonthlyPurchaseReport::keepLaunch() {


}