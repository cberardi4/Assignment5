#include "TreeNode.h"
#include "BST.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	BST<int> *tree = new BST<int>();

	int empty = tree->isEmpty();
	tree->insert(5);
	tree->insert(7);
	tree->insert(4);
	tree->insert(3);

	TreeNode<int> *n = new TreeNode<int>();
	n = tree->getRoot();
	tree->printNodes(n);

	
	tree->deleteNode(4);
	cout << tree->contains(4) << endl;
	n = tree->getRoot();
	//cout << "n->left in main "<<n->left->value << endl;
	//cout <<"n->right in main" <<n->right<< endl;
	tree->printNodes(n);
	

	TreeNode<int> *min = new TreeNode<int>();
	TreeNode<int> *max = new TreeNode<int>();
	max=tree->getMax();
	min = tree->getMin();
	cout << "min:" << min->value<< endl;
	cout <<"max: " << max->value << endl;
	empty = tree->isEmpty();
	cout << "is empty" << empty << endl;

	return 1;
}
