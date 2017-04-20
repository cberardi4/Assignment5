#include <iostream>
#include <fstream>
#include "Student.h"
#include "BST.h"
#include <string>

using namespace std;

class StudentBST: public BST<Student>
{
public:
	void printNodes(TreeNode<Student> *n)
	{
		if(n != NULL)
		{
			printNodes(n->left);
			n->value->printStudent();
			printNodes(n->right);
		}

	}
	void printStudToFile(TreeNode<Student> *n, ofstream &file)
	{
		if(n != NULL)
		{
			printStudToFile(n->left, file);
			file <<  n->value->getId() << endl;
			file <<  n->value->getName() << endl;
			file << n->value->getMajor() << endl;
			file <<  n->value->getGpa() << endl;
			file << n->value->getAdvisor() << endl;
			printStudToFile(n->right, file);
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

	int deleteNode(int id)
	{
		TreeNode<Student> *root = getRoot();
		if (root==NULL) //empty tree
			cout << "empty tree"<< endl;

		TreeNode<Student> *parent = NULL;
		TreeNode<Student> *current = root;
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
					setRoot(NULL);
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
				TreeNode<Student>* successor = getSuccessor(current);

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