#include <iostream>
#include <string.h>
#include <list>
#include "Teacher.h"

using namespace std;

Teacher::Teacher(int i, string n, string l, string d)
{
	id = i;
	name = n;
	level = l;
	department = d;
	advisees = new list<int>();
}

Teacher::Teacher()
{
	id = 0;
	name = "";
	level = "";
	department = "";
	advisees = new list<int>();
}

void Teacher::printTeacher()
{
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Department: " << department << endl;
}

int Teacher::getId()
{
	return id;
}
string Teacher::getName()
{
	return name;
}
string Teacher::getLevel()
{
	return level;
}
string Teacher::getDepartment()
{
	return department;
}
list<int>* Teacher::getAdvisees()
{
	return advisees;
}
void Teacher::addStudent(int id)
{
	advisees->push_back(id);
}












