#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* front=NULL;
Node* rear=NULL;

void enqueue(int x)
{
	Node* temp=new Node();
	temp->data=x;
	temp->next=NULL;
	if(front==NULL and rear==NULL) //As LL uses dynamic memory allocation so we do not have to check for overflow condn
	{
		front=rear=temp;
	}
	rear->next=temp;
	rear=temp;
}

void dequeue()
{
	if(front==NULL)
	{
		cout<<"Queue is already empty "<<endl;
		return;
	}
	else if(front==rear)
	{
		front=rear=NULL;
	}
	else
	{
		Node* temp=front;
		front=front->next;
		delete(temp);
	}
	
}

void peek()
{
	if(front==NULL)
	{
		cout<<" Queue is empty "<<endl;
		return;
	}
	
	cout<< "Element at the front is "<< front->data<<endl;	
}

void print()
{
	Node* temp=front;
	cout<<"Elements in Queue are"<<endl;
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	
}

int main()
{
	peek();
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	peek();
	print();
	dequeue();
	dequeue();
	peek();
	print();
}
