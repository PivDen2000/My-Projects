#pragma once
#include "classes.h"

class Container
{
private:
	size_t size;
	shared_ptr<A>* data;
public:
	Container() noexcept;
	Container(shared_ptr<A>*, size_t) noexcept;
	Container(const Container&) noexcept;
	Container(Container&&) noexcept;
	~Container() noexcept;

	size_t getSize() const noexcept;
	shared_ptr<A>* getData() const noexcept;
	shared_ptr<A> operator[](unsigned int index) const noexcept(false);

	template<class T>
	void insert(shared_ptr<T> ptr, size_t index) noexcept(false);
	template<class T>
	void push(shared_ptr<T> ptr) noexcept(false);
	template<class T>
	void push_back(shared_ptr<T> ptr) noexcept(false);
	
	void erase(int size = 0) noexcept;
	void remove(unsigned int index) noexcept(false);

	int binarySearch(double time) const noexcept;
	int findIndex(double time, bool (*op)(double, double)) const noexcept;
	
	void checkIndex(unsigned int index) const noexcept(false);
	
	template<class T>
	shared_ptr<T> get(double time) const noexcept(false);
	void pop(double time) noexcept(false);
	
	bool empty()const noexcept;

	Container getSegment(double startTime, double endTime) const noexcept(false);
};

// container.cpp

Container::Container() noexcept :size(0), data(nullptr) {}

Container::Container(shared_ptr<A>* otherData, size_t otherSize) noexcept {
	size = otherSize;
	data = otherData;
}

Container::Container(const Container& other) noexcept : Container(other.data, other.size) {}

Container::Container(Container&& other) noexcept : Container(other.data, other.size) {}

Container::~Container() noexcept {}

size_t Container::getSize() const noexcept {
	return size;
}

shared_ptr<A>* Container::getData() const noexcept {
	return data;
}

shared_ptr<A> Container::operator[](unsigned int index) const noexcept(false)
{
	checkIndex(index);
	return data[index];
}

template<class T>
void Container::insert(shared_ptr<T> value, size_t index) noexcept(false)
{
	checkIndex(index);

	shared_ptr<A>* newData = new shared_ptr<A>[size + 1];

	for (size_t before = 0; before < index; before++)
		newData[before] = data[before];

	newData[index] = value;

	for (size_t after = index; after < size; after++)
		newData[after + 1] = data[after];

	erase(size);
	data = newData;
	++size;
}

template<class T>
void Container::push(shared_ptr<T> value) noexcept(false) { insert(value, 0); }

template<class T>
void Container::push_back(shared_ptr<T> value) noexcept(false) { insert(value, size); }

void Container::erase(int size) noexcept
{
	if (empty()) return;
	for (size_t i = 0; i < this->size; i++)
	{
		data[i].reset();
	}
	data->reset();
	this->size = size;
}

void Container::remove(unsigned int index) noexcept(false)
{
	checkIndex(index);

	if (size == 1) { erase(); return; }
	
	shared_ptr<A>* newData = new shared_ptr<A>[size - 1];

	for (size_t before = 0; before < index; ++before)
		newData[before] = data[before];

	for (size_t after = index + 1; after < size; ++after)
		newData[after - 1] = data[after];

	erase(size);
	data = newData;
	--size;
}

int Container::binarySearch(double time) const noexcept {
	int l = 0;
	int r = size - 1;
	int mid = -1;

	while (l <= r)
	{
		mid = r + (l - r) / 2;
		if (data[mid]->getTime() < time) {
			l = mid + 1;
		} else if(data[mid]->getTime() > time){
			r = mid - 1;
		} else return mid;
	}
	return mid;
}

int Container::findIndex(double time, bool (*op)(double l, double r)) const noexcept {

	int index = binarySearch(time);
	if (index == -1) return index;
	if (op(time, data[index]->getTime())) return index;

	if (op(0, 1) && time < data[size - 1]->getTime()) return index + 1;
	if (op(1, 0) && time > data[0]->getTime()) return index - 1;

	if (op(0, 1) && time > data[size-1]->getTime() ||
		op(1, 0) && time < data[0]->getTime()) return -1;
	
	return index;
}

void Container::checkIndex(unsigned int index) const noexcept(false) {
	if (index < 0 || index > size)	throw out_of_range("Bad index");
}

template<class T>
shared_ptr<T> Container::get(double time) const noexcept(false) {
	int index = findIndex(time, [](double l, double r) {return l == r; });
	checkIndex(index);
	return dynamic_pointer_cast<T>(data[index]);
}

void Container::pop(double time) noexcept(false) {
	remove(findIndex(time, [](double l,double r) {return l == r; }));
}

bool Container::empty() const noexcept {
	return !size;
}

Container Container::getSegment(double startTime, double endTime) const noexcept(false)
{
	if (startTime > endTime) throw out_of_range("Bad arguments in getSegment.");

	int startIndex = findIndex(startTime, [](double l, double r) {return l <= r; });
	int endIndex = findIndex(endTime, [](double l, double r) {return l >= r; });

	if (startIndex == -1 || endIndex == -1) throw out_of_range("No elements in segment");

	shared_ptr<A>* result = new shared_ptr<A>[endIndex - startIndex + 1];

	for (int i = startIndex; i <= endIndex; i++)
	{
		result[i - startIndex] = data[i];
	}

	Container res(result, endIndex - startIndex + 1);

	return move(res);
}
