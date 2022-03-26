#include <iostream>
using namespace std;

struct node {
	int data; //데이터 필드
	node* next; //링크 필드
	};

class listQueue {
public:
	listQueue(); //기본 생성자
	void enqueue(int data); //큐의 rear에 원소를 삽입하는 함수
	void dequeue(); //큐의 front에 저장된 원소를 삭제하는 함수
	bool isEmpty(); //큐가 비어있는지 확인하는 함수
	int size(); //큐의 크기를 반환하는 함수
	void front(); //큐의 front에 저장된 원소를 반환하는 함수
	void rear();

private:
	node* frontNode; //링크드 리스트의 head역할
	node* rearNode; //링크드 리스트의 tail역할
	int n; //큐의 크기를 저장하는 변수
	};

listQueue::listQueue() { //기본 생성자
	frontNode = NULL; //private 변수 초기화
	rearNode = NULL;
	n = 0;
}



void listQueue::enqueue(int data) {
	node* newNode = new node;
	newNode->data = data;
	newNode->next = NULL;
	if (isEmpty()) {
		frontNode = rearNode = newNode;
	}
	else {
		rearNode->next = newNode;
		rearNode = newNode;
	}
	n++;
}

void listQueue::dequeue() {
	if (isEmpty()) {
		cout << "Empty" << endl;
	}
	else {
		node* curNode = frontNode;
		if (size() == 1) {
			frontNode = rearNode = NULL;
		}
		else { frontNode = frontNode->next; }
		cout << curNode->data << endl;
		delete curNode;
		n--;
	}


}

bool listQueue::isEmpty() { //큐가 비어있는지 확인하는 함수
	if (size() == 0) {
		return true;
	}
	else {
		return false;
	}

}

int listQueue::size() { //큐의 크기를 반환하는 함수
	return n;
}

void listQueue::front() { //큐의 front에 저장된 원소를 반환하는 함수
	if (isEmpty()) { //큐가 비어있는 경우 -1을 반환하고 종료
		cout << "Empty";
	}
	else cout << frontNode->data;
	cout << endl;

}



void listQueue::rear() { //큐의 rear에 저장된 원소를 반환하는 함수
	if (isEmpty()) cout << "Empty"; //큐가 비어있는 경우 -1을 반환하고 종료
	else cout<< rearNode->data;
	cout << endl;
}

int main() {
	listQueue lq;

	int T = 0;
	cin >> T;


	while (T--) {
		string s;
		cin >> s;
		if (s == "enqueue") {
			int value;
			cin >> value;
			lq.enqueue(value);
		}
		else if (s == "dequeue") lq.dequeue();
		else if (s == "isEmpty") {
			if (lq.isEmpty()) {
				cout << "True" << endl;
			}
			else cout << "False" << endl;
		}
		else if (s == "size") cout << lq.size() << endl;
		else if (s == "front") lq.front();
		else if (s == "rear") lq.rear();

	}
	return 0;
}
