#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* link;
};

Node* head=NULL;

void insert(Node** head, int data, int pos)
{
	Node* temp = new Node();
	Node*temp1=*head;
	temp->data=data;
	temp->link=NULL;
	if(pos==1)
	{
		temp->link=*head;
		*head=temp;
	}
	else
	 {
	 	for(int i=0;i<pos-2;i++)
	 	{ 
			temp1=temp1->link;
	 	}
	 	temp->link=temp1->link;
	 	temp1->link=temp;
	 }
}

void recprint(Node* p)
{
	if(p==NULL)	
	{
 		return;
 	}
 	cout<<"-->"<<p->data;
 	recprint(p->link);
}

/*void revrecprint(Node* p)
{
	if(p==NULL){
		return;
	}
	revrecprint(p->link);
	cout<<"--> "<<p->data;
}

struct Node* rec_reverse(struct Node* p)
{
	if (p->link==NULL)
	{
		head=p;
		return head ;
	}
	rec_reverse(p->link);
	struct Node* q= p->link;
	q->link=p;
	p->link=NULL;
	
    return head;	
}*/
int main()
{   
	insert(&head,2,1);
    insert(&head,6,2);
	insert(&head,5,3);
	insert(&head,4,4);
	recprint(head);
    /*cout<<"Reverse list is "<<"-->";
    head=rec_reverse(head);
    recprint(head);*/
    return 0;
}
