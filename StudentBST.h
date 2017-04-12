#include "Student.h"
#include <iostream>

using namespace std;
class StudentBST:public StudentBST
{
public:
	void printNodes(Student *stud)
	{
		if (stud != NULL)
		{
			cout << stud->printStudent() << endl;
			printNodes(stud->left);
			printNodes(stud->right);
		}
	}

	
private:


}