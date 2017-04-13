#include "Student.h"
#include "BST.h"
#include <iostream>

using namespace std;

template<Student>
class StudentBST<Student>: public BST<class E>
{
public:
	void printNodes(TreeNode<Student> *n)
	{
		if (n != NULL)
		{
			printNodes(n->left);
			n->value.printStudent();
			printNodes(n->right);
		}

	}
	
};