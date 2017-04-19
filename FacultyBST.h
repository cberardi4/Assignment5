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
			printNodes(n->left);
			n->value->printFaculty();
			printNodes(n->right);
		}

	}
	//return faculty id that the student was assigned to
	int assignStudentAdvisee(int studID)
	{
		// int facID;
		// int leastAdvisees;
		// TreeNode<Faculty> *n = getRoot();

		// if (n == NULL)
		// 	cout << "No Faculty in database. Add a Faculty Member." << endl;
		// else if (n != NULL)
		// {
		// 	if(n == root)
		// 	{
		// 		leastAdvisees = n->value->countAdvisees();
		// 	}
		// 	while(n->left != NULL)//go all the way left
		// 	{

		// 	}
		
		// }

		// facID = current->getId();

		return 0;
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
	int deleteNode(int id)
	{
		TreeNode<Faculty> *root = getRoot();

		if (root==NULL) //empty tree
			cout << "empty tree"<< endl;

		TreeNode<Faculty> *parent = NULL;
		TreeNode<Faculty> *current = root;
		bool isLeft = true;

		while(current->value->getId() != id)
		{
			parent = current;

			
	        if (id < current->value->getId()) //go left
			{
				isLeft = true;
				current = current->left;
			}
			else //go right
			{
				isLeft = false;
				current = current->right;
			}
			if (current == NULL)
			{
				cout << "ID Wasn't in the Database." << endl;
				return 0;
			}
	    }

			//we found what needs to be deleted

			//no children--leaf node
			if (current->left == NULL && current->right == NULL)
			{
				if (current == root)
				{
					root = NULL;
				}
				else if (isLeft)
				{
					parent->left = NULL;
				}
				else
				{
					parent->right = NULL;
				}
			}

			//only one child on the left
			else if (current->right == NULL) // no right child
			{
				if (current == root)
					root = current->left;
				else if (isLeft)
				{
						parent->left = current->left;
				}
				else
				{
					parent->right = current->left;
				}
			}

			//only one child on the right
			else if (current->left == NULL) // no left child
			{
				if (current == root)
					root = current->right;
				else if (isLeft)
				{
					parent->left = current->right;
				}
				else
				{
					parent->right = current->right;
				}
			}
			
			//2 children nodes
			else
			{
				TreeNode<Faculty>* successor = getSuccessor(current);

				if (current == root)
					root = successor;
				else if (isLeft)
				{
					parent->left = successor;
				}
				else
				{
					parent->right = successor;
				}
	            
				successor->left = current->left;
			}
		int size = getSize();
		setSize(--size);
		return 1;
		
	}

};