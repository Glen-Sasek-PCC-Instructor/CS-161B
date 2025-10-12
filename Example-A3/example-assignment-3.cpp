// ------------- FILE HEADER -------------
// Author ✅: 
// Assignment ✅:
// Date ✅:
// Citations: 


// ------------- ZYBOOKS SCORES -------------
// Chapter ✅: 
// Participation ✅: 
// Challenge ✅:
// Labs ✅:


// ------------- DISCORD POSTS -------------
// https://discord.com/invite/URYKKf8YHm
// Count ✅:
// Links (Optional): 


// ------------- DESIGN DOCUMENT -------------
// A. INPUT ✅: 
// B. OUTPUT ✅:
// C. CALCULATIONS ✅:
// D. LOGIC and ALGORITHMS ✅:
//    (Optional) flow chart link or file name: 


// ------------- TESTING -------------
// PASS ALL GIVEN SAMPLE RUN TESTS ✅: 
// (Optional) Additional tests count:   

// TEST using make utility config is in Makefile
// make all test clean

// ------------- CODE -------------
#include <iostream>
#include <iomanip>
#include "gs-lib.h" // Example library file. Create your own to reuse code.
#include "lang_en.h"

using namespace std;

const int MAX_SCORE_COUNT = 20;

// Function prototypes (if any)
void welcome();

// Reads a list of scores from the user. A -1 indicates the end of the input and is not stored in the array. 
// (Use an appropriate loop!! Check out this example code - a for loop is count controlled, and a while loop is condition based.)
// Call the readDouble function to do this. You must catch all invalid data such as characters, negative numbers other than -1 etc.
// The variable count keeps track of the number of scores entered.
// You must also do validation to make sure that the number is between 0 and 4 inclusive and nothing other than that. Use a while loop to do this.
void readScores(double scores[], int &count);

// void readDouble(string prompt, double &num);
using gs::readDouble; // My Example: Create your own library file to reuse code. 

// Not required but nice to have.
char scoreToChar(double score);

// Use a loop to process each array element and calculate the letter grade for each score.
void calcGrades(double scores[], char grades[], int count);

// Go through a for loop and print the scores and the corresponding grades for each item.
void printList(double scores[], char grades[], int count);

// Required function
void sort(double scores[], char grades[], int count);


// The median is located in the middle of the array if the array’s size is odd. 
// Otherwise, the median is the average of the middle two values.
// Return the median to main() and output in main() with two decimal places.
double median(double scores[], int count);



// Main function
// https://en.cppreference.com/w/cpp/language/main_function.html
int main() {
  double scores[MAX_SCORE_COUNT] = {0};
  char grades[MAX_SCORE_COUNT] = {0};
  int count = 0;
  
  welcome();
  readScores(scores, count);
  calcGrades(scores, grades, count);

  cout << MSG_STATS_HEADER << endl;
  cout << MSG_LIST_SCORES << endl;
  printList(scores, grades, count);

  sort(scores, grades, count);
  cout << MSG_LIST_SORTED << endl;
  printList(scores, grades, count);
 
  cout << LABEL_MEDIAN << fixed << setprecision(2) << median(scores, count) << endl;

  cout << MSG_THANK_YOU << endl;

  return 0;
}

// Function implementations (if any)
// Function prototypes (if any)
void welcome() {
  cout << MSG_WELCOME << endl;
}

void readScores(double scores[], int &count) {
  const double MIN_SCORE = 0.0;
  const double MAX_SCORE = 4.0;
  const double END_SENTINEL = -1;
  double score = 0;
  while(score != END_SENTINEL && count < MAX_SCORE_COUNT) {
    readDouble(">> ", score);
    if(gs::between(score, MIN_SCORE, MAX_SCORE)) {
      scores[count] = score;
      count++;
    } else if(score != END_SENTINEL) {
      // Not in range or end sentinel.
      cout << ERR_INVALID_SCORE << ' ' << MSG_TRY_AGAIN << endl;
    }
  }

  if(score != END_SENTINEL && count == MAX_SCORE_COUNT) {
    cout << MSG_ADDITIONAL_SCORES_IGNORED << endl;
  }
}

