#include <iostream>
#include <vector>
#include <stack>
#include "students.h"
#ifndef List_H
#define List_H

using namespace std;

class DeansList {
public:
	void sortStudents(stack<Student> Students);
	vector<Student> getDeansList();
	stack<Student> getStudents(string text);
private:
	vector<Student> DeanList;
	stack<Student> studentStack;
};

#endif