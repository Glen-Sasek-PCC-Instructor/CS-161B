#ifndef STUDENT_H_
#define STUDENT_H_

struct Student {
	char first[20];
	char last[20];
	double gpa;
};

Student InitStudent(char *first, char *last, double gpa);

// what was this function supposed to be for??
void GetLastName(char *studentName, Student student);
double GetGPA(Student student);
void printStd(Student student);

#endif

