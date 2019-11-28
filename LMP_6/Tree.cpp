#include "Tree.h"
#include <iostream>

using namespace std;

// Function to create a new Node in heap

Node* FindMin(Node* root)
{
	while (root->left != NULL) 
		root = root->left;
	return root;
}

Node* FindMax(Node* root)
{
	while (root->right != NULL)
		root = root->right;
	return root;
}

// To insert data in BST, returns address of root node 
Node* Insert(Node* root, int data) {
	if (root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	// if data to be inserted is lesser, insert in left subtree. 
	else if (data <= root->data)
		root->left = Insert(root->left, data);
	// else, insert in right subtree. 
	else
		root->right = Insert(root->right, data);
	return root;
}
//To search an element in BST, returns true if element is found
bool Search(Node* root, int data) {
	if (root == NULL) {
		return false;
	}
	else if (root->data == data) {
		return true;
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
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//Case 2: One child 
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
		// case 3: 2 children
		else {
			struct Node* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

Node* DeleteByPointer(Node* p1, Node* p2)
{
	if (p1 == NULL || p2 == NULL)
		return p1;

	Node* temp = p2;
	temp = FindMax(p2);
	p2->data = temp->data;
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

}

void ShowStraight(Node* tree)
{
	if (NULL == tree)    return;    //Если дерева нет, выходим

	cout << tree->data << endl; //Посетили узел
	ShowStraight(tree->left); //Обошли левое поддерево   
	ShowStraight(tree->right); //Обошли правое поддерево   
}

void ShowSymmetric(Node* tree)
{
	if (NULL == tree)    return;    //Если дерева нет, выходим

	ShowSymmetric(tree->left); //Обошли левое поддерево 
	cout << tree->data << endl; //Посетили узел
	ShowSymmetric(tree->right); //Обошли правое поддерево   
}

/*ОБРАТНЫЙ ОБХОД*/
void ShowReverse(Node* tree)
{
	if (NULL == tree)    return;    //Если дерева нет, выходим

	ShowReverse(tree->left); //Обошли левое поддерево 
	ShowReverse(tree->right); //Обошли правое поддерево  

	cout << tree->data << endl; //Посетили узел 
}