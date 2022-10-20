#include <iostream>
using namespace std;
class Queue {

	struct Node
	{
		int value;
		Node* next;
	};

	Node* front, * rear;
	
public:
	Queue() {
		front = NULL;
		rear = NULL;
	}
	void enqueue(int data) {
		Node* newNode=new Node;
		newNode->value=data;
		newNode->next = NULL;
		if (front==NULL)
		{
			front = rear = newNode;
		}
		else
		{
			rear->next = newNode;
			rear = newNode;
		}
	}
	void dequeue() {
		if (front == NULL) {
			cout << "Empty Queue" << endl;
		}
		else {
			Node* current;
			if (front == rear) {
				current = front;
				front = NULL;
				rear = NULL;
				delete current;
			}
			else {
				current = front;
				front = front->next;
				delete current;
			}

		}
	}
		
	void peek() {
		if (front == NULL) {
			cout << "Empty Queue" << endl;
		}
		else {
			cout << front->value << endl;
		}
	}
	void rearFun() {
		if (front == NULL) {
			cout << "Empty Queue" << endl;
		}
		else {
			cout << rear->value << endl;
		}
	}
	void display() {
		Node* currentNode;

		if (front == NULL) {
			cout << "queue is empty." << endl;
		}

		else
		{
			currentNode = front;
			cout << "[";
			while (currentNode != NULL)
			{
				cout << currentNode->value<< " ";
				currentNode = currentNode->next;
			}
			cout << "]"<<endl;
		}
	}
    



};
int main()
{
    Queue q=Queue();
	q.enqueue(10);
	q.enqueue(60);
	q.enqueue(70);
	q.enqueue(80);
	q.display();
	q.dequeue();
	q.display();

	q.peek();
	q.rearFun();
}


