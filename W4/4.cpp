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
	int dequeue(); //큐의 front에 저장된 원소를 삭제하는 함수
	bool isEmpty(); //큐가 비어있는지 확인하는 함수
	int front();

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

int listQueue::dequeue() {
	if (isEmpty()) {
		cout << "Empty" << endl;
	}
	else {
		node* curNode = frontNode;
		if (n == 1) {
			frontNode = rearNode = NULL;
		}
		else { frontNode = frontNode->next; }
		n--;
		return curNode->data;

	}


}

bool listQueue::isEmpty() { //큐가 비어있는지 확인하는 함수
	if (n == 0) {
		return true;
	}
	else {
		return false;
	}

}

int listQueue::front() { //큐의 front에 저장된 원소를 반환하는 함수
	if (isEmpty()) { //큐가 비어있는 경우 -1을 반환하고 종료
		cout << "Empty";
	}
	else return frontNode->data;
}


int main() {
	listQueue p1;
	listQueue p2;

	int n = 0;
	cin >> n;


	for (int i = 0; i < n; i++) {
		int p1Hp = 0;
		int p2Hp = 0;

		int p1Win = 0;
		int p2Win = 0;

		int t = 0;
		cin >> t;

		for (int i = 0; i < t; i++) {
			int card = 0;
			cin >> card;
			p1.enqueue(card);
		}
		for (int i = 0; i < t; i++) {
			int card = 0;
			cin >> card;
			p2.enqueue(card);
		}


		for (int i = 0; i < t; i++) {
			int p1Card = p1.front() + p1Hp;
			p1.dequeue();
			int p2Card = p2.front() + p2Hp;
			p2.dequeue();

			if (p1Card > p2Card) {
				p2Hp = p1Card - p2Card;
				p1Hp = 0;
				p1Win++;
			}

			else if (p2Card > p1Card) {
				p1Hp = p2Card - p1Card;
				p2Hp = 0;
				p2Win++;
			}

			else {
				p1Hp = p2Hp = 0;
			}


			if (p1Hp > p2Hp) {
				cout << "Round" << i + 1 << " " << "P2" << " " << p1Hp - p2Hp << endl;
			}
			else if (p2Hp > p1Hp) {
				cout << "Round" << i + 1 << " " << "P1" << " " << p2Hp - p1Hp << endl;
			}
			else if (p1Hp == p2Hp) {
				cout << "Round" << i + 1 << " " << "Draw" << endl;
			}
			
		}

		if (p1Win > p2Win) {
			cout << "Winner P1" << endl;
		}
		else if (p2Win > p1Win) {
			cout << "Winner P2" << endl;
		}
		else if (p2Win == p2Win) {
			cout << "Draw" << endl;
		}


	}
	return 0;
}