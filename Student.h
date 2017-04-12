#include <iostream>
#include <string.h>

using namespace std;

class Student
{
private:
	int id;
	string name;
	string level;
	string major;
	double gpa;
	int advisor;

public:
	Student(int i, string n, string l, string m, double g, int a);
	Student();
	~Student();

	void printStudent();
	void printAllStudents();

	//accessor
	int getId();
	string getName();
	string getLevel();
	string getMajor();
	double getGpa();
	int getAdvisor();
};