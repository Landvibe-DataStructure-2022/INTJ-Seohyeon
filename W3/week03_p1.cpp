#include <iostream>

using namespace std;

int stack[10];
int s_size;
int t = 0;
int n = 0;

void empty() {
	if (s_size == 0) cout << 1 << endl;
	else cout << 0 << endl;

}

void top() {
	
	if (s_size == 0) cout << "-1" << endl;
	else cout << stack[s_size - 1] << endl;
}

void push(int x) {
	if (s_size == t) cout << "FULL" << endl;
	else {
		stack[s_size] = x;
		s_size++;
	}
}

void pop() {
	if (s_size == 0) { cout << 0 << endl; }
	else cout << stack[s_size - 1] << endl;
	s_size -= 1;
}

int main() {
	
	cin >> t >> n;

	int x;


	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "empty") {
			empty();
		}
		else if (cmd == "top") {
			top();
		}
		else if (cmd == "push") {
			cin >> x;
			push(x);
		}
		else if (cmd == "pop") {
			pop();
		}
	}
	return 0;
}
