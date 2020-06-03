#include<iostream>
using namespace std ;

struct Node
{
	int data;
	Node * next;
};

Node* head=NULL;
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

void Delete(int pos)
{
	Node* temp1= head;
	for (int i=0;i<pos-2;i++)
	{
       temp1=temp1->next;
	}
	
	temp1=temp1->next;
	Node*temp2=temp1->next;
	temp1->next=temp2->next;
	delete(temp2);
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

void search(int x)
{
	Node* temp=head;
	int flag;
	while(temp!=NULL)
	{
		if (temp->data==x)
		{
			cout<<"Element present"<<endl;
			flag=1;

		}
		else{
			flag=0;
		}
		temp=temp->next;	
	}

}

void count(int x)
{
	Node*temp =head;
	int cnt=0;
	while(temp!=NULL)
	{
		if (temp->data==x)
		{  
		    cnt++;
		}
		temp=temp->next;
	}
	
	cout<<"The count of " << x <<" is " <<cnt<<endl;
	
}

void length()
{
	Node*temp=head;
	int len=0;
	while(temp!=NULL)
	{
		len++;
	temp=temp->next;
	}
	cout<<"The length of the list is "<< len<<endl;
	
}
void max_min()
{
	Node*temp = head;
	int max, min =temp->data;
	while(temp!=NULL)
	{
		if(temp->data >= max)
		{
			max=temp->data;
		}
		
		else if (temp->data < min)
		{
			min=temp->data;
		}
		temp=temp->next;
	}
	cout<<"The maximum element is "<<max <<" and the minimum element is "<<min<<endl;
}

void reverse()
{
	struct Node* curr, *prev,* next1;
	prev=NULL;
	curr =head;
	while(curr!=NULL)
	{
		next1=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next1;

	}
	head=prev;
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
	search(7);
	count(11);
	length();
	max_min();
	reverse();
	print();
}
