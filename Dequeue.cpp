#include<iostream>
using namespace std;
#define MAX_SIZE 5

class Dequeue
{
	private:
		int A[MAX_SIZE];
		int front,rear;
		
	public:
		Dequeue()
		{
			front=-1;
			rear=-1;
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
		
		void Insert_at_front(int x)
		{
			if ((rear+1)%MAX_SIZE==front) //Queue is full
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
				front=(front+MAX_SIZE -1)%MAX_SIZE; //This formula can be used to go to previous position in a circular array.
				 									// This equation handles the case when front = 0
			}
			A[front]=x;
		}
		
		void Insert_at_back(int x)
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
		
		void Delete_at_front()
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
		
		void Delete_at_back()
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
				rear=(rear+MAX_SIZE-1)%MAX_SIZE; //This formula can be used to go to previous position in a circular array.
				 								 // This equation handles the case when rear = 0
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
	Dequeue DQ;
	DQ.Insert_at_front(2);
	DQ.Insert_at_front(3);
	DQ.Insert_at_front(4);
	DQ.Insert_at_front(5);
	DQ.Insert_at_front(6);
	DQ.peek();
	DQ.print();
	DQ.Delete_at_back();
	DQ.Delete_at_back();
	DQ.peek();
	DQ.print();
	
}
