#pragma once

using namespace std;

template <class T> class DynamicArray {

private:
	int max_length;
	int current_length;
	void extend();

public:
	T* data;
	DynamicArray();
	~DynamicArray();
	T* getData(int index);
	void append(T newData);
	int getLength();

};

const int increment = 10;

template <class T>
void DynamicArray<T>::extend() { //increase the maximum size of dyanmic array
	T* newData = new T[max_length + increment];
	for (int i = 0; i < max_length; i++) {
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
	max_length += increment;
}

template <class T>
DynamicArray<T>::DynamicArray() {
	data = new T[increment];
	current_length = 0;
	max_length = increment;
}

template <class T>
DynamicArray<T>::~DynamicArray() {
	delete[] data;
}

template <class T>
void DynamicArray<T>::append(T newData) { //add new element into dynamic array
	if (current_length == max_length) extend();
	data[current_length] = newData;
	current_length++;
}

template <class T>
inline int DynamicArray<T>::getLength() { 
	return current_length;
}

template <class T>
T* DynamicArray<T>::getData(int index) {
	return &data[index];
}