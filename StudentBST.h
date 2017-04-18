#include <iostream>

#include "Student.h"
#include "BST.h"
#include <string>

using namespace std;

class StudentBST: public BST<Student>
{
public:
	void printNodes(TreeNode<Student> *n)
	{
		if (n == NULL)
			cout << " " << endl;
		else if (n != NULL)
		{
			printNodes(n->right);
			n->value->printStudent();
			printNodes(n->left);
		}

	}
	TreeNode<Student>* find(int id)
	{
		TreeNode<Student> *root = getRoot();
		TreeNode<Student> *current = root;
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