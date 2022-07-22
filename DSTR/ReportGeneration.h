#pragma once

using namespace std;

class ReportGeneration
{
	public:
		ReportGeneration(int accountType);  // 0 = admin, 1 = executive

		void adminInterface(int accountType);
		void executiveInterface(int accountType);

};

