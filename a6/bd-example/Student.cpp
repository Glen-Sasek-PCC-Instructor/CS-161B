#include <iostream>
#include <cstring>

#include "Student.h"

using namespace std;

Student InitStudent(char *first, char *last, double gpa) {
	Student student;
	strcpy(student.first, first);
	strcpy(student.last, last);
	student.gpa = gpa;
	return student;
}

// what was this function supposed to be for??
void GetLastName(char *studentName, Student student) {
	strcpy(studentName, student.last);
}

double GetGPA(Student student) {
	return student.gpa;
}

void printStd(Student student) {
	cout << student.first << ";" << student.last << ";" <<
	student.gpa << endl;
}
