#include<iostream>
using namespace std;
#define MAX_SIZE 4

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
			if ((rear+1)%MAX_SIZE==front) //Queue is full and check the condn whether rear is equal to the index just before front
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
				rear=(rear+1)%MAX_SIZE; //next element in circular array
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
				front=(front+1)%MAX_SIZE; //next element in circular array
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
			
			if(front<=rear)
			{
			for(int i=front;i<=rear;i++)  //normal case
				{
				cout<<A[i]<<endl;
				}
		   }
		   else
		   {
		   	for(int i=front;i<MAX_SIZE;i++)  // first print from front to last
		   		{
		   		   cout<<A[i]<<endl;	
				}
			for(int i=0;i<=rear;i++)  //print from 0th index to rear element
			{
				cout<<A[i] <<endl;
			}
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
