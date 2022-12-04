#include"BinaryTree.h"
#include<iostream>
#include<cmath>
using namespace std;
template<typename T>
int BinaryTree<T>::searchNodeInd(T parent)
{
	if (maxHeight == 0)
		exit(0);
	int treeSize = pow(2, maxHeight) - 1;
	for (int i = 0; i < treeSize; i++)
	{
		if (data[i] == parent)
			return i;
	}
	return -1;

}
template<typename T>
BinaryTree<T>::BinaryTree(int h) :maxHeight(h)
{
	int treeSize = pow(2, maxHeight) - 1;
	data = new T[treeSize];
	nodeStatus = new bool[treeSize];
	for (int i = 0; i < treeSize; i++)
		nodeStatus[i] = false;
}
template<typename T>
void BinaryTree<T>::setRoot(T v)
{
	if (!nodeStatus[0])
	{
		data[0] = v;
		nodeStatus[0] = true;
	}
}
template<typename T>
T BinaryTree<T>::getRoot()
{
	if (nodeStatus[0])
		return data[0];
}
template<typename T>
void BinaryTree<T>::setLeftChild(T parent, T child)
{
	int ind = searchNodeInd(parent);
	if (ind == -1)
		return;
	data[2 * ind + 1] = child;
	nodeStatus[2 * ind + 1] = true;
}
template<typename T>
void BinaryTree<T>::setRightChild(T parent, T child)
{
	int ind = searchNodeInd(parent);
	if (ind == -1)
		return;
	data[2 * ind + 2] = child;
	nodeStatus[2 * ind + 2] = true;
}
template<typename T>
T BinaryTree<T>::getParent(T node)
{
	int ind = searchNodeInd(node);
	if (ind == -1)
		exit(0);
	return data[(ind - 1) / 2];
}
template<typename T>
void BinaryTree<T>::remove(T node)
{
	int ind = searchNodeInd(node);
	int treeSize = pow(2, maxHeight) - 1;
	if (ind == -1 || ind >= treeSize)
		return;
	nodeStatus[ind] = false;
	if (nodeStatus[2 * ind + 1])
		remove(data[2 * ind + 1]);
	if (nodeStatus[2 * ind + 2])
		remove(data[2 * ind + 2]);
}
template<typename T>
void BinaryTree<T>::displayAncestors(T node)
{
	if (!nodeStatus[0])
		return;
	int ind = searchNodeInd(node);
	if (ind == -1 || ind == 0)
		return;
	ind = (ind - 1) / 2;
	cout << data[ind] << " ";
	displayAncestors(data[ind]);
}
template<typename T>
void BinaryTree<T>::displaDescendents(T node)
{
	int ind = searchNodeInd(node);
	int treeSize = pow(2, maxHeight) - 1;
	if (ind == -1 || ind >= treeSize)
		return;
	nodeStatus[ind] = false;
	if (nodeStatus[2 * ind + 1])
	{
		cout << data[2 * ind + 1] << " ";
		displaDescendents(data[2 * ind + 1]);
	}
	if (nodeStatus[2 * ind + 2])
	{
		cout << data[2 * ind + 2] << " ";
		displaDescendents(data[2 * ind + 2]);
	}
}
template<typename T>
int BinaryTree<T>::HeightOfTree()
{
	return maxHeight;
}
template<typename T>
void BinaryTree<T>::displayLevel(int levelNo)
{
	if (maxHeight == 0)
		return;
	int len = pow(2, levelNo - 1)
		, j = len - 1;
	for (int i = 0; i < len; i++)
	{
		if (nodeStatus[j])
			cout << data[j] << "\n";
		j++;
	}
}
template<typename T>
int BinaryTree<T>::findLevelOfNode(T node)
{
	if (maxHeight == 0)
		return -1;
	for (int i = 1; i <= maxHeight; i++)
	{
		int len = pow(2, i - 1);
		int ind = len - 1;
		for (int j = 0; j < len; j++)
		{
			if (data[ind] == node)
				return i;
			ind++;
		}
	}
	return -1;
}
template<typename T>
void BinaryTree<T>::levelOrder()
{
	if (maxHeight == 0)
		return;
	int treeSize = pow(2, maxHeight) - 1;
	for (int i = 0; i < treeSize; i++)
	{
		if (nodeStatus[i])
			cout << data[i] << "\n";
	}
}
template<typename T>
void BinaryTree<T>::preOrder()
{
	if (maxHeight == 0)
		return;
	preOrderInd(0);	
}
template<typename T>
void BinaryTree<T>::preOrderInd(int ind)
{
	if (!nodeStatus[ind] || ind >= pow(2, maxHeight) - 1)
		return;
	cout << data[ind]<<" ";
	preOrderInd(2 * ind + 1);
	preOrderInd(2 * ind + 2);
}
template<typename T>
void BinaryTree<T>::postOrder()
{
	if (maxHeight == 0)
		return;
	postOrderInd(0);
}
template<typename T>
void BinaryTree<T>::postOrderInd(int ind)
{
	if (!nodeStatus[ind] || ind >= pow(2, maxHeight) - 1)
		return;
	postOrderInd(2 * ind + 1);
	postOrderInd(2 * ind + 2);
	cout << data[ind]<<" ";
}
template<typename T>
void BinaryTree<T>::inOrder()
{
	if (maxHeight == 0)
		return;
	inOrderInd(0);
}
template<typename T>
void BinaryTree<T>::inOrderInd(int ind)
{
	if (!nodeStatus[ind] || ind >= pow(2, maxHeight) - 1)
		return;
	postOrderInd(2 * ind + 1);
	cout << data[ind]<<" ";
	postOrderInd(2 * ind + 2);
}

//template<typename T>
//void BinaryTree<T>::displayExplorerView()
//{
//	/*int treeSize = pow(2, maxHeight) - 1;
//	
//	for (int i = 0; i < maxHeight; i++)
//	{
//		for (int j = i; j <= pow(2, i - 1); j++)
//		{
//			if (nodeStatus[j])
//				cout << data[j] << " ";
//		}
//		cout << "\n";
//	}*/
//}
//template<typename T>
//void BinaryTree<T>::displayParenthesizedView()
//{
//	int treeSize = pow(2, maxHeight) - 1;
//	for (int i = 0; i < treeSize; i++)
//	{
//		if (nodeStatus[i])
//			cout << data[i] << "\n";
//	}
//}