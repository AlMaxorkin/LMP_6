#include "Tree.h"
#include <iostream>

using namespace std;

Node* FindMin(Node* root)
{
	while (root->left != NULL) 
		root = root->left;
	return root;
}

Node* Insert(Node* root, int data) {
	if (root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	
	else if (data <= root->data)
		root->left = Insert(root->left, data);

	else
		root->right = Insert(root->right, data);
	return root;
}

Node* Search(Node* root, int data) {
	if (root == NULL) {
		return NULL;
	}
	else if (root->data == data) {
		return root;
	}
	else if (data <= root->data) {
		return Search(root->left, data);
	}
	else {
		return Search(root->right, data);
	}
}

Node* Delete(struct Node* root, int data) {
	if (root == NULL) 
		return root;
	else if (data < root->data) 
		root->left = Delete(root->left, data);
	else if (data > root->data) 
		root->right = Delete(root->right, data);
	else {
		
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		
		else if (root->left == NULL) {
			struct Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			struct Node* temp = root;
			root = root->left;
			delete temp;
		}
		
		else {
			struct Node* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

void Delete_Node(struct Node* p2)
{
	if (p2->left == NULL || p2->right == NULL)
	{
		cout << "p2 must have 2 childs" << endl;
		return;
	}

	Node* temp = p2->left;
	Node* parrent = p2;

	while (temp->right != NULL)
	{
		parrent = temp;
		temp = temp->right;
	}
	p2->data = temp->data;

	if(temp->left!=NULL)
	{
		parrent->right = temp->left;
		delete temp;
	}
	else if(parrent == p2)
	{
		parrent->left = NULL;
		delete temp;
	}
	else
	{
		parrent->right = NULL;
		delete temp;
	}
	
}

void ShowStraight(Node* root)
{
	if (root == NULL)   
		return;    

	cout << root->data << endl; 
	ShowStraight(root->left);  
	ShowStraight(root->right);  
}

void ShowSymmetric(Node* root)
{
	if (root == NULL)
		return;   

	ShowSymmetric(root->left); 
	cout << root->data << endl; 
	ShowSymmetric(root->right);  
}

void ShowReverse(Node* root)
{
	if (root == NULL)
		 return;    

	ShowReverse(root->left); 
	ShowReverse(root->right); 

	cout << root->data << endl; 
}