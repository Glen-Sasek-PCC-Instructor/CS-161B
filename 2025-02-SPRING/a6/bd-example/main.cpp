/******************************************************************************
# Author:           
# Assignment:       Assignment 6 (CS161B)
# Date:             24 May 2025
# Description:      Student Roster and GPA Displayer
Shows students loaded from students.txt file. Displays student with
highest GPA. Allows adding a removing of students, and saving the file.
# Input:            menu choices, student first name, last name, gpa
# Output:           menu, list of students, student with highest gpa
# Sources:          REF CS161b specifications
#******************************************************************************/

// Run this program with the following command:
// g++ -Wall -Werror -Wfatal-errors *.cpp && ./a.out && rm ./a.out

#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>


#include "Student.h"
#include "Course.h"

using namespace std;

// function stubs
void welcome(string msg, char fill);
int showMenu();
// these should be in Course.h, but I get errors
//void openFile(char fileName[], ifstream &inFile);
//void readStudent(ifstream &inFile, Course &course);
//void openFile(char fileName[], ofstream &outFile);
//void saveStudentFile(Course course, ofstream &outFile);

// main loop
int main() {
    //main loop variables
    // file system
    ifstream inFile;
    ofstream outFile;
    char fileName[20] = "students.txt";
    
    // student roster
    Course course = InitCourse();
    char lastname[20];
    
    // menu
    int option = 0;
    
    //display welcome
    welcome("Welcome to the Student Roster Program", '*');
    
    // open the students.txt file
    openFile(fileName, inFile);
    readStudent(inFile, course); // load student file
    
    //display initial student roster
    cout << fixed << showpoint << setprecision(1);
    welcome("Student Roster", '-');
    printRoster(course);
    
    // loop until quit
    // switch didn't like some function so I used if
    do {
        // show menu and get options
        option = showMenu();
        if (option == 1) {
            welcome("Student Roster", '-');
            printRoster(course);
        }
        else if (option == 2) {
            Student student = FindStudentHighestGPA(course);
            welcome("Top Student GPA", '-');
            cout << student.first << " " << student.last 
            << " - GPA: " << student.gpa << endl;
        }
        else if (option == 3) {
            addNewStudent(course);
        }
        else if (option == 4) {
            dropStudent(lastname, course);
        }
        else if (option == 5) {
            openFile(fileName, outFile);
            saveStudentFile(course, outFile);
        }
    }
    while (option != 6);

    welcome("Thank you for using the Student Roster Program", '*');

	return 0;
}

// display welcome/goodbye
void welcome(string msg, char fill) {
    cout << setfill(fill) << setw(msg.length()) << "" << endl;
    cout << msg << endl;
    cout << setfill(fill) << setw(msg.length()) << "" << endl;
}

// show menu and get options
int showMenu() {
    int choice = 0;
    do {
        cout << "\nPlease make a selection: \n" << endl;
        cout << "1 - Show list of students" << endl;
        cout << "2 - Show student with highest GPA" << endl;
        cout << "3 - Add a student" << endl;
        cout << "4 - Remove a student" << endl;
        cout << "5 - Write changes to students.txt" << endl;
        cout << "6 - Quit program" << endl;
        cout << "\nEnter selection: ";
        cin >> choice;
        if (cin.fail() || cin.peek() != '\n' || choice < 1 || choice > 6) {
            cout << "\n*** Invalid entry. ***" << endl;
            cout << "Must be a whole number between 1 and 7." << endl;
            choice = 0;
            fixInputStream();
        }
    }
    while (choice == 0);
    fixInputStream();
    cout << endl;
    return choice;
}

