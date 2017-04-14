#include <iostream>

using namespace std;

template<class E>
class TreeNode
{
public:
	TreeNode();
	TreeNode(E value);

	virtual ~TreeNode();

	void setValue(E *newValue);

	E value;

	TreeNode<E> *left;
	TreeNode<E> *right;
};

template<class E>
TreeNode<E>::TreeNode()
{
	left = NULL;
	right = NULL;
}

template<class E>
TreeNode<E>::TreeNode(E v)
{
	left = NULL;
	right = NULL;
	value = v;
}

template<class E>
TreeNode<E>::~TreeNode()
{
	left = NULL;
	right = NULL;
}

template<class E>
void TreeNode<E>::setValue(E *newValue)
{
	value = newValue;
}