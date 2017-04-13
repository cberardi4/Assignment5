/*
#include "TreeNode.h"
#include "BST.h"
#include "StudentBST.h"
#include <iostream>

#ifndef STUDENT_BST
#define STUDENT_BST

#ifndef STUDENT_H
#define STUDENT_H


using namespace std;

int main(int argc, char** argv)
{
	*/
	/*
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
	

	TreeNode<int> *min = new TreeNode<int>();
	TreeNode<int> *max = new TreeNode<int>();
	max=tree->getMax();
	min = tree->getMin();
	cout << "min:" << min->value<< endl;
	cout <<"max: " << max->value << endl;
	empty = tree->isEmpty();
	cout << "is empty" << empty << endl;

*/
/*
	Student *st1 = new Student(1, "Tina", "Soph","CS", 4.0, 12);
	Student *st2 = new Student(2, "Jack", "Junior","Math", 3.0, 12);
	Student *st3 = new Student(3, "Liz", "Freshman","English", 3.4, 12);

	StudentBST<Student> *stuBST = new StudentBST<Student>();

	stuBST->insert(st1);
	stuBST->insert(st2);
	stuBST->insert(st3);

	TreeNode<Student> *n = new TreeNode<Student>();
	n = stuBST->getRoot();

	stuBST->printNodes(n);





	return 1;
}

#endif
#endif
*/
