#include"BinaryTree.h"
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	BinaryTree<int> q(5);
	q.setRoot(1);
	q.setLeftChild(1,2);
	q.setRightChild(1, 3);
	q.setLeftChild(2, 4);
	q.setRightChild(2, 5);
	q.setLeftChild(3, 6);
	q.setRightChild(3, 7);
	q.setLeftChild(4, 8);
	q.setRightChild(4, 9);
	q.setLeftChild(5, 10);
	q.setRightChild(5, 11);
	q.preOrder();
	cout << '\n';
	q.postOrder();
	cout << '\n';
	q.inOrder();
	//q.displayParenthesizedView();
	//q.displayExplorerView();
	return 0;
}