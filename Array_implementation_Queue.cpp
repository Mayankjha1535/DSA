#include<iostream>
using namespace std;
#define MAX_SIZE 101

class Queue
{
	private:
		int front,rear;
		int A[MAX_SIZE];
	public:
		Queue()
		{
			front=rear=-1;
		}
		
		void enqueue(int x)
		{
			if (rear==MAX_SIZE-1) //Queue is full
			{
				cout<<"Overflow"<<endl;
				return;
			}
			else if(IsEmpty()) //Check if Queue is empty
			{
				front=rear=0;
			}
			else
			{
				rear++;
			}
			A[rear]=x;	
		}
		
		void dequeue()
		{
			if(IsEmpty())//Queue is already empty
			{
				cout<<"Queue is already empty"<<endl;
				return ;
			}
			else if(front==rear)
			{
				front=rear==-1;
			}
			else
			{
				front++;
			}
		}
		
		int peek()
		{
			if(front==-1)
			{
				cout<<" Queue is empty "<<endl;
				return 0;
			}
			
			cout<<"Element at front is "<< A[front] <<endl;
			return A[front];
		}
		
		int IsEmpty()
		{
			if(front== -1 and rear==-1)
			{
				cout<<"Queue is empty now "<<endl;
				return 1;
			}
			else
			{
				return 0;
			}
		}
		void print()
		{
			cout<<"Elements in Queue are "<<endl;
			for(int i=front;i<=rear;i++)
			{
				cout<<A[i]<<endl;
			}
		}
};

int main()
{
	Queue Q;
	Q.peek();
    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(5);
    Q.peek();
    Q.print();
    Q.dequeue();
    Q.dequeue();
    Q.peek();
    Q.print();
	return 0;
}
