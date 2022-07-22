#include "Screen.h"
#include "Homepage.h"
#include "Login.h"
#include <iostream>
#include <thread>
using namespace std;

Homepage::Homepage() {
    Initialise();
}

void Homepage::Initialise(){
    cout << "============================" << endl;
    cout << "    LiveOrder PO system     " << endl;
    cout << "============================\n" << endl;
    cout << "Welcome, " << endl <<
        endl <<
        "1. Login" << endl <<
        "2. Exit" << endl
        << endl;

    int option;
    cin >> option;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (option) {
        case 1: {
            Screen::clearScreen();
            Login login;
            break;
            }
        case 2: {
            Screen::clearScreen();
            exit(0);
        }
        default: {
            cout << "\n-----------------------------" << endl;
            cout << "    Invalid option!            " << endl;
            cout << "-----------------------------" << endl;
            this_thread::sleep_for(std::chrono::seconds(3));
            Screen::clearScreen();
            Homepage home;

        }

    }
}

