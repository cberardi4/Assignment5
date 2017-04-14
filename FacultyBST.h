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
		if (n != NULL)
		{
			printNodes(n->left);
			n->value.printFaculty();
			printNodes(n->right);
		}

	}

	TreeNode<Faculty>* find(int id)
	{
		TreeNode<Faculty> *root = getRoot();
		TreeNode<Faculty> *current = getRoot();
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