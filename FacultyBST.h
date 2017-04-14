#include <iostream>
#include "Teacher.h"

using namespace std;

class FacultyBST:public BST<Teacher>
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

	TreeNode<Teacher>* find(int id)
	{
		TreeNode<Teacher> *root = getRoot();
		TreeNode<Teacher> *current = getRoot();
		int currentId = current->value.getId();

		//start at root check left or right keep searching till found or leaf
		if (current == NULL)
		{
			return NULL;
		}
		else
		{
			while(currentId != id)
			{
				if (id < currentId) //go left
				{
					current = current->left;
				}
				else //go right
				{
					current = current->right;
				}
				if (current == NULL)
				{
					return NULL;
				}
			}
	}
	return current;

	}


};