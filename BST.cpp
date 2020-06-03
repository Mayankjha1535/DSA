#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* GetNewNode(int x)
{
	BstNode* temp = new BstNode();
	temp->data=x;
	temp->left=NULL;
	temp->right= NULL;
	return temp;
}

BstNode* Insert(BstNode* root, int data)
{
	BstNode* temp = GetNewNode(data);
	if(root==NULL)
	{
		root=temp;
	}
	
	else if(data <= root->data){
		root->left=Insert(root->left,data);
	}
	else
	{
		root->right=Insert(root->right,data);
	}
	return root;
	
}

bool Search(BstNode* root, int key)
{
	if(root==NULL){
		return false;
	}
	else if(root->data==key){
		return true;
	}
	else if(key <= root->data)
	{
		return Search(root->left, key);
	}
	else
	{
		return Search(root->right, key);
	}
}
BstNode* FindMin(BstNode* root)
{
	if(root==NULL){
		return NULL;
	}
	
	else if(root->left == NULL){
		return root;
	}
	return FindMin(root->left);
}
BstNode* Delete(BstNode* root, int val)
{
	if(root=NULL){
		return NULL;
	}
	else if(val <= root->data){
	  root->left = Delete(root->left, val);
	}
	
	else if(val > root->data){
	  root->right= Delete(root->right, val);
	}
	
	else
	{
		if(root->left==NULL && root->right == NULL){
			delete root;
			root=NULL;
		}
		
		else if(root->left==NULL){
			BstNode* temp = root;
			root=root->right;
			delete temp;
		}
		
		else if(root->right==NULL){
			BstNode* temp = root;
			root=root->left;
			delete temp;			
		}
		
		else
		{
			BstNode* temp = FindMin(root->right);
			root->data=temp->data;
			root->right= Delete(root->right,temp->data);
		}
	}
	return root;
}

void Inorder(BstNode* root)
{
	if(root==NULL){
		return;
	}
	Inorder(root->left);
	cout<<root->data <<" ";
	Inorder(root->right);
}

void Postorder(BstNode* root)
{
	if(root==NULL){
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
    cout<<root->data <<" ";

}

void Preorder(BstNode* root)
{
	if(root==NULL){
		return;
	}
	cout<<root->data <<" ";
	Preorder(root->left);
	Preorder(root->right);
}

void LevelOrder(BstNode* root)
{
	queue<BstNode*> q;
	if(root == NULL){
		return;
	}
	q.push(root);
	while(!q.empty())
	{
		BstNode* temp= q.front();
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
bool isUtil(BstNode* root, int min, int max){
    if(root==NULL){
        return true;
    }
    if(root->data > min && root->data < max 
           && isUtil(root->left,min,root->data)
            &&isUtil(root->right, root->data, max)){
                return true;
            }
    else{
        return false;
    }       
}
bool isBST(BstNode* root) {
    return isUtil(root, INT_MIN,INT_MAX);
}
int main()
{
	BstNode* root = GetNewNode(5);
	root= Insert(root,3);
	root=Insert(root,10);
	root=Insert(root, 1);
	root=Insert(root, 4);
	root=Insert(root, 11);
	cout<<"Inorder traversal"<<" " ;
	Inorder(root);
	cout<<"Preorder traversal"<<" ";
	Preorder(root);
	cout<<"Postorder traversal"<<" ";
	Postorder(root);
	cout<<"Level Order traversal"<<" ";
	LevelOrder(root);
	cout<<"Search for 11 "<<Search(root,11)<" " ;
	int bst = isBST(root);
	if(bst){
		cout<<"Given Tree is a BST ";
	}
	else{
		cout<<"Tree is not a BST ";
	}
		
}



