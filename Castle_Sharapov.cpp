#include <iostream>
#include <cmath>
using namespace std;

/*
Task
There is a castle in the shape of a triangle, with three towers and three walls.
The goal is to place the people so that the number of people on each side
matched the given numbers side1, side2, side3 also given total number of people.
*/

int MIN(int a, int b) {
	return (a < b) ? a : b;
}
int MAX(int a, int b) {
	return (a > b) ? a : b;
}
int Fact(int a) {
	if (a == 0) return 1;
	return a*Fact(a - 1);
}
int BinomC(int all, int a1, int a2, int a3, int a4, int a5, int a6) {
	return Fact(all) / (Fact(a1) * Fact(a2) * Fact(a3) * Fact(a4) * Fact(a5) * Fact(a6));
}

int main() {

	int side1, side2, side3, all;
	int count = 0;
	
	cout << "Input Side1, Side2, Side3, All." << endl;

	cin >> side1;
	cin >> side2;
	cin >> side3;
	cin >> all;

	if (side1 < 0 || side2 < 0 || side3 < 0 || all<0 || all > side1 + side2 + side3 || 2 * all < side1 + side2 + side3) {
		cout << "Wrong arguments.." << endl;
		goto end;
	}

	int a, b, c, x, y, z;
	int a1, b1, c1, x1, y1, z1;

	/*
	a + y + b = side1;
	b + z + c = side2;
	c + x + a = side3;
	x + c + z = all - side1;
	y + a + x = all - side2;
	z + b + y = all - side3;
	a + b + c = side1 + side2 + side3 - all;
	x + y + z = 2 * all - (side1 + side2 + side3);
	*/
	
	// side1 >= y >= all - (side2 + side3)
	// side2 >= z >= all - (side1 + side3)
	// all - side3 >= y+z >= 2*all - (side1 + side2 + 2*side3)

	y = all - (side2 + side3), z = all - (side1 + side3);

	b = all - side3 - y - z;
	x = 2 * all - (side1 + side2 + side3) - y - z;
	a = z + (side1 + side3 - all);
	c = y + (side2 + side3 - all);

	if (a < 0 || b < 0 || c < 0 || x < 0 || y < 0 || z < 0) {
		cout << "no result.." << endl;
		goto end;
	}

	//for (int y1 = all - (side2 + side3); y1 <= side1; y1++) {
	//	for (int z1 = MAX(all - (side1 + side3), 2 * all - (side1 + side2 + 2 * side3) - y1); z1 <= MIN(all - side3 - y1, side2); z1++) {
	//		b1 = all - side3 - y1 - z1;
	//		x1 = 2 * all - (side1 + side2 + side3) - y1 - z1;
	//		a1 = z1 + (side1 + side3 - all);
	//		c1 = y1 + (side2 + side3 - all);

	//		count+= BinomC(all,a1,b1,c1,x1,y1,z1);
	//	}
	//}

	cout << "		"<<a << endl;
	cout << "	" << x << "		" << y << endl;
	cout << c << "		" << z << "		" << b << endl << endl;
	cout << count << endl;

	end:
	system("pause");
	return 0;
}
