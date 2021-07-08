#include <iostream>
#include <cmath>
#include "windows.h"
using namespace std;

/*
Change color of console on each output of "Hello World!!!"
*/

int main() {

	while (true) {
		for (int i = 97; i < 103; i++) {
			for (int j = 49; j < 58; j++) {
				char arr[9] = { 'c' , 'o' , 'l' , 'o' , 'r' , ' ' , j , i , '\0' };
				cout << "Hello World!!!	";
				system(arr);
				Sleep(150);
			}
		}
	}

	cout << (int)'1'<<' '<<(int)'a' << endl;

	system("pause");
	return 0;
}