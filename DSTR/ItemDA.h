#pragma once

#include "Item.h"
#include "LinkedList.h"

using namespace std;

class ItemDA
{
	private:
		const string filepath = "item.txt"; // relative database

	public:

		ItemDA() {};

		// public functions here


	private:
		// private functions (connect to database)
		void importFrom(string filepath, LinkedList<Item>* items);
};

