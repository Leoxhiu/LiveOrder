#include <iostream>
#include "YearlyPurchaseReport.h"

using namespace std;

YearlyPurchaseReport::YearlyPurchaseReport(int accountType) {

	Initialization();

}

void YearlyPurchaseReport::Initialization() {

	cout << "============================" << endl;
	cout << "   Yearly Purchase Report  " << endl;
	cout << "============================" << endl;

	string desiredYear;

	cout << "Desired year: ";
	cin >> desiredYear;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');



}

void YearlyPurchaseReport::keepLaunch() {


}