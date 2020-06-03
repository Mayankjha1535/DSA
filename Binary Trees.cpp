#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct BinaryTree
{
	int data;
	BinaryTree* left;
	BinaryTree* right;
};

BinaryTree* GetNewNode(int x)
{
	BinaryTree* temp = new BinaryTree();
	temp->data=x;
	temp->left=NULL;
	temp->right= NULL;
	return temp;
}

void Insert(BinaryTree* root,int data)
{
	queue<BinaryTree*> q;
	BinaryTree* temp;
	q.push(root);
	while(!q.empty()){
		temp=q.front();
		q.pop();
		if(temp->left==NULL){
			temp->left=GetNewNode(data);
			break;
		}
		else
		{
			q.push(temp->left);
		}
	    if(temp->right==NULL){
			temp->right=GetNewNode(data);
			break;
		}
		else
		{
			q.push(temp->right);
		}
	}
}
BinaryTree* delete_deepest(BinaryTree* root)
{
	if(root->right==NULL)
	{
		delete root;
		return NULL;
	}
	root->right=delete_deepest(root->right);
	return root;
}
BinaryTree* Delete(BinaryTree* root, int key)
{
	queue<BinaryTree*> q;
	if(root ==NULL)
	{
		return NULL;
	}
	if(root->left==NULL and root->right==NULL)
	{
		if(root->data==key){
			delete root;
		}
		else
		{
			return root;
		}
	}
	q.push(root);
	BinaryTree* key_node;
	BinaryTree* temp;
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		if(temp->data==key){
			key_node=temp;
		}
		if(temp->left){
			q.push(temp->left);
		}
		if(temp->right){
			q.push(temp->right);
		}
	}
	
	if(key_node!=NULL){
		int x=temp->data;
		delete_deepest(temp);
		key_node->data=x;
	}
	return root;	
}

void Inorder(BinaryTree* root)
{
	if(root==NULL){
		return;
	}
	Inorder(root->left);
	cout<<root->data <<" ";
	Inorder(root->right);
}

void Postorder(BinaryTree* root)
{
	if(root==NULL){
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
    cout<<root->data <<" ";

}

void Preorder(BinaryTree* root)
{
	if(root==NULL){
		return;
	}
	cout<<root->data <<" ";
	Preorder(root->left);
	Preorder(root->right);
}

void LevelOrder(BinaryTree* root)
{
	queue<BinaryTree*> q;
	if(root == NULL){
		return;
	}
	q.push(root);
	while(!q.empty())
	{
		BinaryTree* temp= q.front();
		cout<<temp->data<<" ";
		if(temp->left!=NULL){
			q.push(temp->left);
		}
		if(temp->right!=NULL){
			q.push(temp->right);
		}
		q.pop();
	}
}

void Reverse_LevelOrder(BinaryTree* root)
{
	if(root==NULL){
		return;
	}
	queue<BinaryTree*> q;
	stack<BinaryTree*> s;
	q.push(root);
	while(!q.empty())
	{
		BinaryTree* temp=q.front();
		q.pop();
		s.push(temp);
		if(temp->right){
			q.push(temp->right);
		}
		if(temp->left){
			q.push(temp->left);
		}
	}
	
	while(!s.empty()){
		root = s.top();
		cout<<root->data<<" ";
		s.pop();
	}
}

void search(BinaryTree* root, int key)
{
	if(root==NULL)
	{
		return;
	}
	if(root->left==NULL and root->left==NULL)
	{
		if(root->data==key){
			cout<<"Item found";
		}
		else
		{
			cout<<"Item not present";
		}
	}
	queue<BinaryTree* > q;
	q.push(root);
	
	while(!q.empty())
	{
		BinaryTree* temp=q.front();
		q.pop();
		if(temp->data==key){
			cout<<"Item found";
			break;
		}
		if(temp->left){
			q.push(temp->left);
		}
		if(temp->right){
			q.push(temp->right);
		}
	}
}

int height(BinaryTree* root)
{
	if(root == NULL){
		return 0;
	}
	int left_height= height(root->left);
	int right_height = height (root->right);
	return max(left_height, right_height) + 1;
}

int diameter(BinaryTree* root)
{
	if(root==NULL){
		return 0;
	}
	int lheight = height (root->left);
	int rheight = height (root->right);
	int ldiameter = diameter(root->left);
	int rdiameter = diameter(root->right);
	return max (lheight + rheight + 1, max(ldiameter,rdiameter));
}
int main()
{
	BinaryTree* root = GetNewNode(10);
	Insert(root,11);
	Insert(root, 12);
	Insert(root,13);
	Insert(root, 14);
	Insert(root, 15);
	Insert(root, 16);
	cout<<"Inorder traversal"<<" " ;
	Inorder(root);
	cout<<"Preorder traversal"<<" ";
	Preorder(root);
	cout<<"Postorder traversal"<<" ";
	Postorder(root);
	cout<<"Level Order traversal"<<" ";
	LevelOrder(root);
	cout<<"Reverse Level Order traversal" <<" ";
	Reverse_LevelOrder(root);
	int h= height(root);
	cout<<"Height of the tree "<< h;
	int d = diameter(root);
	cout<<"Diameter of the tree "<< d;
	search(root, 12);
	Delete(root, 12);
	cout<<endl;
	cout<<"Inorder traversal"<<" ";
	Inorder(root);
}
