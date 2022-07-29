#pragma once
class UpdateOrder {

public:
	UpdateOrder(int accountType);

	void adminInterface(int accountType);
	void executiveInterface(int accountType);

private:

	void keepLaunch(string message, int accountType);
};