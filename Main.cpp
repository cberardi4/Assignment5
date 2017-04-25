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
#include <list>

//global variables
int response;
int startingStudentId = 1000;
int startingFacultyId = 1;
StudentBST *students = new StudentBST();
FacultyBST *faculty = new FacultyBST();

stack<StudentBST> studStack;
stack<FacultyBST> facStack;


//functions
int displayMenu();
void checkFiles();
void writeToFiles();
void printStudents(TreeNode<Student>* root);
void printFaculty(TreeNode<Faculty>* root);
void displayStudent();
void displayFaculty();
void printFacultyAdvisor();
void printAdvisees();
int assignStudAdvisor();
void addStudent();
void deleteStudent();
void addFaculty();
void deleteFaculty();
void removeAdvisee();
void changeAdvisor();
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
	//addStudStack();
	//addFacStack();

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
				//cant only revert student/fac because changes affect both. ie changing advisor adds to faculty and students
				cout << "Would you like to rollback to the last Databse version? (y/n)" << endl;
				cin >> r;
				while (true)
				{
					if (r == 'y' || r == 'Y')
					{
						rollbackFaculty();
						rollbackStudent();
						break;
					}
					else if (r == 'n' || r == 'N')
					{
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
	cout << "Students: " << endl;
	if(students->empty())
		cout << "No Students in Database." << endl;
	students->printNodes(stuRoot);
}

void printFaculty(TreeNode<Faculty>* teachRoot)
{
	cout << "Faculty: " << endl;
	if(faculty->empty())
		cout << "No Faculty in Database." << endl;
	faculty->printNodes(teachRoot);
}
void displayStudent()
{
	int id;

	TreeNode<Student>* foundStudent = new TreeNode<Student>();

	cout << "ID number of Student you would like to display: " << endl;
	cin >> id;

	foundStudent = students->find(id);
	if(foundStudent != NULL)
		foundStudent->value->printStudent();
	else 
		cout << "Student " << id << " does not exist in Databse." << endl;

}
void displayFaculty()
{
	int id;

	TreeNode <Faculty>* foundFaculty = new TreeNode<Faculty>();

	cout << "ID number of Faculty member you would like to display: " << endl;
	cin >> id;

	foundFaculty = faculty->find(id);

	if(foundFaculty != NULL)
		foundFaculty->value->printFaculty();
	else 
		cout << "Faculty " << id << " does not exist in Databse." << endl;
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
	if(foundStudent != NULL)
	{
		cout << "Student " << studID << "'s Advisor: " << endl;
		//get their faculty advisors id
		int facId = (foundStudent->value)->getAdvisor();
		//traverse the faculty tree
		TreeNode<Faculty>* foundFaculty = new TreeNode<Faculty>();
		foundFaculty = faculty->find(facId);
		//once found print that faculty member
		(foundFaculty->value)->printFaculty();	
	}
	else
		cout << "Student not found." << endl;
	

}

void printAdvisees()
{

	//get the faculty object
	int facID;
	bool isValid = true;
	while(isValid)
	{
		string input;
		cout << "Enter Faculty ID: " << endl;
		cin >> input;
		facID = atoi(input.c_str());
		if(facID != 0)
		{
			isValid = false;
		}
		else
			cout << "Not Valid ID" << endl;
	}
	TreeNode<Faculty>* foundFaculty = new TreeNode<Faculty>();
	foundFaculty = faculty->find(facID);
	if(foundFaculty != NULL)
	{
		cout << "Faculty " << facID << "'s Advisees: " << endl;
		//get the list of advisees (id numbers)
		list<int>* advisees = foundFaculty->value->getAdvisees();
		for(int i : *advisees)
		{
			//traverse the student tree for each number, print them as they come up
			students->find(i)->value->printStudent();
		}
		if(advisees->size() == 0)
			cout << "No Advisees. " << endl;
		
	}
	else
		cout << "Faculty Member not found." << endl;
	
}
int assignStudAdvisor()
{
	//save the bst
	addFacStack();
	addStudStack();

	//check if there are advisors
	
	if(faculty->getSize() == 0)
	{
		cout << "No Faculty Members. Add Faculty in order to assign Advisor." << endl;
		
	}
	else if(faculty->getSize() == 1)
	{
		//there is only one faculty member, so just assign the student to them
		return faculty->getRoot()->value->getId();
	}
	else if(faculty->getSize() > 1)
	{
		//generate random number for the faculty id
		//make sure it is in between starting num and max size
		int start = 1;
		int end = faculty->getSize();

		int r = (end - start) + 1;
		
		srand(time(NULL));
		int id = start + rand() % r;

		return id;

	}
	return -1;
	
}
void addStudent()
{
	//save the bst
	addFacStack();
	addStudStack();

	//make a new student
	int advisor;
	string name, level, major;
	float gpa; 
	advisor = assignStudAdvisor();
	if(advisor != -1)
	{

		cout << "Name: " << endl;
		getline(cin, name, '\n');
		cout << "Level: " << endl;
		cin >> level;
		cout << "Major: " << endl;
		getline(cin, major, '\n');
		cin >> major;
		cout << "GPA: " << endl;
		cin >> gpa;

		int id = startingStudentId++;
		TreeNode<Student> *exists = students->find(id);
		while(exists != NULL)
		{
			id = startingStudentId++;
			TreeNode<Student> *exists = students->find(id);
		}

	

		Student *newStud = new Student(id, name, level, major, gpa, advisor);

		//add it to our tree
		students->insert(newStud);

		//add the advisee to the faculty member
		Faculty *ad = faculty->find(advisor)->value;
		ad->addStudent(id);
	}

}
void removeAdvisee()
{
	//save the bst
	addFacStack();
	addStudStack();

	if(faculty->getSize() != 0)
	{
		string advInput, studInput;
		int advID, studID;
		
		while(true)
		{
			cout << "Enter Advisor ID: " << endl;
			cout << "Enter 0 to quit" << endl;
			cin >> advInput;
			cout << "Enter ID of Advisee to remove from list: " << endl;
			cout << "Enter 0 to quit" << endl;
			cin >> studInput;
			advID = atoi(advInput.c_str());
			studID = atoi(studInput.c_str());
			if(advID == 0 || studID == 0)
			{
				break;
			}

			if(faculty->find(advID) == NULL)
			{
				cout << "Not a valid faculty ID. Try again." << endl;
				continue;
			}
			
			if(students->find(studID) == NULL)
			{
				cout << "Not valid student ID. Try again." << endl;
				continue;
			}
					
			//bst->facultyNode->faculty->removeStudent
			faculty->find(advID)->value->removeAdvisee(studID);

			int newid;
			while(true)
			{
				//reassign students advisor
				int start = 1;
				int end = faculty->getSize();

				int r = (end - start) + 1;
				
				srand(time(NULL));
				newid = start + rand() % r;
				if(newid != advID)
				{
					break;
				}
				
			}
			//update student advisor
			students->find(studID)->value->setAdvisor(newid);
			//update advior's list
			faculty->find(newid)->value->addStudent(studID);
			


			cout << "Successfully removed Student: " << studID << " from " << advID << "'s list." << endl;
			break;
			
		}

	}
	else if(faculty->getSize() == 0)
	{
		cout << "No Faculty in Database. " << endl;
	}
	

}
void deleteStudent()
{
	//save the bst
	addFacStack();
	addStudStack();

	//delete the student
	int id;
	string input;
	while(true)
	{
		cout << "Enter ID of Student you want to delete: " << endl;
		cout << "Enter 0 to quit" << endl;
		cin >> input;
		id = atoi(input.c_str());

		if(id == 0)
		{
			break;
		}
		
		if(students->find(id) == NULL)
		{
			cout << "Not valid student ID. Try again." << endl;
			continue;
		}
		
		
		//if cant find student with that id, prompt again and say no such student

		Student *tempStud = students->find(id)->value;
		int success = students->deleteNode(id);

		if(success == 1)
		{
			//delete student id from faculty list
			int advID = tempStud->getAdvisor();
			//bst->facultyNode->faculty->removeStudent
			faculty->find(advID)->value->removeAdvisee(id);

			cout << "Successfully deleted Student: " << id << endl;
			break;
		}
	}
	
}
void addFaculty()
{
	//save the bst
	addFacStack();
	addStudStack();

	//make a new faculty
	string name, level, department;

	cout << "Name: " << endl;
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
	addFacStack();
	addStudStack();

	//delete the faculty
	int id;
	string input;
	while(true)
	{
		cout << "Enter ID of Facutly you want to delete: " << endl;
		cin >> input;
		id = atoi(input.c_str());
		
		if(faculty->find(id) == NULL)
		{
			cout << "Not valid faculty ID. Try again." << endl;
			continue;
		}
		
		//if cant find student with that id, prompt again and say no such student

		Faculty *temp = faculty->find(id)->value;

		list<int>* advisees = temp->getAdvisees();		
		int success = faculty->deleteNode(id);

		if(success == 1)
		{
			//reassign advisees to existing advisors
			for(int i : *advisees)
			{
				int start = 1;
				int end = faculty->getSize();

				int r = (end - start) + 1;
				
				srand(time(NULL));
				int newid = start + rand() % r;
				//update student advisor
				students->find(i)->value->setAdvisor(newid);
				//update advior's list
				faculty->find(newid)->value->addStudent(i);
			}

			cout << "Successfully deleted Faculty: " << id << endl;
			break;
		}
	}
}
void changeAdvisor()
{
	//save the bst
	addFacStack();
	addStudStack();

	string studInput, advisInput;
	int studID, advID;
	while(true)
	{
		//get the student
		cout << "Enter Student ID: " << endl;
		cout << "Enter 0 to stop" << endl;
		cin >> studInput;
		cout << "Enter new Advisor ID: " << endl;
		cout << "Enter 0 to stop" << endl;
		cin >> advisInput;

		studID = atoi(studInput.c_str());
		advID = atoi(advisInput.c_str());

		if(studID == 0 || advID == 0)
		{
			break;
		}
		//get advisor instance
		if(students->find(studID) == NULL)
		{
			cout << "Student does not exist." << endl;
			continue;
		}
		if(faculty->find(advID) == NULL)
		{
			cout << "Advisor does not exist." << endl;
			continue;
		}

		break;

	}

		//found the student and new faculty

		//store the old advisor, so you can remove this student from their list
		int old = students->find(studID)->value->getAdvisor();

		//remove that student from their list
		faculty->find(old)->value->removeAdvisee(studID);

		//set the students advisor
		students->find(studID)->value->setAdvisor(advID);
		//set the student in the advisors list
		faculty->find(advID)->value->addStudent(studID);
}
void rollbackFaculty()
{
	//get the last saved bst from stack
	if(!facStack.empty())
	{
		faculty = &facStack.top();
		facStack.pop();
	}
	else
		cout << "No previous versions." << endl;
}
void rollbackStudent()
{
	//get the last saved bst from stack
	if(!studStack.empty())
	{
		students = &studStack.top();
		studStack.pop();
	}
	else
		cout << "No previous versions." << endl;
}
void writeToFiles()
{
	ofstream outputFaculty;
	outputFaculty.open("facultyTable.txt");
	ofstream outputStudent;
	outputStudent.open("studentTable.txt");
	students->printStudToFile(students->getRoot(), outputStudent);
	faculty->printFacToFile(faculty->getRoot(), outputFaculty);

	outputFaculty.close();
	outputStudent.close();
}
void exitProgram()
{
	writeToFiles();	
	cout << "Exiting program now." << endl;
	exit(0);
}
void addStudStack()
{
	//add a bst to the stack of studentBST
	StudentBST lastStudBST = *students;
	studStack.push(lastStudBST);
}
void addFacStack()
{
	//ad a bst to the stack of facultyBST
	FacultyBST lastFacBST = *faculty;
	facStack.push(lastFacBST);
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

			if(name.empty())
			{
				continue;
			}

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

	if (readStudent.is_open())
	{
		while (!readStudent.eof())
		{
			string name;
			getline(readStudent, name);

			if(name.empty())
			{
				continue;
			}

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

			Student *newStudent = new Student(id, name, grade, major, gpa, advisor);

			students->insert(newStudent);
			

			line = "";
		}

		readStudent.close();
	}

} 



//#endif
#endif
#endif