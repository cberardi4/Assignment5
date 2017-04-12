#include "Student.h"
#include <iostream>

using namespace std;
class StudentBST:public BST
{
public:

	void printNodes(Student *stud)
	{
		if (stud != NULL)
		{
			printNodes(stud->left);
			stud->printStudent();
			printNodes(stud->right);
		}
	}
	
};