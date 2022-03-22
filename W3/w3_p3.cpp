#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;

	Node() {
		next = NULL;
		data = 0;
	}
};

Node* top = NULL;

void empty() {
	if (top == NULL) cout << "1";
	else cout << "0";
	cout << endl;
}

void Top() {
	if (top != NULL) {
		cout << top->data;
	}
	else {
		cout << "-1";
	}
	cout << endl;
}

void push(int data) {
	Node* node = new Node();
	node->data = data;
	node->next = top;
	top = node;
}



void pop() {
	if (top == NULL) {
		cout << "-1" << endl;
	}
	else {
		cout << top->data << endl;
		top = top->next;
	}
}


int main() {

	int n;
	cin >> n;

	while (n--) {
		string s;
		cin >> s;

		if (s == "empty") empty();
		else if (s == "top")  Top();
		else if (s == "push") {
			int x = 0;
			cin >> x;
			push(x);
		}
		else if (s == "pop") pop();
	}
	return 0;

}