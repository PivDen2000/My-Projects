#include <iostream>
#include "classes.h"
#include "container.h"
using namespace std;

// container size
const int N = 4;

int main() {

	try {

		// create elements
		const A a(0.0, 0, 0);
		const B b(0.1, 1, 1, 1);
		const C c(0.2, 2, 2, 2);
		const D d(0.3, 3, 3, 3, 3);

		// push into container
		Container<A> container;
		container.push_back(a);
		container.push_back(b);
		container.push_back(c);
		container.push_back(d);

		// deserialize elements by index
		for (size_t i = 0; i < N; i++)
		{
			container[i].deserialize();
		}
		
		// deserialize elements by time
		for (double time = 0.0; time < 0.1*N; time+=0.1)
		{
			container.get(time).deserialize();
		}

		// pop elements by time
		for (double time = 0.0; time < 0.1 * N; time += 0.1)
		{
			container.pop(time).whoAmI();
		}
		cout << container.getSize() << endl;

	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	system("pause");
	return 0;
}