#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};
void Insert(Node**head, int d, int n)
{
	Node *temp=new Node();
	temp->data =d;
	temp->next=NULL;
	Node*temp1=*head;
	
	if (n==1)
	{
		temp->next=*head;
		*head=temp;
	}
	else
	{
		for (int i=0;i<n-2;i++)
		{
			temp1=temp1->next;
		}
	
	
	temp->next=temp1->next;
	temp1->next=temp;
	 }
}
void print(Node* head)
{
	Node *temp = head;
	cout<<"Elements of the list are---- " <<endl;
	while(temp!=NULL)
	{
		cout<< temp->data<<"-->>";
		temp=temp->next;
	}
}

Node* merge(Node* left,Node *right);
void split(Node* head,Node** left, Node** right);
void mergesort(Node** p)
{
	Node*left,*right;
	Node *temp=*p;
    if(temp==NULL|| temp->next==NULL)
    {
    	return;
	}
	split(temp,&left,&right);
	mergesort(&left);
	mergesort(&right);
	*p=merge(left,right);
}
void split(Node* head, Node** left, Node** right)
{
	Node* fast, *slow;
	slow=head;
	fast=head;
	while(fast->next!=NULL or fast->next->next!=NULL)
	{   
		slow=slow->next;
		fast=fast->next->next;	
	}
	*left=head;
	*right=slow->next;
	slow->next=NULL;
}
Node* merge(Node* left,Node* right)
{
	Node* ptr =NULL;
	if(left==NULL)
	{
		return right;
	}
	else if(right==NULL)
	{
		return left;
	}
	
	if(left->data < right->data)
	{
		ptr=left;
		ptr->next=merge(left->next,right);
	}
	else
	{
		ptr=right;
		ptr->next=merge(left,right->next);
	}
	return ptr;
}

int main()
{
	Node* head=NULL;
	Insert(&head,2,1);
    Insert(&head,6,2);
	Insert(&head,5,3);
	Insert(&head,4,4);
	Insert(&head,7,3);
	Insert(&head,1,5);
	print(head);
	mergesort(&head);
	print(head);
	return 0;
}
