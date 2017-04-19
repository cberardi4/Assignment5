#include <iostream>
#include "Faculty.h"
#include "TreeNode.h"
#include "BST.h"

using namespace std;

class FacultyBST : public BST<Faculty>
{
public:
	void printNodes(TreeNode<Faculty> *n)
	{
		if (n == NULL)
			cout << " " << endl;
		else if (n != NULL)
		{
			printNodes(n->right);
			n->value->printFaculty();
			printNodes(n->left);
		}

	}

	TreeNode<Faculty>* find(int id)
	{
		TreeNode<Faculty> *root = getRoot();
		TreeNode<Faculty> *current = root;
		int currentId;

		//start at root check left or right keep searching till found or leaf
		if (current == NULL)
		{
			return NULL;
		}
		else
		{

			while(currentId != id)
			{
				currentId = current->value->getId();
				if (id < currentId) //go left
				{
					current = current->left;
				}
				else if (id > currentId)//go right
				{
					
					current = current->right;
					
				}
				if (current == NULL)
				{
					break;
				}
			}
			
		}
		return current;

	}
};