#include <iostream>
#include "students.h"

using namespace std;

string Student::getName() {
	return name;
}
float Student::getGpa() {
	return gpa;
}
void Student::setName(string namee) {
	name = namee;
}
void Student::setGpa(float gpaa) {
	gpa = gpaa;
}