#include "Student.h"
#include "BST.h"
#include <iostream>

using namespace std;

template<Student>
class StudentBST<Student>: public BST<class E>
{
public:
<<<<<<< HEAD

	void printNodes(Student *rootStudent)
	{
		if (rootStudent != NULL)
		{
			printNodes(rootStudent->left);
			rootStudent->printStudent();
			printNodes(rootStudent->right);
=======
	void printNodes(TreeNode<Student> *n)
	{
		if (n != NULL)
		{
			printNodes(n->left);
			n->value.printStudent();
			printNodes(n->right);
>>>>>>> origin/master
		}

	}
	
};