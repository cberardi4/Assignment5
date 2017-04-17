#include <iostream>
#include <string.h>
#include <list>
#include "Faculty.h"

using namespace std;

Faculty::Faculty(int i, string n, string l, string d)
{
	id = i;
	name = n;
	level = l;
	department = d;
	advisees = new list<int>();
}

Faculty::Faculty()
{
	id = 0;
	name = "";
	level = "";
	department = "";
	advisees = new list<int>();
}

void Faculty::printFaculty()
{
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Department: " << department << endl;
}

int Faculty::getId()
{
	return id;
}
string Faculty::getName()
{
	return name;
}
string Faculty::getLevel()
{
	return level;
}
string Faculty::getDepartment()
{
	return department;
}
list<int>* Faculty::getAdvisees()
{
	return advisees;
}
void Faculty::addStudent(int id)
{
	advisees->push_back(id);
}
void Faculty::setName(string newName)
{
	name = newName;
}
void Faculty::setLevel(string newLevel)
{
	level = newLevel;
}
void Faculty::setDepartment(string newDepartment)
{
	department = newDepartment;
}









