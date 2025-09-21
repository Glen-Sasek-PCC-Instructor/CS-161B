//*****************************************************************************
// Author: 
// Assignment:
// Date:
// Description:
// Sources: 
//*****************************************************************************

#include <iostream>
#include <limits>

using namespace std;

// * void welcome() - This function prints a welcome message to the user.
void welcome();

// * void readScores(double scores[], int &count)
//    * Reads a list of scores from the user. A -1 indicates the end of the input and is not stored in the array. (Use an appropriate loop!! Check out this example code - a for loop is count controlled, and a while loop is condition based.) 
//    * Call the readDouble function to do this. You must catch all invalid data such as characters, negative numbers other than -1 etc.
//    * The variable count keeps track of the number of scores entered.
//    * You must also do validation to make sure that the number is between 0 and 4 inclusive and nothing other than that. Use a while loop to do this.
void readScores(double scores[], int &count);

// * void readDouble(string prompt, double &num)
//    * This function should be used any time you read any floats or doubles from the user. Use this function to read the numerical scores from the user.
//    * It takes a string prompt, outputs it, reads a number from the user, validates and returns the num by reference.
//    * Write it exactly like the readInt from assignment 1 but declare a double or float instead of an int. See Samplea01.cpp for the readInt function.
//    * You must catch all invalid data such as characters, negative numbers etc.
void readDouble(string prompt, double &num);

// * void calcGrade(double scores[], char grade[], int count)
//    * Use a loop to process each array element and calculate the letter grade for each score.
//    * Use the table below to assign grades A to F to the corresponding numerical score.
void calcGrade(double scores[], char grade[], int count);

char getCharForScore(double score);


const string MSG_INVALID_SCORE = "Invalid score! Please try again!!";

int main() {
  cout << "Hello, World!" << endl;
  return 0;
}

void welcome() {
  cout << "Welcome to my Parallel Arrays program!" << endl;
}

void readDouble(string prompt, double &num) {
  bool next = true;
  while(next) {
    cout << prompt;
    cin >> num;
    if(!cin) {
      cout << MSG_INVALID_SCORE << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else {
      next = false;
    }
  }
}


void readScores(double scores[], int &count) {
  const double END_SENTINEL = -1; 
  const double MIN = 0.0;
  const double MAX = 4.0;

  count = 0;
  
  bool next = true;
  while(next) {
    double d = 0.0;
    readDouble(">> ", d);
    if(d == END_SENTINEL) {
      next = false;
    } else if(d < MIN || d > MAX) {
      cout << MSG_INVALID_SCORE << endl;
    } else {
      scores[count] = d;
      count++;
    }
  }
}

char getCharForScore(double score) {
  if(score >= 3.3) {
    return 'A';
  } else if( score >= 2.7) {
    return 'B';
  } else if( score >= 1.9) {
    return 'C';
  } else if( score >= 1.1) {
    return 'D';
  } else {
    return 'F';
  }
}


void calcGrade(double scores[], char grade[], int count) {
  for(int i = 0; i < count; i++) {
    grade[i] = getCharForScore(scores[i]);
  }
}
