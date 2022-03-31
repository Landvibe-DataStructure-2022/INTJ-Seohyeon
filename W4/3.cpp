#include<iostream>
using namespace std;

class arrayQueue
{
private:
	int* arr;
	int capacity;
	int frontIndex;
	int rearIndex;
	int n;

public:
	arrayQueue(int capacity);
	bool empty();
	int size();
	void front();
	void rear();
	void enqueue(int data);
	void dequeue();



};

arrayQueue::arrayQueue(int capacity)
{
	this->capacity = capacity;
	arr = new int[capacity];
	frontIndex = rearIndex = 0;
	n = 0;
};

bool arrayQueue::empty()
{
	return(n == 0);
}

int arrayQueue::size()
{
	return n;
}
void arrayQueue::front()
{
	if (n == 0)
	{
		cout << "Empty" << endl;
	}
	else cout << arr[frontIndex] << endl;
}

void arrayQueue::rear() {
	if (n == 0) {
		cout << "Empty" << endl;
	}
	else {
		if (rearIndex - 1 < 0) {
			cout << arr[capacity - 1] << endl;
		}
		else {
			cout << arr[rearIndex - 1] << endl;
		}
	}
}

void arrayQueue::enqueue(int data)
{
	if (size() == capacity)
	{
		cout << "Full" << endl;
		}
	else{
		arr[rearIndex] = data;
		rearIndex = (rearIndex + 1) % capacity;
		n++;
	}
	

}
void arrayQueue::dequeue()
{
	if (n == 0)
	{
		cout << "Empty" << endl;
	}
	else{
		cout << arr[frontIndex] << endl;
		frontIndex = (frontIndex + 1) % capacity;
		n--;
	}
	


}


int main()
{
	int n, t;
	cin >> n >> t;
	arrayQueue q(n);

	for (int i = 0; i < t; i++)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "enqueue") {
			int x;
			cin >> x;
			q.enqueue(x);
		}
		else if (cmd == "dequeue") {
			q.dequeue();
		}
		else if (cmd == "isEmpty") {
			if (q.empty()) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		
		}
		else if (cmd == "size") {
			cout << q.size() << endl;
		}
		else if (cmd == "front") {
			q.front();
		}
		else if (cmd == "rear") {
			q.rear();
		}
	}
	return 0;
}