/*
Program Title: School Management System in C++

Submitted by: Lord Patrick Raizen Togonon, Gem Win Ca�ete, John Paul Sapasap, Jed Andrew Del Rosario

Program Description: The Program Takes in inputs the teacher/admin. For the Teacher/Admin, first the program takes in a username and password which can be edited directly on the password.txt file.
We've also added a student function where a student can check his/her profile with a pin given to him/her by the teacher/admin */


#include "functions.cpp"

int main()
{
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	system("pause"); 
	welcome();
	main_menu();
	getch();

	return 0;
}

