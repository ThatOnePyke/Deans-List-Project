#include <iostream>
#ifndef students_H
#define students_H

using namespace std;

class Student {
public:
	string getName();
	float getGpa();
	void setName(string namee);
	void setGpa(float gpaa);
private:
	string name;
	float gpa;
};

#endif