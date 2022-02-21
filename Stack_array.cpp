/*Stack : Array Implementation */
#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Stack
{
	int top;

public:
	int A[MAX_SIZE];
	Stack() { top = -1; }
	void Push(int);
	void Pop();
	int Top();
	bool isEmpty();
	void Print();
};

void Stack::Push(int x)
{
	if (top == MAX_SIZE - 1)
	{
		cout << "Error : Stack Overflow" << endl;
		return;
	}
	A[++top] = x;
	// top++;
	// A[top] = x;
}

void Stack::Pop()
{
	if (top == -1)
	{
		cout << "Error : Stack Underflow(No element to pop)" << endl;
		return;
	}
	top--;
}

int Stack::Top()
{
	return A[top];
}

bool Stack::isEmpty()
{
	return (top < 0);
}

void Stack::Print()
{
	cout << "Stack : ";
	for (int i = 0; i <= top; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

int main()
{
	Stack s;
	s.Push(2);
	s.Print();
	s.Push(4);
	s.Print();
	s.Push(6);
	s.Print();
	s.Push(8);
	s.Print();
	s.Pop();
	s.Print();
	s.Pop();
	s.Print();
	cout << s.isEmpty();
}