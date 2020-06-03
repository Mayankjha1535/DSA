#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* prev;
	Node* next;
};
struct Node* head=NULL;
void insert(int x, int pos)
{
	Node* temp = new Node();
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL ;
	if (pos==1)
	{
		temp->next=head;
		head=temp;
		return;
	}
	else
	{
		Node* temp1=head;
		for (int i=0;i<pos-2;i++)
		{
			temp1=temp1->next;
		}
		temp->next=temp1->next; //temp is the new node
		temp1->next=temp;
		temp1->next->prev=temp; 
		temp->prev=temp1;

	}
	
}

void print()
{
	Node*temp=head;
	cout<<"Doubly Linked List is ---"<<endl;
	while(temp!=NULL)
	{
		cout<< temp->data<<"-->"<<endl;
		temp=temp->next;

	}
}

void Delete(int pos)
{
	Node* temp=head;
	for(int i=0;i<pos-2;i++)
	{
		temp=temp->next;
	}
	Node* curr= temp->next; //curr is the node to be deleted
	temp->next=curr->next;
	curr->next->prev=temp;
	delete(curr);
}

void reverse()
{
	Node* prev1,*curr,*next1;
	prev1=NULL;
	curr=head;
	while(curr!=NULL)
	{
		next1=curr->next;
		curr->next=prev1;
		curr->prev=next1;
		prev1=curr;
		curr=next1;	
	}
	head=prev1;
}
int main()
{   
	cout<<"Program begin"<<endl;
	insert(2,1);
	insert(3,2);
	insert(4,3);
	insert(5,1);
	print();
	reverse();
	print();
	Delete(2);
	print();

	return 0;
}
