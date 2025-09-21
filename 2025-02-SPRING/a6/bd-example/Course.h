#ifndef COURSE_H_
#define COURSE_H_
//#include <fstream>
#include "Student.h"

using std::ifstream;
using std::ofstream;

struct Course {
	Student roster[20];
	int numStudents = 0;
};

Course InitCourse();
void openFile(char fileName[], ifstream &inFile);
void readStudent(ifstream &inFile, Course &course);
void openFile(char fileName[], ofstream &outFile);
void saveStudentFile(Course course, ofstream &outFile);
Student FindStudentHighestGPA(Course course);
void AddStudent(Student student, Course &course);
void printRoster(Course course);
void dropStudent(char *lastname, Course &course);
void addNewStudent(Course &course);
bool isLessThan(char student1[], char student2[]);
void fixInputStream();

#endif

