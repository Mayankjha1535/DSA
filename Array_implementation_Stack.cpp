#include<iostream>
using namespace std;
#define MAX_SIZE 1000

class Stack
{
	private:
		int A[MAX_SIZE];
		int top;
	public:
		Stack()
		{
		  top=-1;
		}
		void push(int x) //push operation
		{
			if(top==MAX_SIZE-1) //OVERFLOW Condition
			{
				cout<<"Overflow"<<endl;
				return;
			}
			A[++top]=x;
		}
		void pop() 
		{
			if(IsEmpty()) //Check whether stack is already empty
			{
				cout<<"Stack is already empty"<<endl;
				return;
			}
			top--;
		}
		int peek() //returns the top elements of the stack
		{
			cout<<"Element at top is "<< A[top] <<endl;
			return A[top];
		}
		
		int IsEmpty() //check whether stack is empty
		{
			if(top==-1)
			{
				return 1;
			}
			return 0;
		}
		void print()
		{
			cout<<"Elements of Stack are "<<endl;
			for (int i=0;i<=top;i++)
			{
				cout<<A[i]<<endl;
			}
		}
};

int main()
{
	Stack S;
	S.push(2);
	S.push(3);
	S.push(4);
	S.push(5);
	S.print();
	S.peek();
	S.IsEmpty();
	S.pop();
	S.pop();
	S.peek();
	S.print();
	return 0;
}

