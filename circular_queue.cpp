// circular_queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
const int length = 5;
class CircularQueue {

    int front=-1;
    int rear=-1;
    int count = 0;
    int queue[length];
public:
    bool isEmpty() {
        if (front ==-1) {
            return true;

        }
        return false;
    }
    bool isFull() {
        if (front == 0 && rear == length - 1) {
            return true;
        }
        else if (front == rear + 1) {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
        }
        else {
            if (isEmpty()) {
                front = rear = 0;
                queue[rear] = value;
            }
            else if (rear == length - 1)
            {
                rear = 0;
                queue[rear] = value;
            }
            else
            {
                queue[++rear] = value;
            }
        }
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "queue is empty." << endl;
        }
        else
        {
            if (front == rear) {
                front = rear = -1;
            }
            else if (front == length - 1) {
                front = 0;
            }
            else
            {
                front++;
            }
        }
    }
    int peek() {
        if (isEmpty()) {
            cout << "queue is empty." << endl;
            return -1;
        }
        else
        {
            return queue[front];
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "queue is empty." << endl;
        }
        else
        {
            if (front <= rear) {
                for (int i = front; i <= rear; i++)
                {
                    cout << queue[i] << "\t";
                }
                cout << endl;
            }
            else
            {
                for (int i = front; i < length; i++)
                {
                    cout << queue[i] << "\t";
                }
                for (int i = 0; i <= rear; i++)
                {
                    cout << queue[i] << "\t";
                }
                cout << endl;
            }
        }
        }

};

int main()
{
    CircularQueue q;
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(8);
    q.display();
    q.dequeue();
    q.display();
}
