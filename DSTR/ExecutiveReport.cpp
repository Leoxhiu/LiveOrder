#include <iostream>
#include <thread>

#include "User.h"
#include "UserDA.h"
#include "ReportGeneration.h"
#include "ExecutiveReport.h"
#include "Screen.h"

using namespace std;

ExecutiveReport::ExecutiveReport(int accountType) {
	
	UserDA userDA;

	cout << "============================" << endl;
	cout << " Executive Report Generation " << endl;
	cout << "============================" << endl << endl;
	userDA.filterUserByRole(1);
	userDA.displayList();

	cout << "What are you going to do next?" << endl <<
		endl <<
		"1. Sort Executive by ID" << endl <<
		endl <<
		"2. << Back" << endl
		<< endl;

	int option;
	cin >> option;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (option) {
		case 1: {
			int opt;
			int cont = 0;
			cout << "1. Ascending order" << endl <<
					"2. Descending Order" << endl;
			do {
				opt = 0;
				cin >> opt;
				switch (opt) {
				case 1:{
					userDA.sortUserByID(UserDA::sortMethod::ascending);

					cout << "Enter 1 to continue: ";
					cin >> cont;
					if (cont == 1) {
						Screen::clearScreen();
						ExecutiveReport executiveReport(accountType);
						break;
					}
					else {
						cin.ignore();
					}
				}
				case 2: {
					userDA.sortUserByID(UserDA::sortMethod::descending);

					cout << "Enter 1 to continue: ";
					cin >> cont;
					if (cont == 1) {
						Screen::clearScreen();
						SupplierReport supplierReport(accountType);
						break;
					}
					else {
						cin.ignore();
					}
				}
				  defaukt: {
					  cin.ignore();
					  cout << "\n-----------------------------" << endl;
					  cout << "        Invalid input!       " << endl;
					  cout << "-----------------------------" << endl;
					  break;
				}
				}
			} while (opt != 1 && opt != 2);
		}
		case 2: {
			Screen::clearScreen();
			ReportGeneration ReportGeneration(accountType);
			break;
		}
		default: {
			cout << "\n-----------------------------" << endl;
			cout << "        Invalid input!       " << endl;
			cout << "-----------------------------" << endl;
			this_thread::sleep_for(std::chrono::seconds(3));
			Screen::clearScreen();
			ExecutiveReport ExecutiveReport(accountType);
		}

		}
}

