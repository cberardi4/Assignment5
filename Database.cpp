/*#include <stack>
#include "TreeNode.h"
#include "BST.h"
#include "StudentBST.h"
#include "FacultyBST.h"
#include <iostream>
#include <fstream>
#include <string>

#ifndef STUDENT_H
#define STUDENT_H

#ifndef FACULTY_H
#define FACUTLY_H

using namespace std;

//global variables
int response;
StudentBST *students = new StudentBST();
FacultyBST *faculty = new FacultyBST();
int startingStudentId = 1000;
int startingFacultyId = 1;
stack<StudentBST> *studStack = new stack<>();
stack<FacultyBST> *facStack = new stack<>();


//functions
int displayMenu();
void checkFiles();
void printStudents(TreeNode<Student>* root);
void printFaculty(TreeNode<Faculty>* root);
void displayStudent();
void displayFaculty();
void printFacultyAdvisor();
void printAdvisees();
void addStudent();
void deleteStudent();
void addFaculty();
void deleteFaculty();
void changeAdvisor();
void removeAdvisee();
void rollbackStudent();
void rollbackFaculty();
void exitProgram();
void addStudStack();
void addFacStack();


int main(int argv, char** argc)
{
	while(true)
	{
		response = displayMenu();


		TreeNode<Student> *stuRoot;
		TreeNode<Faculty> *teachRoot;


		switch(response)
		{
			case 1:
				stuRoot = students.getRoot();
				printStudents(stuRoot);
				break;
			case 2:
				teachRoot = faculty.getRoot();
				printFaculty(teachRoot);
				break;
			case 3:
				displayStudent();
				break;
			case 4:
				displayFaculty();
				break;
			case 5:
				printFacultyAdvisor();
				break;
			case 6:
				printAdvisees();
				break;
			case 7:
				addStudent();
				break;
			case 8:
				deleteStudent();
				break;
			case 9:
				addFaculty();
				break;
			case 10:
				deleteFaculty();
				break;
			case 11:
				changeAdvisor();
				break;
			case 12:
				removeAdvisee();
				break;
			case 13:
				char r;
				cout << "Would you like to rollback student(s) or faculty(f)" << endl;
				cin >> r;
				while (true)
				{
					if (r == 'f')
					{
						rollbackFaculty();
						break;
					}
					else if (r == 's')
					{
						rollbackStudent();
						break;
					}
					else 
						cout << "Not an option. Try again." << endl;
				}
				break;
			case 14:
				exitProgram();
				break;
			default:
				cout <<"Not a valid option." << endl;
		}
	}
}

void printStudents(TreeNode<Student>* stuRoot)
{
	students.printNodes(stuRoot);
}

void printFaculty(TreeNode<Faculty>* teachRoot)
{
	faculty.printNodes(teachRoot);
}
void displayStudent()
{
	int id;

	TreeNode <Student>* foundStudent = new TreeNode<Student>();

	cout << "ID number of student you would like to display: " << endl;
	cin >> id;

	foundStudent = students.find(id);

	foundStudent->value.printStudent();

}
void displayFaculty()
{
	int id;

	TreeNode <Faculty>* foundFaculty = new TreeNode<Faculty>();

	cout << "ID number of faculty member you would like to display: " << endl;
	cin >> id;

	foundFaculty = faculty.find(id);

	foundFaculty->value.printFaculty();
}
void printFacultyAdvisor(int studID)
{
	//get the student object
	//get their faculty advisors id
	//traverse the faculty tree
	//once found print that faculty member

	//maybe we need a print specific faculty method

}
void printAdvisees(int facID)
{
	//get the faculty object
	//get the list of advisees (id numbers)
	//traverse the student tree for each number, print them as they come up

}
void addStudent()
{
	//save the last bst before we change
	addStudStack();

	//make a new student
	int advisor;
	string name, level, major;
	float gpa; 

	cout << "Name: " << endl;
	cin >> name;
	cout << "Level: " << endl;
	cin >> level;
	cout << "Major: " << endl;
	cin >> major;
	cout << "GPA: " << endl;
	cin >> gpa;
	cout << "Advisor: " << endl;
	cin >> advisor;

	Student newStud(startingStudentId++, name, level, major, gpa, advisor);

	//add it to our tree
	students.insert(newStud);

	//have the advisor id, find it in the database, add the student
	//faculty.find(advisor);

}
void deleteStudent()
{
	//save the last bst
	addStudStack();

	//delete the student
}
void addFaculty()
{
	//save the last bst
	addFacStack();

	//make a new faculty
	string name, level, department;

	cout << "Name: " << endl;
	cin >> name;
	cout << "Level: " << endl;
	cin >> level;
	cout << "Department: " << endl;
	cin >> department;

	Faculty newTeach(startingFacultyId++, name, level, department);

	//add them to the bst
	faculty.insert(newTeach);
}

void deleteFaculty()
{
	//save the bst
	addFacStack();

	//delete the faculty
}
void changeAdvisor()
{
	//save the bst
	addStudStack();

	//get the student
	//get advisor instance
	//switch the advisor
}
void removeAdvisee()
{
	//save the bst
	addFacStack();

	//get the faculty object
	//get the list of advisees
	//find the advisee and delete them
}
void rollbackFaculty()
{
	//get the last saved bst from stack
	faculty = facStack.pop();
}
void rollbackStudent()
{
	//get the last saved bst from stack
	students = studentStack.pop();
}
void exitProgram()
{
	cout << "Exiting program now." << endl;
	exit(0);
}
int displayMenu()
{
	int response;

	cout << "Hello, Welcome to the Database!" << endl;
	cout <<"What would you like to do today?" << endl;
	cout <<"--------------------------------" << endl;
	cout <<" " << endl;
	cout <<"1. Print all students and their information (sorted by ascending id #)" << endl;
	cout <<"2. Print all faculty and their information (sorted by ascending id #)" << endl;
	cout <<"3. Find and display student information given the students id" << endl;
	cout <<"4. Find and display faculty information given the faculty id" << endl;
	cout <<"5. Given a student’s id, print the name and info of their faculty advisor" << endl;
	cout <<"6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
	cout <<"7. Add a new student" << endl;
	cout <<"8. Delete a student given the id" << endl;
	cout <<"9. Add a new faculty member" << endl;
	cout <<"10. Delete a faculty member given the id." << endl;
	cout <<"11. Change a student’s advisor given the student id and the new faculty id." << endl;
	cout <<"12. Remove an advisee from a faculty member given the ids" << endl;
	cout <<"13. Rollback" << endl;
	cout <<"14. Exit" << endl;

	cin >> response;
	cout << " " << endl;

	return response;
}

void addStudStack()
{
	//add a bst to the stack of studentBST
	studStack.push(students);
}
void addFacStack(FacultyBST bst)
{
	//ad a bst to the stack of facultyBST
	facStack.push(faculty);
}
*/
/*
void checkFiles()
{
	ifstream readStudent("studentTable.txt");
	ifstream readFaculty("facultyTable.txt");

	string line;

	//have to read in faculty before students
	//if we want to add a student, need faculty there first
	if(readFaculty.is_open())
	{
		while(!readFaculty.eof())
		{
			string name;
			getLine(readFaculty, name);

			getLine(readFaculty, line);
			int id = atoi(line.c_str());

			string level;
			getLine(readFaculty, faculty);

			string department;
			getline(readFaculty, department);

			Faculty newFaculty(id, name, level, department);
			faculty.insert(newFaculty);

			//getting list of advisees
			getline(readFaculty, line);
			int numAdvisees;

			for (int k=0; k<numAdvisees; ++k)
			{
				getLine(readFaculty, line);
				int stud = atoi(line.c_str());
				faculty.find(newFaculty)->value.addStudent(stud);
			}

			line = "";
		}

	 	readFaculty.close();
	}

	//clear

	if (readStudent.is_open())
	{
		while (!readStudent.eof())
		{
			string name;
			getline(readStudent, name);

			getline(readStudent, line);
			int id = atoi(line.c_str());

			string grade;
			getline(readStudent, grade);

			string major;
			getline(readStudent, major);

			getline(readStudent, line);
			double gpa = atof(line.c_str());

			getline(readStudent, line);
			int advisor = atoi(line.c_str());

			Student newStudent(id, name, grade, major, gpa, advisor);
			students.insert(newStudent);

			line = "";
		}

		readStudent.close();
	}

	//clear
} 
*/

//#endif
//#endif


