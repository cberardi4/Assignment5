#include "Student.h"
#include <iostream>

using namespace std;
class StudentBST:public BST
{
public:

	void printNodes(Student *rootStudent)
	{
		if (rootStudent != NULL)
		{
			printNodes(rootStudent->left);
			rootStudent->printStudent();
			printNodes(rootStudent->right);
		}
	}
	
};