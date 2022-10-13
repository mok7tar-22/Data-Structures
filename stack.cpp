#include<iostream>
using namespace std;
const int maxSize = 5;
template<class type>
class Stack {
private:
	int top;
	type item[maxSize];

public:
	Stack() :top(-1) {}

	bool isEmpty() {
		return top < 0;
	}

	void push(type element) {
		if (top >= maxSize - 1) {
			cout << "Stack full on push";
		}
		else
		{
			top++;
			item[top] = element;
		}
	}
	void pop()
	{
		if (isEmpty())
			cout << "stack empty on pop";
		else
			top--;
	}
	void getTop() {
		if (isEmpty()) {
			cout << "stack empty on pop";
		}
		else {
			cout << item[top];
		}

	}
	void print() {
		cout << "[ ";
		for (int i = top; i >= 0; i--)
		{
			cout << item[i] << " ";
		}
		cout << "]";
		cout << endl;

	}



};
int main()
{
	Stack<int> s;
	s.push(5);
	s.push(15);
	s.push(20);
	s.print();
	s.pop();
	s.print();
	return 0;
}
