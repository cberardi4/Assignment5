#include <iostream>
#include <string.h>
#include <list>

using namespace std;

class Teacher
{
private:
	int id;
	string name;
	string level;
	string department;
	list<int>* advisees;

public:
	Teacher();
	Teacher(int i, string n, string l, string d);
	~Teacher();

	void addStudent(int idNum);

	//accessors
	int getId();
	string getName();
	string getLevel();
	string getDepartment();
	list<int>* getAdvisees();
};