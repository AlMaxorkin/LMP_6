#pragma once

struct Node {
	int data;
	Node* left;
	Node* right;
};

 
Node* Insert(Node* root, int data);
Node* Delete(struct Node* root, int data);
void Delete_Node(Node*);
Node* Search(Node* root, int data);
void ShowSymmetric(Node* tree);
void ShowStraight(Node* tree);
void ShowReverse(Node* tree);

