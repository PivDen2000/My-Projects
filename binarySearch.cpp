#include<iostream>
using namespace std;

int binarySearch(double el, double arr[], int min, int max) {
	int mid = -1;
	while (min <= max)
	{
		mid = min + (max - min) / 2;
		if (arr[mid] < el) {
			min = mid + 1;
		}
		else if (arr[mid] > el) {
			max = mid - 1;
		}
		else return mid;
	}
	return mid;
}

int main() {
	double arr[10] = { 0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9 };
	int index;

	index = binarySearch(0.05, arr, 0, 9);
	cout << ((index != -1) ? arr[index] : -1) << endl;

	index = binarySearch(0.55, arr, 0, 9);
	cout << ((index != -1) ? arr[index] : -1) << endl;



	system("pause");
	return 0;
}