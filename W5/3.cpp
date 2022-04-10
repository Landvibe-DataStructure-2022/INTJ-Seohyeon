#include <iostream>
#include <string>
using namespace std;

class Node {
private: 
	Node* next;
	Node* prev;
	int value;
public:
	Node() {
		next = nullptr;
		prev = nullptr;
		value = 0;
	}

	Node(int v) {
		next = nullptr;
		prev = nullptr;
		value = v;
	}
	friend class Iterator;
	friend class Sequence;
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

	Iterator* operator++(){
		node = node->next;
		return this;
	}

	Iterator* operator--() {
		node = node->prev;
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
		head = nullptr;
		tail = nullptr;
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
	void erase(Iterator& p) {
		if (size == 0) cout << "Empty\n";
		else{
			Node* deleteNode = p.node;
			p.node->prev->next = p.node->next;
			p.node->next->prev = p.node->prev;

			p.node = begin();//????
			size--;
			delete deleteNode;
		}
	}
	void print() {
		if (size == 0) cout << "Empty";
		else {
			Node* newNode = head->next;
			while (newNode != tail) {
				cout << newNode->value << " ";
				newNode = newNode->next;
			}
			cout << endl;
			

			
		}
	}

	void upper(int e) {
		Node* nd = head->next;
		if (size == 0)cout << "-1\n";
		else {
			for (int i = 0; i < size; i++) {
				if (e < nd->value)	cout << i << "\n";
				else nd = nd->next;

			}
		}

		
	}
};

int main() {
	int n;
	cin >> n;
	Sequence seq;
	Iterator pos;
	while (n--) {
		string s;
		cin >> s;

		if (s == "begin") {
			seq.begin();
		}
		else if (s == "end") {
			seq.end();
		}
		else if (s == "insert") {
			int v = 0;
			cin >> v;
			seq.insert(pos,v);
		}
		else if (s == "erase") {
			seq.erase(pos);
		}
		else if (s == "nextP") {
			++pos;
		}
		else if (s == "prevP") {
			--pos;
		}
		else if(s == "print") {
			seq.print();
		}
		else if (s == "upper") {
			int v = 0;
			cin >> v;
			seq.upper(v);
}

	}




	return 0;

}