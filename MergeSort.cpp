#include <iostream>
#include <ctime>
using namespace std;

template<typename T>
void mergeSort(T* array, size_t arraySize) {
	if (arraySize == 2  && *array > *(array + 1)) {
		// swap two elements
		*array += *(array + 1);
		*(array + 1) = *array - *(array + 1);
		*array -= *(array + 1);
	}
	if (arraySize > 2) {
		size_t firstSize = arraySize / 2;
		size_t secondSize = arraySize - arraySize / 2;

		// sort two sub-arrays
		mergeSort(array, firstSize);
		mergeSort(array + firstSize, secondSize);

		// merge two sub-arrays in one
		T* result = new T[arraySize];
		size_t i = 0, j = 0, k = 0;
		while (i < arraySize)
		{
			// choose smaller element from two sub-arrays
			*(result + i++) =
				(j < firstSize) && (k < secondSize) && *(array + j) < *(array + firstSize + k) ||
				!((j < firstSize) && (k < secondSize)) && (k == secondSize)
				?
				*(array + j++)
				:
				(j < firstSize) && (k < secondSize) && !(*(array + j) < *(array + firstSize + k)) ||
				!((j < firstSize) && (k < secondSize)) && !(k == secondSize)
				?
				*(array + firstSize + k++)
				:
				NULL;
		}
		for (size_t i = 0; i < arraySize; i++)
		{
		array[i] = result[i];
		}
		delete[] result;
	}
}

template<typename T>
void printArray(T* array, size_t arraySize) {
	for (size_t i = 0; i < arraySize; i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl;
}

int main() {
	// create array
	const size_t arraySize = 20;
	int* array = new int[arraySize];
	
	// fill array
	srand(time(0));
	for (size_t i = 0; i < arraySize; i++)
	{
		array[i] = rand() % 100;
	}

	// sort array
	printArray(array, arraySize);
	mergeSort(array, arraySize);
	printArray(array, arraySize);

	// delete array
	delete[] array;

	system("pause");
	return 0;
}