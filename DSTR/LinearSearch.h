#pragma once

using namespace std;

// linear search template function
// arr: array
// n: size of array
// x: value to search
// the function returns the index of x if it is present in arr
// otherwise it returns -1

template <class T>
T LinearSearch(T arr[], int length, T x) {

	for (int i = 0; i < n; ++i) {

		if (arr[i] == x)
			return i;

	}

	return false;

}
