#include<iostream>
using namespace std;

struct Node {
	int data = 0;
	Node* next = nullptr;
};

void fill(Node* node) {
	int i = 0;
	while (node)
	{
		node->data = i++;
		node = node->next;
	}
}

void print(Node* node) {
	while (node)
	{
		cout << node->data << ' ';
		node = node->next;
	}
	cout << endl;
}

void reverse(Node*& node) {
	// no nodes or one node
	if (!node || !node->next) return;
	
	// two nodes
	if (!node->next->next) {
		node->next->next = node;
		node = node->next;
		node->next->next = nullptr;
		return;
	}

	Node* n0 = node;
	Node* n1 = node->next;
	Node* n2 = node->next->next;

	while (n2)
	{
		n1->next = n0;

		n0 = n1;
		n1 = n2;
		n2 = n2->next;
	}
	n1->next = n0;
	
	node->next = nullptr;
	node = n1;
}

int main() {
	// allocate memory
	const int N = 10;
	Node** nodes = new Node*[N];

	// create nodes
	for (size_t i = 0; i < N; i++)
	{
		nodes[i] = new Node;
	}

	// create connections 0 -> 1 -> ... -> 9
	Node* head = nodes[0];
	for (size_t i = 0; i < N-1; i++)
	{
		nodes[i]->next = nodes[i + 1];
	}

	fill(head);

	print(head);
	
	reverse(head);
	
	print(head);

	// delete memory
	for (size_t i = 0; i < N; i++)
	{
		delete nodes[i];
	}
	delete[] nodes;

	system("pause");
	return 0;
}