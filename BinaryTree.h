#ifndef BINARY_TREE_H
#define BINARY_TREE_H
template<typename T>
class BinaryTree
{
	int maxHeight;
	T* data;
	bool* nodeStatus;
	int searchNodeInd(T parent);
	void preOrderInd(int ind);
	void postOrderInd(int ind);
	void inOrderInd(int ind);
public:
	BinaryTree(int h);
	void setRoot(T v);
	T getRoot();
	void setLeftChild(T parent, T child);
	void setRightChild(T parent, T child);
	T getParent(T node);
	void remove(T node);
	void displayAncestors(T node);
	void displaDescendents(T node);
	int HeightOfTree();
	void displayLevel(int levelNo);
	int findLevelOfNode(T node);
	void preOrder();
	void levelOrder();
	void postOrder();
	void inOrder();
	/*
	void displayExplorerView();
	void displayParenthesizedView();
	*/
};
#endif // !BINARY_TREE_H
