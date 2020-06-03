#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

void push(Node** top, int x) //Insert at head as it will take O(1) time
{
	Node* temp=new Node(); //Here is the benefit of using LL implementation as we do not have to check for overflow condn.
	temp->data=x;
	temp->next=*top;
	*top=temp;
}

void pop(Node** top) //Delete at last as it will take O(1) time
{
	Node* temp= *top;
	if(top==NULL)
	{
		cout<<"Stack is already empty"<<endl;
		return;
	}
	*top=temp->next;
	delete(temp);
}

void print(Node* p)
{
	Node* temp=p;
	cout<<"Elements of the stack are "<<endl;
	while(temp!=NULL)
	{
		cout<<temp->data <<endl;
		temp=temp->next;
	}
}
void peek(Node* p)
{
	cout<<"	Element at the top of stack are "<<p->data<<endl;
}
int main()
{
	Node* top = NULL;
	push(&top, 2);
	push(&top,3);
	push(&top,4);
	push(&top,5);
	peek(top);
	print(top);
	pop(&top);
	pop(&top);
	peek(top);
	print(top);
	return 0;
	
}
