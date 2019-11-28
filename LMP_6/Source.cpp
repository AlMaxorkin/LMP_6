#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
	Node* root = NULL;
	root = Insert(root, 12);
	root = Insert(root, 13);
	root = Insert(root, 14);
	root = Insert(root, 8);
	root = Insert(root, 7);
	root = Insert(root, 20);

	root = Delete(root, 8);


	ShowStraight(root);
	cout << endl;
	ShowSymmetric(root);
	cout << endl;
	ShowReverse(root);

	system("pause");
	return 0;
}