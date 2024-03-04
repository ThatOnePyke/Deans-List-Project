#include <iostream>
#include "List.h"
#include "Menu.h"
#include "students.h"


int main() {
	Menu menu;
	menu.startScreen();
	DeansList list;
	list.sortStudents(list.getStudents(menu.textName()));
	list.getDeansList();
	return 0;
}