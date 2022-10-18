// linked_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
template <class type>
class LinkedList {
	struct Node
	{
		type value;
		Node* next;
	};
	Node* head=NULL , *last;
public:
	void insertAtEnd(type element) {
		Node *newNode=new Node;
		newNode->value = element;
		if (head == NULL) {
			head =last=newNode;
			newNode->next=NULL;
		}
		else {
			last->next = newNode;
			newNode->next = NULL;
			last = newNode;
		}
	}
	void insertAtBegin(type element) {
		Node* newNode = new Node;
		newNode->value = element;
		if (head == NULL) {
			head = last = newNode;
			newNode->next = NULL;
		}
		else {
			newNode->next = head;
			head = newNode;
			   
		}
	}
	void removeAtEnd() {
		if (head == NULL) {
			cout << "Empty Linked List" << endl;
		}
		else if (head->next==NULL) {
			delete head;
			head =last  = NULL;
		}
		else {
			Node *currentNode=head->next;
			Node* previouseNode = head;
			while (currentNode!=last) {
				previouseNode = currentNode;
				currentNode = currentNode->next;
			}
			delete currentNode;
			previouseNode->next = NULL;
			last = previouseNode;

		}

	}
	void removeAtBegin() {
		if (head == NULL) {
			cout << "Empty Linked List" << endl;
		}
		else if (head->next == NULL) {
			delete head;
			head = last = NULL;
		}
		else {
			Node* current = head;
			head = current->next;
			delete current;

		}
	}
	void display() {
		if (head == NULL) {
			cout << "Linked list is Empty"<<endl;
		}
		else {
			Node* current;
			current = head;
			while (current != NULL) {
				cout << current->value << " ";
				current = current->next;
			}
		}
	}


};

int main()
{
	LinkedList<double> l;
	l.insertAtEnd(2.6);
	l.insertAtEnd(3);
	l.insertAtEnd(5);
	l.insertAtBegin(9);
	l.removeAtBegin();
	l.display();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
