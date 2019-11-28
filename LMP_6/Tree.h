#pragma once

struct Node {
	int data;
	Node* left;
	Node* right;
};

// To insert data in BST, returns address of root node 
Node* Insert(Node* root, int data);
Node* Delete(struct Node* root, int data);
bool Search(Node* root, int data);
void ShowSymmetric(Node* tree);
void ShowStraight(Node* tree);
void ShowReverse(Node* tree);

