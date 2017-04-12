/*
#include <iostream>
#include "TreeNode.h"
#include "BST.h"
#include "Student.h"
#include "Teacher.h"

using namespace std;

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
void rollback();
void exitProgram();

int main(int argv, char** argc)
{

	int response;
	BST<Student> *students = new BST<Student>();
	BST<Teacher> *faculty = new BST<Teacher>();
	bool isNew = true; //to see if we have existing trees

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

	TreeNode<E> *root;


	switch(response):
		case 1:
			root = students->getRoot();
			printStudents(root);
			break;
		case 2:
			printFaculty();
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

void printStudents(TreeNode<Student>* root)
{
	students->printAllStudents(root);
}

void printFaculty();
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

*/





