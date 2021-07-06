#pragma once
#include "classes.h"

// accuracy (use in findIndex())
#define EPS 0.00001

template<class T>
class Container
{
private:
	size_t size;
	T* data;
public:
	Container();
	~Container();
	Container(const Container&) = delete;
	Container(Container&&) = delete;
	Container& operator= (const Container&) = delete;
	Container& operator= (Container&&) = delete;

	size_t getSize() const noexcept;

	T& operator[](unsigned int index) const throw();
	T insert(const T& value, size_t index) throw();
	T push(const T& value) throw();
	T push_back(const T& value) throw();
	T remove(unsigned int index) throw();
	void erase() noexcept;

	int findIndex(double time) const noexcept;
	void checkIndex(unsigned int index) const throw();
	T get(double time) const throw();
	T pop(double time) throw();
};

// container.cpp
template<class T>
Container<T>::Container() :size(0), data(nullptr) {}

template<class T>
Container<T>::~Container()
{
	delete[] data;
}

template<class T>
size_t Container<T>::getSize() const noexcept {
	return size;
}

template<class T>
T& Container<T>::operator[](unsigned int index) const throw()
{
	checkIndex(index);
	return data[index];
}

template<class T>
T Container<T>::insert(const T& value, size_t index) throw()
{
	checkIndex(index);

	T* newData = new T[size + 1];

	for (size_t before = 0; before < index; before++)
	{
		newData[before] = data[before];
	}

	newData[index] = value;

	for (size_t after = index; after < size; after++)
	{
		newData[after + 1] = data[after];
	}

	delete[] data;
	data = newData;
	++size;

	return value;
}

template<class T>
T Container<T>::push(const T& value) throw() { return insert(value, 0); }

template<class T>
T Container<T>::push_back(const T& value) throw() { return insert(value, size); }

template<class T>
T Container<T>::remove(unsigned int index) throw()
{
	checkIndex(index);

	T tmp = data[index];

	if (size == 1)
	{
		erase();
		return tmp;
	}

	T* newData = new T[size - 1];

	for (int before = 0; before < index; ++before)
		newData[before] = data[before];

	for (int after = index + 1; after < size; ++after)
		newData[after - 1] = data[after];

	delete[] data;
	data = newData;
	--size;

	return tmp;
}

template<class T>
void Container<T>::erase() noexcept
{
	delete[] data;

	data = nullptr;
	size = 0;
}

template<class T>
int Container<T>::findIndex(double time) const noexcept {
	for (size_t i = 0; i < size; i++)
	{
		// 0.3 equals 2.9999999 => (0.3 == 2.99999) => false, should return true
		if (abs(time - data[i].getTime()) < EPS) {
			return i;
		}
	}
	return -1;
}

template<class T>
void Container<T>::checkIndex(unsigned int index) const throw() {
	if (index < 0 || index > size)	throw out_of_range("Bad index");
}

template<class T>
T Container<T>::get(double time) const throw() {
	checkIndex(findIndex(time));
	return data[findIndex(time)];
}

template<class T>
T Container<T>::pop(double time) throw() {
	checkIndex(findIndex(time));
	return remove(findIndex(time));
}