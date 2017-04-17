#ifndef STUDENT_H
#define STUDENT_H
#ifndef FACULTY_H
#define FACULTY_H

#include "FacultyBST.h"
#include "StudentBST.h"

#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	Student *st = new Student(34, "Jack", "soph", "CS", 3.5, 1245);
	Faculty *fac = new Faculty(1245, "Tina", "assistant", "Engineering");
	st->printStudent();
	fac->printFaculty();

	StudentBST *studBST = new StudentBST();
	FacultyBST *facBST = new FacultyBST();


	studBST->insert(st);
	facBST->insert(fac);


	//studBST->printNodes(studBST->getRoot());
	//facBST->printNodes(facBST->getRoot());


	return 0;
}

#endif
#endif
