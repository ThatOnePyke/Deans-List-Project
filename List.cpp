#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include "List.h"
#include "Menu.h"

using namespace std;

stack<Student> DeansList::getStudents(string textFileName) {
	string myText;
	string name;
	float gpa;

	//opening text file and reading contents into student class
	ifstream myfile(textFileName);
	while (getline(myfile, myText)) {
		name = myText.substr(0, myText.find_last_of(" "));
		string tempgpa2 = myText.substr(myText.find_last_of(" ")+1, myText.length());
		gpa = stof(tempgpa2);

		//student class gets pushed to stack
		Student stud;
		stud.setGpa(gpa);
		stud.setName(name);
		studentStack.push(stud);
	}
	myfile.close();

	
	return studentStack;
}
void DeansList::sortStudents(stack<Student> studentStack) {
	cout << "Students:" << endl;
	// while stack not empty prints name and gpa of student at top of stack and then pops it off, seeing if stack had correct names and gpa
	while (!studentStack.empty()) {
		cout << studentStack.top().getName();
		cout << " ";
		cout << studentStack.top().getGpa();
		cout << endl;
		if (studentStack.top().getGpa() >= 3.5) {
			DeanList.push_back(studentStack.top());
		}
		studentStack.pop();
	}
	
}
vector<Student> DeansList::getDeansList() {
	cout << endl << "Deans List:" << endl;
	for (int i = 0; i < DeanList.size(); i++) {
		cout << DeanList.at(i).getName() << " ";
		cout << DeanList.at(i).getGpa() << endl;
	}
	return DeanList;
}