#include <iostream>
#include <string>
using namespace std;

class Node {
private:
	int data;
	Node* prev;
	Node* next;

public:
	Node() {
		data = 0;
		prev = nullptr;
		next = nullptr;
	}

	Node(int d) {
		data = d;
		prev = nullptr;
		next = nullptr;
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
	Iterator* operator++() {
		this->node = this->node->next;//오류나서 this붙임
		return this;
		}
	Iterator* operator--() {
		node = node->next;
		return this;
	}
	friend class Sequence;
}; 

class Sequence {
public:
	Sequence();
	Node* begin();
	Node* end();
	void insert(Iterator& pos, int data);
	void erase(Iterator& pos);
	void print();
	void find(int e);

private:
	Node* header;
	Node* trailer;
	int n; //사이즈
};

Sequence::Sequence() {
	header = new Node();
	trailer = new Node();
	header->next = trailer;
	trailer->prev = header;
	header->prev = trailer->next = NULL;
	n = 0;
}


Node* Sequence::begin() {
	return header->next;
}
Node* Sequence::end() {
	return trailer;
}

void Sequence::insert(Iterator &pos, int data) {
	Node* newNode = new Node(data);
	newNode->data = data;
	newNode->prev = pos.node->prev;
	newNode->next = pos.node;
	pos.node->prev = newNode;
	n++;
}

//𝑝가 trailer를 가리키는 경우, 연산을 수행하지 않고, 리스트가 비어 있는 경우, “Empty”를 출력한다.

void Sequence::erase(Iterator &pos) {
	if (n==0) cout << "Empty" << endl;
	else{
		Node* newNode = pos.node;
		pos.node->prev->next = pos.node->next;
		pos.node->next->prev = pos.node->prev;
		pos.node = begin();
		n--;
		delete pos.node;
	}
	
}


void Sequence::print() {
	if (n == 0) cout << "Empty" << endl;
	else{
		Node* nd = header->next;
		for (int i = 0; i < n; i++) {
			cout << nd->data << " ";
			nd = nd->next;

		}
	}
}

void Sequence::find(int e) {
	if (n == 0) {
		cout << "-1" << endl;
	}
	else{
		Node* nd = header;
		for (int i = 0; i < n; i++) {
			nd = nd->next;
			if (nd->data == e) {
				cout << i << endl;
			}
			else { nd = nd->next; }
			
		}
		}
	
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Sequence list;
	Iterator p = Iterator(list.begin());

	int m = 0;
	cin >> m;

	while (m--) {
		string cmd;
		cin >> cmd;
		if (cmd == "begin") {
			p = list.begin();
		}
		else if (cmd == "end") {
			p = list.end();
		}
		else if (cmd == "insert") {
			int e;
			cin >> e;
			list.insert(p, e);
		}
		else if (cmd == "erase") {
			list.erase(p);
		}
		else if (cmd == "nextP") {
			++p;
		}
		else if (cmd == "prevP") {
			--p;
		}
		else if (cmd == "print") {
			list.print();
		}
		else if (cmd == "find") {
			int e;
			cin >> e;
			list.find(e);
		}


	}
	return 0;
}