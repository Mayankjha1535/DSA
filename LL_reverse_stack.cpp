#include<iostream>
#include<stack>
using namespace std ;

struct Node
{
	int data;
	Node * next;
};
Node* head=NULL;
stack<Node*> S; //Stack using STL

void Insert(int d, int n)
{
	Node *temp=new Node();
	temp->data =d;
	temp->next=NULL;
	
	if (n==1)
	{
		temp->next=head;
		head=temp;
	}
	else
	{
		Node* temp1=head;
		for (int i=0;i<n-2;i++)
		{
			temp1=temp1->next;
		}
	
	
	temp->next=temp1->next;
	temp1->next=temp;
	 }
}
void print()
{
	Node *temp = head;
	cout<<"Elements of the list are---- " <<endl;
	while(temp!=NULL)
	{
		cout<< temp->data<<"-->>";
		temp=temp->next;
	}
}

void reverse()
{
	Node* temp=head;
	while(temp!=NULL)
	{
		S.push(temp);
		temp=temp->next;
	}
	temp=S.top();
	head=temp;
	S.pop();
	while(!S.empty())
	{
		temp->next=S.top();
		S.pop();
		temp=temp->next;
	}
	temp->next=NULL; //change the address of the last node
}

int main()
{
	cout<<"Program begin :)" <<endl;
	Insert(7,1);
	Insert(5,2);
	Insert(11,3);
	Insert(11,4);
	Insert(7,3);
	Insert(9,4);
	print();
	reverse();
	print();
}
	
	
