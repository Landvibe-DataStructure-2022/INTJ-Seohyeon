#include<iostream>
using namespace std;

struct Node {
	Node* next;
	Node* prev;
	int data;

	Node() {
		next = prev = nullptr;;
		data = 0;
	}
	Node(int d) {
		next = prev = nullptr;
		data = d;
		
	}
};

class Iterator {
private:
	Node* node;
public:
	Iterator() {
		node = nullptr;
	}
	Iterator(Node* n) {
		node = n;
	}
	Iterator* operator++() {
		node = node->next;
		return this;
	}
	friend class Sequence;
};

class Sequence {
private:
	Node* head;
	Node* tail;
	int size;
public:
	Sequence() {
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
		size = 0;
	}
	Node* begin() {
		return head->next;
	}
	Node* end() {
		return tail;
	}

	void insert(Iterator& p, int e) {
		Node* newNode = new Node(e);

		p.node->prev->next = newNode;
		newNode->prev = p.node->prev;

		newNode->next = p.node;
		p.node->prev = newNode;
		size++;
		
	}

	void print() {
		Node* curNode = head->next;
		int a = 0;
		int b = 0;
		int c = 0;

		while(curNode !=tail){
			//처음 앞에 두개만 더하는 방법을 모르겠다
			a = curNode->data;
			b = curNode->next->data;
			c = curNode->next->next->data;
			cout << a+b+c << " ";
			curNode = curNode->next;	
		}
		cout << "\n";
	}
};

int main() {
	

	int n = 0;
	cin >> n;

	while (n--) {
		Sequence s;
		Iterator p = Iterator(s.begin());
		int e = 0;
		cin >> e;
		while (e--) {
			int v = 0;
			cin >> v;
			s.insert(p, v);
		}
		s.print();
		

	}
	return 0;

}