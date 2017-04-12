#include "Student.h"
#include <string.h>
#include <iostream>

using namespace std;

Student::Student(int i, string n, string l, string m, double g, int a)
{
	id = i;
	name = n;
	level = l;
	major = m;
	gpa = g;
	advisor = a;
}

Student::Student()
{
	id = 0;
	name = "";
	level = "";
	major = "";
	gpa = 0.0;
	advisor = 0;
}

Student::~Student()
{}

int Student::getId()
{
	return id;
}
string Student::getName()
{
	return name;
}
string Student::getLevel()
{
	return level;
}
string Student::getMajor()
{
	return major;
}
double Student::getGpa()
{
	return gpa;
}
int Student::getAdvisor()
{
	return advisor;
}
void Student::printStudent()
{
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Major: " << major << endl;
	cout << "GPA: " << gpa << endl;
	cout << "Advisor: " << advisor << endl;
}





