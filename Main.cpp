#ifndef STUDENT_H
#define STUDENT_H
#ifndef FACULTY_H
#define FACULTY_H

#include "FacultyBST.h"
#include "StudentBST.h"


#include <fstream>
#include <string>
#include <stack>
#include <iostream>

//global variables
int response;
int startingStudentId = 1000;
int startingFacultyId = 1;
StudentBST *students = new StudentBST();
FacultyBST *faculty = new FacultyBST();

//stack<StudentBST> *studStack = new stack<>();
//stack<FacultyBST> *facStack = new stack<>();


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

#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	checkFiles();
	cout << "Hello, Welcome to the Database!" << endl;
	cout <<"What would you like to do today?" << endl;
	cout <<"--------------------------------" << endl;

	//keep looping untill they quit
	while(true)
	{
		//what to do
		response = displayMenu();
		getchar();

		TreeNode<Student> *stuRoot;
		TreeNode<Faculty> *teachRoot;


		switch(response)
		{
			case 1:
				stuRoot = students->getRoot();
				printStudents(stuRoot);
				break;
			case 2:
				teachRoot = faculty->getRoot();
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

	
		cout << "Press enter to continue. ";
		getchar();

	}
}
int displayMenu()
{
	int response;

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

void printStudents(TreeNode<Student>* stuRoot)
{
	students->printNodes(stuRoot);
}

void printFaculty(TreeNode<Faculty>* teachRoot)
{
	faculty->printNodes(teachRoot);
}
void displayStudent()
{
	int id;

	TreeNode<Student>* foundStudent = new TreeNode<Student>();

	cout << "ID number of Student you would like to display: " << endl;
	cin >> id;

	foundStudent = students->find(id);

	foundStudent->value->printStudent();

}
void displayFaculty()
{
	int id;

	TreeNode <Faculty>* foundFaculty = new TreeNode<Faculty>();

	cout << "ID number of Faculty member you would like to display: " << endl;
	cin >> id;

	foundFaculty = faculty->find(id);

	foundFaculty->value->printFaculty();
}
void printFacultyAdvisor()
{
	int studID;
	bool isValid = true;
	while(isValid)
	{
		string input;
		cout << "Enter Student ID: " << endl;
		cin >> input;
		studID = atoi(input.c_str());
		if(studID != 0)
		{
			isValid = false;
		}
		else
			cout << "Not Valid ID" << endl;
	}
	
	//get the student object
	TreeNode<Student>* foundStudent = new TreeNode<Student>();
	foundStudent = students->find(studID);
	//get their faculty advisors id
	int facId = (foundStudent->value)->getAdvisor();
	//traverse the faculty tree
	TreeNode<Faculty>* foundFaculty = new TreeNode<Faculty>();
	foundFaculty = faculty->find(facId);
	//once found print that faculty member
	(foundFaculty->value)->printFaculty();
	

}
void printAdvisees()
{
	//get the faculty object
	//get the list of advisees (id numbers)
	//traverse the student tree for each number, print them as they come up
	cout << "" << endl;
}
void addStudent()
{
	//save the last bst before we change
	//addStudStack();

	//make a new student
	int advisor;
	string name, level, major;
	float gpa; 

	cout << "Name: " << endl;
	cin.ignore();
	getline(cin, name, '\n');
	cout << "Level: " << endl;
	cin >> level;
	cout << "Major: " << endl;
	getline(cin, major, '\n');
	cin >> major;
	cout << "GPA: " << endl;
	cin >> gpa;

	


	Student *newStud = new Student(startingStudentId++, name, level, major, gpa, advisor);

	//add it to our tree
	students->insert(newStud);

	//have the advisor id, find it in the database, add the student
	//faculty.find(advisor);

}
void deleteStudent()
{
	//save the last bst
	//addStudStack();


	//delete the student
	int id;
	string input;
	while(true)
	{
		cout << "Enter ID of Student you want to delete: " << endl;
		cin >> input;
		id = atoi(input.c_str());
		if(id == 0)
		{
			cout << "Not valid student ID. " << endl;
			continue;
		}

		//if cant find student with that id, prompt again and say no such student
		int success = students->deleteNode(id);
		if(success == 1)
		{
			cout << "Successfully deleted Student: " << id << endl;
			break;
		}
	}
	
}
void addFaculty()
{
	//save the last bst
	//addFacStack();

	//make a new faculty
	string name, level, department;

	cout << "Name: " << endl;
	cin.ignore();
	getline(cin, name, '\n');
	cout << "Level: " << endl;
	getline(cin, level, '\n');
	cout << "Department: " << endl;
	getline(cin, department, '\n');

	Faculty *newTeach = new Faculty(startingFacultyId++, name, level, department);

	//add them to the bst
	faculty->insert(newTeach);
}

void deleteFaculty()
{
	//save the bst
	//addFacStack();

	//delete the faculty
	int id;
	string input;
	while(true)
	{
		cout << "Enter ID of Faculty you want to delete: " << endl;
		cin >> input;
		id = atoi(input.c_str());
		if(id == 0)
		{
			cout << "Not valid student ID. " << endl;
			continue;
		}

		//if cant find student with that id, prompt again and say no such student
		int success = faculty->deleteNode(id);
		if(success == 1)
		{
			cout << "Successfully deleted Faculty: " << id << endl;
			break;
		}
	}
}
void changeAdvisor()
{
	//save the bst
	//addStudStack();

	//get the student
	//get advisor instance
	//switch the advisor
}
void removeAdvisee()
{
	//save the bst
	//addFacStack();

	//get the faculty object
	//get the list of advisees
	//find the advisee and delete them
}
void rollbackFaculty()
{
	//get the last saved bst from stack
	//faculty = facStack->pop();
}
void rollbackStudent()
{
	//get the last saved bst from stack
	//students = studentStack->pop();
}
void exitProgram()
{
	cout << "Exiting program now." << endl;
	exit(0);
}


void addStudStack()
{
	//add a bst to the stack of studentBST
	//studStack->push(students);
}
void addFacStack(FacultyBST bst)
{
	//ad a bst to the stack of facultyBST
	//facStack->push(faculty);
}


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
			getline(readFaculty, name);

			getline(readFaculty, line);
			int id = atoi(line.c_str());

			string level;
			getline(readFaculty, level);

			string department;
			getline(readFaculty, department);

			Faculty *newFaculty = new Faculty(id, name, level, department);
			faculty->insert(newFaculty);

			//getting list of advisees
			getline(readFaculty, line);
			int numAdvisees;

			for (int k=0; k<numAdvisees; ++k)
			{
				getline(readFaculty, line);
				int stud = atoi(line.c_str());
				//faculty->find(newFaculty->getId())->value->addStudent(stud);
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

			if(name == " ")
			{
				break;
			}
			//getline(readStudent, line);
			//int id = atoi(line.c_str());

			string grade;
			getline(readStudent, grade);

			string major;
			getline(readStudent, major);

			getline(readStudent, line);
			double gpa = atof(line.c_str());

			getline(readStudent, line);
			int advisor = atoi(line.c_str());

			Student *newStudent = new Student(startingStudentId++, name, grade, major, gpa, advisor);

			students->insert(newStudent);
			

			line = "";
		}


		readStudent.clear();
		readStudent.close();
	}

	//clear
} 



//#endif
#endif
#endif