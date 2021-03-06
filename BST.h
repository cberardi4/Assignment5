#ifndef TREENODE_H
#define TREENODE_H

using namespace std;
#include <iostream>

using namespace std;

template <typename E>
class BST
{
public:
	BST();
	~BST();

	virtual void insert(E *v);
	bool contains(E *v);
	virtual int deleteNode(E *value);
	TreeNode<E>* getRoot();
	void setRoot(TreeNode<E>* r);
	virtual TreeNode<E>* find(E *v);

	bool isEmpty();
	TreeNode<E>* getMin(); //leftmost
	TreeNode<E>* getMax(); //rightmost
	int getSize();
	void setSize(int s);

	TreeNode<E>* getSuccessor(TreeNode<E>* n); //helper function for delete method
	virtual void printNodes(TreeNode<E>* n);

private:
	TreeNode<E> *root;
	int size;
};

template <typename E>
BST<E>::BST()
{
	root = NULL;
	size = 0;
}
template <typename E>
BST<E>::~BST()
{
	//iterate and delete
	//linear big o
}
template <typename E>
void BST<E>::printNodes(TreeNode<E>* n)
{
		
}
template <typename E>
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
template <typename E>
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
template <typename E>
void BST<E>::insert(E *v)
{
	TreeNode<E> *node = new TreeNode<E>(v);

	if (root == NULL) //empty tree
	{
		root = node;
		++size;
	}

	else
	{
		TreeNode<E> *current = root; //start at the root
		TreeNode<E> *parent;
		
		while(true)
		{
			parent = current;

			//go left
			if (v->getId() < current->value->getId())
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
template <typename E>
bool BST<E>::contains(E *v)
{
	if (root == NULL)
	{
		return false;
	}
	else
	{
		TreeNode<E> *current = root;

		while(current->value != v)
		{
			if (v < current->value) //go left
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
template <typename E>
int BST<E>::deleteNode(E* value)
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
	return 1;
	
}


template<typename E>
TreeNode<E>* BST<E>::getSuccessor(TreeNode<E>* n)
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

template<typename E>
TreeNode<E>* BST<E>::getRoot()
{
	return root;
}
template<typename E>
void BST<E>::setRoot(TreeNode<E>* r)
{
	root = r;
}

template<typename E>
bool BST<E>::isEmpty()
{
	return (root == NULL);
}
template<typename E>
int BST<E>::getSize()
{
	return size;
}
template<typename E>
void BST<E>::setSize(int s)
{
	size = s;
}



template<typename E>
TreeNode<E>* BST<E>::find(E *v)
{
	return NULL;
}


#endif


