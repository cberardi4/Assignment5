#include <iostream>
#include "Faculty.h"
#include "TreeNode.h"
#include "BST.h"

using namespace std;

class FacultyBST:public BST<Faculty>
{
public:
	void printNodes(TreeNode<Faculty> *n)
	{
		Faculty *fac = n->value;
		if (n != NULL)
		{
			printNodes(n->left);
			fac->printFaculty();
			printNodes(n->right);
		}

	}

	TreeNode<Faculty>* find(int id)
	{
		TreeNode<Faculty> *root = getRoot();
		TreeNode<Faculty> *current = getRoot();
		int currentId = current->value->getId();

		//start at root check left or right keep searching till found or leaf
		if (current == NULL)
		{
			return NULL;
		}
		else
		{
			while(currentId != id)
			{
				if (id < currentId) //go right
				{
					current = current->right;
				}
				else //go left
				{
					current = current->left;
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