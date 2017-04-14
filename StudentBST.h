#include "Student.h"
#include "BST.h"
#include <iostream>

using namespace std;

class StudentBST: public BST<Student>
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

	TreeNode<Student>* find(int id)
	{
		TreeNode<Student> *root = getRoot();
		TreeNode<Student> *current = root;
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