// Required function name and signature
void sort(double scores[], char grades[], int count) {
  // Implemented in my library with specific name because I may want to implement additional specific sorting methods.
  // Using my re-usable code library. 
  gs::selectionSortParallel(scores, grades, count);
}

// Sort First! This function depends on a sorted array.
double median(double scores[], int count) {
  double n = 0.0;
  int indexForOddCount = count / 2;
  bool even = count % 2 == 0;
  if(even) {
    // For even count the median is the average of the middle two values.
    n = (scores[indexForOddCount] + scores[indexForOddCount - 1]) / 2.0;
  } else {
    n = scores[indexForOddCount];
  }
  return n;
}

char scoreToChar(double score) {
  enum grades {A, B, C, D, F}; // Syntactic convenience A=0, B=1...F=4
  const double GRADE_CUTOFFS[] = {3.3, 2.7, 1.9, 1.1, 0.0};
  const char GRADE_CHARS[] = {'A', 'B', 'C', 'D', 'F'};
  char c = GRADE_CHARS[F];
  for(int i = A; i < F && c == GRADE_CHARS[F]; i++) {
    if(score > GRADE_CUTOFFS[i]) {
      c = GRADE_CHARS[i];
    }
  }
  return c;
}

// Use a loop to process each array element and calculate the letter grade for each score.
void calcGrades(double scores[], char grades[], int count) {
  for(int i = 0; i < count; i++) {
    grades[i] = scoreToChar(scores[i]);
  }
}

void printList(double scores[], char grades[], int count) {
  cout << fixed << setprecision(1);
  for(int i = 0; i < count; i++){
    cout << scores[i] << ' ' << grades[i] << endl;
  }
}


// ------------- DESIGN -------------
/* 
Program Name:

Program Description:

Design:
A. INPUT
Define the input variables including name data type. 

B. OUTPUT
Define the output variables including data types. 

C. CALCULATIONS
A	>3.3 <= 4.0	Exceeds
B	>2.7 <= 3.3	Meets
C	>1.9 <= 2.7	Approaching
D	>1.1 <= 1.9	Not Yet
F	>0.0 <= 1.1	No Evidence

D. LOGIC and ALGORITHMS
Design the logic of your program using pseudocode or flowcharts. 
Use conditionals, loops, functions or array constructs.
List the steps in transforming inputs into outputs. 
https://github.com/Glen-Sasek-PCC-Instructor/2025-06-22/blob/main/Pseudocode-Reference.txt


SAMPLE RUNS
Welcome to my Parallel Arrays program!
Please enter the list of scores (-1 to end input:)
Valid scores are between 0 and 4 inclusive.
>> 3.5
>> 2.7
>> 3.3
>> 2.5
>> 3.2
>> 1.5
>> 4.0
>> 3.7
>> -1

Your stats are as below: 

The list of scores and their grades are:
3.5 A
2.7 C
3.3 B
2.5 C
3.2 B
1.5 D
4.0 A
3.7 A

The list sorted by scores in ascending order:
1.5 D
2.5 C
2.7 C
3.2 B
3.3 B
3.5 A
3.7 A
4.0 A

The median score is 3.25

Thank you for using my Parallel Arrays program!!



Welcome to my Parallel Arrays program!
Please enter the list of scores (-1 to end input:)
Valid scores are between 0 and 4 inclusive.
>> 3.5
>> 2.7
>> 3.3
>> 4.5
Invalid score! Please try again!!
>> abc
Invalid score! Please try again!!
>> 3.2
>> 1.5
>> 4.0
>> 3.7
>> 4.0
>> -1

Your stats are as below: 

The list of scores and their grades are:
3.5 A
2.7 C
3.3 B
3.2 B
1.5 D
4.0 A
3.7 A
4.0 A

The list sorted by scores in ascending order:
1.5 D
2.7 C
3.2 B
3.3 B
3.5 A
3.7 A
4.0 A
4.0 A

The median score is 3.40

Thank you for using my Parallel Arrays program!!

*/
