
#include "TreeNode.h"
#include "Student.h"
#include "BST.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	BST<Student> *tree = new BST<Student>();

	Student *stud = new Student(22222, "Maddy", "Soph", 1.0 , 4444);

	int empty = tree->isEmpty();
	tree->insert(stud);
	

	TreeNode<Student> *n = new TreeNode<Student>();
	n = tree->getRoot();
	tree->printNodes(n);

	
	tree->deleteNode(stud);
	cout << tree->contains(stud) << endl;
	n = tree->getRoot();
	//cout << "n->left in main "<<n->left->value << endl;
	//cout <<"n->right in main" <<n->right<< endl;
	tree->printNodes(n);
	
/*
	TreeNode<int> *min = new TreeNode<int>();
	TreeNode<int> *max = new TreeNode<int>();
	max=tree->getMax();
	min = tree->getMin();
	cout << "min:" << min->value<< endl;
	cout <<"max: " << max->value << endl;
	empty = tree->isEmpty();
	cout << "is empty" << empty << endl;

*/




	return 1;
}