#include <iostream>
#include "Teacher.h"

using namespace std;

template<Teacher>
class FacultyBST:public BST
{
public:
	void printNodes(TreeNode<Teacher> *n)
	{
		if (n != NULL)
		{
			printNodes(n->left);
			n->value.printTeacher();
			printNodes(n->right);
		}

	}


};