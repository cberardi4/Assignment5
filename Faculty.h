#include <iostream>
#include <string.h>
#include <list>

using namespace std;

class Faculty
{
private:
	int id;
	string name;
	string level;
	string department;
	list<int>* advisees;

public:
	Faculty();
	Faculty(int i, string n, string l, string d);
	~Faculty();

	void addStudent(int idNum);
	void printFaculty();

	//accessors
	int getId();
	string getName();
	string getLevel();
	string getDepartment();
	list<int>* getAdvisees();
	void removeAdvisee(int studID);
	int countAdvisees();

	//mutators
	void setName(string newName);
	void setLevel(string newLevel);
	void setDepartment(string newDepartment);
};