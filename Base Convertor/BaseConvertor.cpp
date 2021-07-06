#include <iostream>
#include <cmath>
#include <string>
#include <typeinfo>
using namespace std;

#define EPS 10 //after dot digits

string convert(string input = "", unsigned int from = 10, unsigned int to = 10) {

	if (from < 2 || to < 2) throw exception("Wrong base");
	if (input == "") { input = "0"; return "0"; };

	string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	string result = "";

	//check correctness
	bool sing = false; // 0 mean +, 1 mean -
	bool dotFlag = false;

	if (alphabet.substr(0, from).find(input[0]) == -1 &&
		input[0] != '-' &&
		input[0] != '.')
	{
		throw exception("Wrong first digit");
	}

	if (input[0] == '-') {
		sing = true;
	}

	if (input[0] == '.') {
		dotFlag = true;
	}

	for (size_t i = 1; i < input.size(); i++)
	{
		if (input[i] == '.') {
			if (dotFlag)	throw exception("Wrong digit (too more dots)");
			dotFlag = true;
		}
		if (input[i] != '.' && alphabet.substr(0, from).find(input[i]) == -1) throw exception("Wrong digit (not from base)");
	}

	//check calculation needness
	if (from == to) return input;

	//parse to Integer and Fractional parts
	string integerPart = "";
	string fractionalPart = "";

	if (dotFlag) {
		integerPart = input.substr(sing, input.find('.') - sing);
		fractionalPart = input.substr(input.find('.') + 1);
	}
	else
	{
		integerPart = input.substr(sing);
	}

	//convert integer part number from current base to decimal
	int* integerPartInt = new int[integerPart.size()];
	for (int i = 0; i < integerPart.size(); i++)
	{
		integerPartInt[i] = alphabet.find(integerPart[i]);
	}
	long long int integerPartDec = 0;
	for (int i = 0; i < integerPart.size(); i++)
	{
		integerPartDec += integerPartInt[i] * pow(from, integerPart.size() - (i + 1));
	}
	delete[] integerPartInt;

	//convert integer part number from decimal base to new
	string newIntegerPart = "";
	long long int T = integerPartDec;
	int R = 0;
	while (T > 0) {
		R = T % to;
		T /= to;
		newIntegerPart = alphabet[R] + newIntegerPart;
	}
	newIntegerPart = (newIntegerPart == "") ? "0" : newIntegerPart;

	if (fractionalPart != "") {
		//convert fractional part number from current base to decimal
		double* fractionalPartInt = new double[fractionalPart.size()];
		for (int i = 0; i < fractionalPart.size(); i++)
		{
			fractionalPartInt[i] = alphabet.find(fractionalPart[i]);
		}
		long double fractionalPartDec = 0;
		for (int i = 0; i < fractionalPart.size(); i++)
		{
			fractionalPartDec += fractionalPartInt[i] / pow(from, (i + 1));
		}
		delete[] fractionalPartInt;

		//convert integer part number from decimal base to new
		string newFractionalPart = "";
		long double V = fractionalPartDec;
		unsigned int P = to;
		int d = 0;
		int digitsCount = 0;
		while (digitsCount < EPS) {
			d = floor(V * P);
			V = V * P - d;
			newFractionalPart += alphabet[d];
			digitsCount++;
		}

		result = (sing ? "-" : "") + newIntegerPart + (dotFlag ? "." : "") + newFractionalPart;
	}
	else {
		result = (sing ? "-" : "") + newIntegerPart + (dotFlag ? "." : "");
	}

	return result;
}

void printConverting(string input, int from, int to) {
	cout << input << "_" << from << " -> " << convert(input, from, to) << '_' + to_string(to) << endl;
}

int main() {

	try
	{
		int* ptr = new int;
		string ptrAdress = convert(to_string((int)ptr), 10, 16);
		while (ptrAdress.size() != 8) {
			ptrAdress = '0' + ptrAdress;
		}
		cout << ptr << ' ' << ptrAdress << endl;
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	system("pause");
	return 0;
}
