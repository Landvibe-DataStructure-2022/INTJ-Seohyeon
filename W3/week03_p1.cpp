//#include <iostream>
//
//using namespace std;
////empty
////top
////push X
////pop
//
//int stack[11];
//int s_size;
//
//void empty() {
//	if (s_size == 0) cout << 1 << "\n";
//	else cout << 0 << "\n";
//}
//
//
//void top() {
//	cout << stack[s_size - 1];//top�� ���� ���
//	if(s_size == 0) cout << -1 << "\n"; 
//}
//
//void push(int data) {
//	stack[s_size + 1] = data;
//	if (s_size > 10) cout << "full";
//}
//
//void pop() {
//	cout << stack[s_size - 1];
//	s_size -= 1;
//}
//
//int main() {
//
//	int t = 0;
//	int n = 0;
//	cin >> t >> n;
//
//	while (t--) {
//		string cmd;//�Է¹��� ��ɾ�
//		cin >> cmd;
//	
//		int x;// cmd�� ���� x(data)
//		
//		//cmd�� ���� if������ �б� ó��
//		if (cmd == "empty") {
//			cout << empty() << "\n";
//		}
//		else if (cmd == "top") {
//			cout<<top();
//		}
//		else if (cmd == "push") {
//			cin >> x;
//			push(x);
//		}
//		else if (cmd == "pop") {
//			cout << pop() << "\n";
//		}
//		e
//	}
//		
//		
//		
//		
//	return 0;
//}

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
}