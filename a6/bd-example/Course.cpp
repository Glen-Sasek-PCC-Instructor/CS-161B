#include <iostream>
#include <cstring>
#include <fstream>
#include <limits>

const int MAXCHAR = 20;
#include "Course.h"
#include "Student.h"
using namespace std;

Course InitCourse() {
	Course course;
	course.numStudents = 0;
	return course;
}

Student FindStudentHighestGPA(Course course) {
   Student gpaWinner;
   int i;
   double topGPA = 0.0;
   for (i = 0; i < course.numStudents; ++i) {
      if (course.roster[i].gpa > topGPA) {
         topGPA = course.roster[i].gpa;
         gpaWinner = course.roster[i];
      }
   }
   return gpaWinner;
}

void AddStudent(Student student, Course &course) {
	int i = 0;
   int j = 0;
   //intial added student
   if (course.numStudents == 0) {
      strcpy(course.roster[course.numStudents].first, student.first);
      strcpy(course.roster[course.numStudents].last, student.last);
      course.roster[course.numStudents].gpa = student.gpa;
   }
   //insert alphabetically on first name
   else {
      for(i = 0; i < course.numStudents; i++)
         {
            //if new first is lower
            if(strcmp(student.first, course.roster[i].first) < 0)
               {
                  break; // stop here
               }
         }
      //make room
      for(j = course.numStudents; j > i; j--)
         {
            course.roster[j] = course.roster[j-1];
         }
      //insert into the right position after making room
      course.roster[i] = student;
   }
   // increase total number of students
	course.numStudents++;
	// return course;
}

// load students from file
void readStudent(ifstream &inFile, Course &course)
{
   Student fileStudent;
   char firstName[MAXCHAR];
   char lastName[MAXCHAR];
   double gpa = 0.0;
   inFile.get(firstName, MAXCHAR, ';');
   while(inFile)
      {
         inFile.ignore(100, ';');
         inFile.get(lastName, MAXCHAR, ';');
         inFile.ignore(100, ';');
         inFile >> gpa;
         inFile.ignore(100, '\n');
         fileStudent = InitStudent(firstName, lastName, gpa);
         AddStudent(fileStudent, course);
         inFile.get(firstName, MAXCHAR, ';');
      }
   inFile.close();
}

// print out the list of students
void printRoster(Course course) {
   int i;
   for (i = 0; i < course.numStudents; ++i) {
      Student tempStudent = InitStudent(course.roster[i].first, 
         course.roster[i].last, course.roster[i].gpa);
      printStd(tempStudent);
   }
}

// remove a student
void dropStudent(char *lastname, Course &course) {
   int i = 0;
   int j = 0;
   bool found = false;
   cout << "Enter the last name of the student to drop: ";
   cin.getline(lastname, MAXCHAR);
   while (i < course.numStudents && !found) {
      if(strstr (course.roster[i].last,  lastname) != NULL ) {
         found = true;
         cout << "\nDeleting user " << course.roster[i].first << " " << course.roster[i].last << endl;
         for(j = i + 1; j < course.numStudents ; ++j)
                  {
                     course.roster[j-1] = course.roster[j];
                  }
         course.numStudents--;
      }
      ++i;
   }
   if (!found) {
      cout << "\nA student with the last name of " << lastname << 
      " was not found." << endl;
   }
}

// manually add a new student
void addNewStudent(Course &course) {
   char first[20];
   char last[20];
   double gpa = -1.0;
   cout << "Enter the student's first name: ";
   cin.getline(first, 20);
   cout << "Enter the student's last name: ";
   cin.getline(last, 20);
   do {
      cout << "Enter the student's GPA (0 - 4.0): ";
      cin >> gpa;
      if (cin.fail() || cin.peek() != '\n' || gpa < 0 || gpa > 4) {
         cout << "\n*** Invalid entry. ***" << endl;
         cout << "Must be a number between 0 and 4." << endl;
         gpa = -1.0;
         fixInputStream();
      }
   }
   while (gpa == -1.0);
   Student newStudent = InitStudent(first, last, gpa);
   AddStudent(newStudent, course);
   cout << "\nStudent " << first << " " << last << " added." << endl;
}

void openFile(char fileName[], ifstream &inFile) {
   inFile.open(fileName);  
   if (!inFile) {
      cout << "Cannot open the input file. \n"
      << "Exiting program.";
      exit(0);
   }
}

//open the output file
void openFile(char fileName[], ofstream &outFile)
{
   outFile.open(fileName);
   if(!outFile)
      {
         cout << "Output file did not open. Exiting program." << endl;
         exit(0);
      }
}

//writes the students back to the file
void saveStudentFile(Course course, ofstream &outFile)
{
   int i = 0;
   for(i = 0; i < course.numStudents; i++)
      {
         outFile << course.roster[i].first << ";" <<
         course.roster[i].last << ";" << course.roster[i].gpa <<
         endl;
      }
   outFile.close();
   cout << "Student file saved." << endl;
 }

bool isLessThan(char student1[], char student2[])
{
   if(strcmp(student1, student2) < 0)
      {
         return true;
      }
   else
      {
         return false;
      }
}


// clears and resets input stream
void fixInputStream() {
      cin.clear();
      //Best practice to clear input
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Requires #include <limits> NOTE *not <climits> this is a different library
      
      // Bad practice literal 100 called a "Magic Number" an insulting term in code.
      // Commonly seen in this type of example to avoid the uglieness and required include above. 
      // cin.ignore(100, '\n');
}


