#pragma once
#include <iostream>

using namespace std;

class MainMenu
{
public:
	MainMenu(int accountType); // 0 = admin, 1 = executive
	
	void adminInterface(int accountType);
	void executiveInterface(int accountType);
};

