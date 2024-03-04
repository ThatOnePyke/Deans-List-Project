#include <iostream>
#ifndef Menu_H
#define Menu_H

using namespace std;

class Menu {
public:
	void startScreen();
	bool chooseFile();
	string textName();
private:
	string fileName;
	string filePath;
	string selectedFile;
};

#endif