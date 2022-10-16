#include<iostream>
using namespace std;
template<class type>
class Stack {
private:
	struct node
	{
		type value;
		node* next;
	};
	node* topPointer, * currentPointer;
public:
	Stack() {
		topPointer = NULL;
	}
	bool isEmpty()
	{
		return topPointer == NULL;
	}
	void push(type newItem)
	{
		node* newPtr = new node;
		if (newPtr == NULL)
			cout << "Stack push cannot allocate memory";
		else
		{
			newPtr->value = newItem;
			newPtr->next = topPointer;
			topPointer = newPtr;
		}
	}
	void pop() {
		if (isEmpty())
			cout << "Stack empty on pop";
		else {
			node* temp = topPointer;
			topPointer = topPointer->next;
			temp->next = NULL;
			delete temp;
		}
	}
	void pop(type stackTop)
	{
		if (isEmpty())
			cout << "Stack empty on pop";
		else {
			stackTop = topPointer->value;
			node* temp = topPointer;
			topPointer = topPointer->next;
			temp->next = NULL;
			delete temp;
		}
	}
	void getTop(type &stackTop)
	{
		if (isEmpty())
			cout << "stack empty on getTop";
		else
			stackTop = topPointer->value;
		cout << "\nTop Element of the stack is " << stackTop;
		cout << endl;
	}
	void print()
	{
		currentPointer = topPointer;
		cout << "\nItems in the stack : ";
		cout << "[ ";
		while (currentPointer != NULL)
		{
			cout << currentPointer->value<<" ";
			currentPointer = currentPointer->next;
		}
		cout << " ]\n";
	}
};
int main()
{
	Stack<int>s;
	s.push(10);
	s.push(20);
	s.push(50);
	s.push(90);
	int x;
	s.getTop(x);
	cout << "top value=" << x << endl;
	s.print();
}