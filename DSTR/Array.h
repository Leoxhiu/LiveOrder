#pragma once
#include <iostream>

using namespace std;

template <class T> class Array
{
	private:
		int max; // maximum length of array
		int length; // current length
		T *arr;

	public:
		int getLength() const;
		void add(const T& item);
		T& get(int index);

	public:
		T* linearSearch(int i);
		Array(int length);
		~Array();
		
	
};

template<class T>
int Array<T>::getLength() const
{
	return this->length;
}


template<class T>
void Array<T>::add(const T &item)
{
	if (this->length < this->max)
	{
		this->arr[this->length++] = item;
	}
	else
	{
		cout << "Array is full.";
	}
		
}


template<class T>
T& Array<T>::get(int index)
{
	if(index < 0 || index >= this->length)
	{
		cout << "Bad index";
	}
	
	return this->arr[index];
}


template<class T>
inline T* Array<T>::linearSearch(int i)
{
	if (i >= this->length)
	{
		return NULL;
	}
	if (i == 0) {
		return &this->arr[0];
	}
	else {
		while (i < this->length) {
			t++;
		}
		return &(this->arr[i]);
	}
}

template<class T>
Array<T>::Array(int length)
{
	this->cap = length;
	this->length = 0;
	this->arr = new T[this->max];
}

template<class T>
Array<T>::~Array()
{
	delete[] this->arr;
}