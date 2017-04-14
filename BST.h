#ifndef TREENODE_H
#define TREENODE_H
//___________________________________
//
//DECLARATION
//___________________________________
using namespace std;
#include <iostream>

using namespace std;

template <class E>
class BST
{
public:
	BST();
	~BST();

	virtual void insert(E value);
	bool contains(E value);
	void deleteNode(E value);
	TreeNode<E>* getRoot();
	virtual TreeNode<E>* find(E* value);

	bool isEmpty();
	TreeNode<E>* getMin(); //leftmost
	TreeNode<E>* getMax(); //rightmost
	int getSize();

	TreeNode<E>* getSuccessor(TreeNode<E>* n); //helper function for delete method
	virtual void printNodes(TreeNode<E> *n);

private:
	TreeNode<E> *root;
	int size;
};

//___________________________________
//
//IMPLEMENTATION
//___________________________________

template <class E>
BST<E>::BST()
{
	root = NULL;
	size = 0;
}
template <class E>
BST<E>::~BST()
{
	//iterate and delete
	//linear big o
}
template <class E>
void BST<E>::printNodes(TreeNode<E> *n)
{
	if (n != NULL)
	{
		printNodes(n->left);
		cout << n->value << endl;
		printNodes(n->right);
	}
}
template <class E>
TreeNode<E>* BST<E>::getMax()
{	
	TreeNode<E> *current = root;
	
	if (root == NULL)
		return NULL;

	while (current->right != NULL)
	{
		current = current->right;
	}

	return current;
}
template <class E>
TreeNode<E>* BST<E>::getMin()
{	
	TreeNode<E> *current = root;
	
	if (root == NULL)
		return NULL;

	while (current->left != NULL)
	{
		current = current->left;
	}

	return current;
}
template <class E>
void BST<E>::insert(E value)
{
	TreeNode<E> *node = new TreeNode<E>(value);

	if (root == NULL) //empty tree
	{
		root = node;
	}

	else
	{
		TreeNode<E> *current = root; //start at the root
		TreeNode<E> *parent;
		
		while(true)
		{
			parent = current;

			//go left
			if (value < current->value)
			{
				current = current->left;
				if (current == NULL) //found our position
				{
					parent->left = node;
					++size;
					break;
				}
			}
			else //go right
			{
				current = current->right;
				if (current == NULL) //found our position
				{
					parent->right = node;
					++size;
					break;
				}
				
			}
		}
	}
}
template <class E>
bool BST<E>::contains(E value)
{
	if (root == NULL)
	{
		return false;
	}
	else
	{
		TreeNode<E> *current = root;

		while(current->value != value)
		{
			if (value < current->value) //go left
			{
				current = current->left;
			}
			else //go right
			{
				current = current->right;
			}
			if (current == NULL)
			{
				return false;
			}
		}
	}
	return true;
}
template <class E>
void BST<E>::deleteNode(E value)
{
	if (root==NULL) //empty tree
		cout << "empty tree"<< endl;

	TreeNode<E> *parent = NULL;
	TreeNode<E> *current = root;
	bool isLeft = true;

	while(current->value != value)
	{
		parent = current;

		
        if (value < current->value) //go left
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
			cout << "Wasn't in the tree" << endl;
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
			TreeNode<E>* successor = getSuccessor(current);

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
	--size;
	
}


template<class E>
TreeNode<E> *BST<E>::getSuccessor(TreeNode<E> *n)
{
    TreeNode<E> *successorParent = n;
    TreeNode<E> *successor = n; //one right all the way left
    TreeNode<E> *current = n->right;
    while (current != NULL)
    {
        successorParent = successor;
        successor = current;

        current = current->left;
    }

    if (successor != n->right)//if successor is below the nodes right, so it wasnt the first node under it
    {
        successorParent->left = successor->right;
        successor->right = n->right;
    }
    return successor;
    
}

template<class E>
TreeNode<E>* BST<E>::getRoot()
{
	return root;
}

template<class E>
bool BST<E>::isEmpty()
{
	return (root == NULL);
}
template<class E>
int BST<E>::getSize()
{
	return size;
}


template<class E>
TreeNode<E>* BST<E>::find(E *value)
{
	TreeNode<E> *current = root;

	//start at root check left or right keep searching till found or leaf
	if (root == NULL)
	{
		return NULL;
	}
	else
	{
		while(current->value != value)
		{
			if (value < current->value) //go left
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
#endif

