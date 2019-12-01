#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
	Node* root = NULL;
	/* 
			  50
		   /     \
		  30      70
		 /  \    /  \
	   20   40  60  80 
	           /  \
			  55   65*/


	root = Insert(root, 50);
	root = Insert(root, 30);
	root = Insert(root, 20);
	root = Insert(root, 40);
	root = Insert(root, 70);
	root = Insert(root, 60);
	root = Insert(root, 80);
	root = Insert(root, 55);
	root = Insert(root, 65);

	
	ShowStraight(root);
	cout << endl;

	Node* p2 = Search(root, 60);
	Delete_Node(p2);

	ShowStraight(root);
	cout << endl;


	ShowSymmetric(root);
	cout << endl;
	ShowReverse(root);

	system("pause");
	return 0;
}