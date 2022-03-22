#include <iostream>
using namespace std;
int t;

class Node {
public:
	int data;
	Node* next;
	Node() {
		data = 0;
		next = NULL;
	}
};

class Stack {
public:
	Node* head;

	int s_size;


	Stack() {
		head = new Node();
		s_size = 0;
	}



	void empty() {
		if (s_size == 0) cout << 1 << endl;
		else cout << 0 << endl;
	}

	int top() {
		if (s_size == 0) return -1;
		else return head->data;
	}

	void push(int x) {
		if (s_size >= 99) cout << "FULL" << endl;
		else {
			Node* new_node = new Node();
			new_node->data = x;
			new_node->next = head;
			head = new_node;
			s_size++;
		}

	}

	void pop() {
		if (s_size == 0) cout << -1 << endl;
		else {
			head = head->next;
			s_size--;
		}
	}


};

int main() {

	cin >> t;

	Stack st;
	string print;

	while (t--) {
		string s;
		cin >> s;

		for (int i = 0; i < s.size(); i++) {
			if ('0' <= s[i] && s[i] <= '9') {
				st.push(s[i] - '0');
			}
			else if (s[i] == '+') {
				int n2 = st.top();
				st.pop();
				int n1 = st.top();
				st.pop();
				st.push(n1 + n2);
			}

			else if (s[i] == '-') {
				int n2 = st.top();
				st.pop();
				int n1 = st.top();
				st.pop();
				st.push(n1 - n2);
			}

			else if (s[i] == '*') {
				int n2 = st.top();
				st.pop();
				int n1 = st.top();
				st.pop();
				st.push(n1 * n2);
			}




		}

		cout << st.top() % 10 << endl;

	}
	return 0;
}

