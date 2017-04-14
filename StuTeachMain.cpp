
#include "FacultyBST.h"
#include "StudentBST.h"
#include "Teacher.h"
#include "Student.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{

	Student *st = new Student(34, "Jack", "soph", "CS", 3.5, 1245);
	Faculty *fac = new Faculty(1245, "Tina", "assistant", "Engineering");
	st->printStudent();
	fac->printFaculty();


	StudentBST<Student> *studBST = new StudentBST<Student>();
	FacultyBST<Faculty> *facBST = new FacultyBST<Faculty>();

	studBST->printNodes(st);
	facBST->printNodes(fac);


	return 0;
}
