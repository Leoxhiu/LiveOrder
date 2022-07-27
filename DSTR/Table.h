#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

//print element into tabular format
template<typename T> void printElement(T t, const int& width)
{
    const char separator = ' ';

    cout << left << setw(width) << setfill(separator) << t;
}