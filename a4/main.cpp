//*****************************************************************************
// Author: Glen
// Assignment: A4 starter
// Date:
// Description:
// Sources: 
//*****************************************************************************

#include <iostream>

using namespace std;

const int MAXCHAR = 51;

// You must have functions to do the following:
// ❏ void welcome() - This function prints a welcome message to the user.
void welcome();

// ❏ void readInput(char courseNums[][MAXCHAR], int students[], int &count) (***Note: modified for this grade level***)
// a. This function takes an array of c-strings, and an array of ints and reads the
// course numbers and students enrolled from the user.
// b. Read until the user enters “Quit” or “quit” for the course number. The
// SampleA04.cpp should help you do this. Read the corresponding number of
// students enrolled.
// c. Call the readInt function to read the number of students for each course
// number. You must catch all invalid data such as characters, negative numbers
// etc.
// d. You must also do validation to make sure that the number is between 0 and 25.
// The maximum number of students that can be enrolled in a course is less than or
// equal to 25. Use a while loop to do this.
// e. Insert the course number and the number of students in the right position based
// on the course number. You must not use any sorting algorithm. Insert the
// course numbers and its students in the right position, by finding the
// position and shifting the other courses. Here is an example -
// insertSorted.cpp. See sample run below.
// f. count will keep track of the number of courses entered.
// g. Test your function with at least 10 courses to make sure that the insertion works
// correctly.
void readInput(char courseNums[][MAXCHAR], int students[], int &count);

// ❏ void readInt(string prompt, int &num)
// a. This function should be used any time you read any integers from the user. Use
// this function to read the menu option from the user.
// b. It takes a string prompt, outputs it, reads a number from the user, validates and
// returns the num by reference.
// c. See Samplea01.cpp for the function. You may use the function in the sample.
// d. You must catch all invalid data such as characters, negative numbers etc.
void readInt(string prompt, int &num);

// ❏ void printList(char courseNums[][MAXCHAR], int students[], int count)
// a. This function takes the 2 arrays and count, uses a for loop and prints the lists to
// the user.
// b. Format your list neatly.
void printList(char courseNums[][MAXCHAR], int students[], int count);

// ❏ void cancelCourses(char courseNums[][MAXCHAR], int students[], int &count)
// a. This function takes the 2 arrays and the count and removes all courses with less
// than 10 students in the course.
// b. You must use a for loop, find the index where the number of students is less than
// 10, and then remove that number and the corresponding course number from the
// char array by shifting elements in both the arrays.
// c. Update the count appropriately. If you cancel or remove 3 courses, then count
// should be subtracted by 3, so the number of courses is updated.
void cancelCourses(char courseNums[][MAXCHAR], int students[], int &count)

// ❏ int main()
// a. Declare the arrays for course numbers and students.
// b. Call the readInput() function and get the arrays filled. The list must be
// ordered by the course numbers. This is important for this grade level.
// c. Call the printList() function and print the course numbers and students
// neatly formatted.
// d. Call the cancelCourses() function and cancel the courses with less than10
// students in them.
// e. Call the printList() function again and print the course numbers and
// students neatly formatted.
// f. End your program.

int main() {
  cout << "Hello, World!" << endl;
  return 0;
}

// PLACEHOLDER IMPLEMENTATIONS
void welcome() {
  cout << "TODO: Print a welcome message to the user." << endl;
}

void readInput(char courseNums[][MAXCHAR], int students[], int &count) {
  cout << "TODO: readInput(char courseNums[][MAXCHAR], int students[], int &count)" << endl;
}

void readInt(string prompt, int &num) { 
  cout << "TODO: readInt(string prompt, int &num)" << endl;
}

void printList(char courseNums[][MAXCHAR], int students[], int count) {
  cout << "TODO: printList(char courseNums[][MAXCHAR], int students[], int count)" << endl;
}

void cancelCourses(char courseNums[][MAXCHAR], int students[], int &count) {
  cout << "TODO: cancelCourses(char courseNums[][MAXCHAR], int students[], int &count)" << endl;
}