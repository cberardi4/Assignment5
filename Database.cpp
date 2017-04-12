
#include "TreeNode.h"
#include "BST.h"
#include "Student.h"
#include "Teacher.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//global variables
int response;
BST<Student> students;
BST<Teacher> faculty;
int startingStudentId = 1000;
int startingTeacherId = 1;


//functions
int displayMenu();
//void checkFiles();
void printStudents(TreeNode<Student>* root);
void printFaculty(TreeNode<Teacher>* root);
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
void rollback();
void exitProgram();

int main(int argv, char** argc)
{

	response = displayMenu();


	TreeNode<Student> *stuRoot;
	TreeNode<Teacher> *teachRoot;


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
			rollback();
			break;
		case 14:
			exitProgram();
			break;
		default:
			cout <<"Not a valid option." << endl;
	}

}

void printStudents(TreeNode<Student>* root)
{
	students.printAllStudents(root);
}

void printFaculty();
void displayStudent();
void displayFaculty();
void printFacultyAdvisor();
void printAdvisees();
void addStudent()
{
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

	Student *newStud = new Student(startingStudentId++, name, level, major, gpa, advisor);

	students.insert(newStud);
	//faculty.find(advisor);

}
void deleteStudent();
void addFaculty()
{
	string name, level, department;

	cout << "Name: " << endl;
	cin >> name;
	cout << "Level: " << endl;
	cin >> level;
	cout << "Department: " << endl;
	cin >> department;

	Teacher *newTeach = new Teacher(startingTeacherId++, name, level, department);

	students.insert(newStud);
}

void deleteFaculty();
void changeAdvisor();
void removeAdvisee();
void rollback();
void exitProgram();
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

	cin >> response >> endl;

	return response;
}
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

			Teacher newTeacher(id, name, level, department);
			faculty.insert(newTeacher);

			//getting list of advisees
			getline(readFaculty, line);
			int numAdvisees;

			for (int k=0; k<numAdvisees; ++k)
			{
				getLine(readFaculty, line);
				int stud = atoi(line.c_str());
				faculty.find(newTeacher)->value.addStudent(stud);
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




