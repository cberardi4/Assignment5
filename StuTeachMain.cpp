// #ifndef STUDENT_H
// #define STUDENT_H
// #ifndef FACULTY_H
// #define FACULTY_H

// #include "FacultyBST.h"
// #include "StudentBST.h"

// #include <iostream>
// using namespace std;

// int main(int argc, char** argv)
// {
// 	Student *st = new Student(34, "Jack", "soph", "CS", 3.5, 1245);
// 	Faculty *fac = new Faculty(1245, "Tina", "assistant", "Engineering");
// 	Student *st2 = new Student(35, "Monica", "junior", "Math", 3.4, 2902);
// 	Student *st3 = new Student(36, "Jimmy", "senior", "English", 4.0, 2902);
// 	Faculty *fac2 = new Faculty(2902, "Harry", "professor", "Art");
// 	//st->printStudent();
// 	//st2->printStudent();

// 	//fac->printFaculty();

// 	StudentBST *studBST = new StudentBST();
// 	FacultyBST *facBST = new FacultyBST();


// 	studBST->insert(st);
// 	studBST->insert(st2);
// 	studBST->insert(st3);
// 	facBST->insert(fac);
// 	facBST->insert(fac2);

// 	studBST->printNodes(studBST->getRoot());
// 	facBST->printNodes(facBST->getRoot());

	
// 	Student* stud = (studBST->find(st3->getId()))->value;
// 	cout << stud->getName() << endl;

// 	Faculty* facul = (facBST->find(fac2->getId()))->value;
// 	cout << facul->getName() << endl;


// 	return 0;
// }

// #endif
// #endif
