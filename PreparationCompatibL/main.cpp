#include "container.h"
using namespace std;

// container size
const int N = 4;

void delimiter() {
	cout << "=================================================" << endl;
}

int main() {

	try {
		// create elements
		shared_ptr<A> a = make_shared<A>(0.0, 0, 0);
		shared_ptr<B> b = make_shared<B>(0.1, 1, 1, 1);
		shared_ptr<C> c = make_shared<C>(0.2, 2, 2, 2);
		shared_ptr<D> d = make_shared<D>(0.3, 3, 3, 3, 3);
		
		delimiter();
		cout << "Deserialize original objects." << endl;
		delimiter();
		a->deserialize();
		b->deserialize();
		c->deserialize();
		d->deserialize();
		delimiter();

		// push into container
		Container container;
		container.push_back(a);
		container.push_back(b);
		container.push_back(c);
		container.push_back(d);

		cout << "Deserialize by index in container." << endl;
		delimiter();
		for (size_t i = 0; i < N; i++)
		{
			container[i]->deserialize();
		}
		delimiter();

		cout << "Ask each element about class." << endl;
		delimiter();
		for (size_t i = 0; i < N; i++)
		{
			container[i]->whoAmI(); // A B C D
		}
		delimiter();

		cout << "Downcast elements." << endl;
		cout << "Deserialize elements." << endl;
		delimiter();
		container.get<A>(container[0]->getTime())->deserialize();
		container.get<B>(container[1]->getTime())->deserialize();
		container.get<C>(container[2]->getTime())->deserialize();
		container.get<D>(container[3]->getTime())->deserialize();
		delimiter();

		cout << "Find elements by getSegment." << endl;
		Container segment(container.getSegment(0.03, 0.28));
		
		cout << "Ask each element about class." << endl;
		delimiter();
		for (size_t i = 0; i < segment.getSize(); i++)
		{
			segment[i]->whoAmI(); // B C
		}
		delimiter();

		cout << "Downcast and deserialize elements." << endl;
		delimiter();
		container.get<B>(segment[0]->getTime())->deserialize();
		container.get<C>(segment[1]->getTime())->deserialize();
		delimiter();

		// erase segment
		segment.erase();

		// pop elements by time
		for (size_t i = 0; i < N; i++)
		{
			container.pop(container[0]->getTime());
		}

		cout << "Clear container and check size" << endl;
		delimiter();
		cout << container.getSize() << endl;
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	system("pause");
	return 0;
}