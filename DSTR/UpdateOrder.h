#pragma once
class UpdateOrder {

public:
	UpdateOrder(int accountType);

	void AdminUpdateOrder(int accountType);

	void ExecutiveUpdateOrder(int accountType);

private:

	void keepLaunch(string message, int accountType);
};