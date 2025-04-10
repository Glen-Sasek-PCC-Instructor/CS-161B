//*****************************************************************************
// Author: Glen
// Assignment: Discussion 2
// Date:
// Description:
// Sources: 
//*****************************************************************************

// Strong Password
// With your programming partner, write a program that creates a password for a user, given the following information:
// Ask the user for a word they remember. Longer words are best, and phrases are even better. 
// The word may be a dog or cat you had years ago, or even a street you lived on. 
// For this example I will use a street I lived on: Mower Street. 
// Take the first word of the phrase and ignore the rest. 
// So, just Mower in this case.
// Pick a number you can remember, such as the year you graduated high school. For this example, 
// I will use the year I graduated from college: 1980. 
// Limit this to a 4 digit number. 
// Use a char array, and make sure every character of the char array is a number.
// Pick a symbol you will remember. 
// Make sure it is readily available on your keyboard so you don't have to hunt for it. 
// For this example I will use ^.
// Assume all char arrays have 20 characters.
// Hint: 
//  Make a new string, 
//  copy the first word to the new string. 
//  Then concatenate the 4 digit number. 
//  And then finally concatenate the character & 
// Use C-string library functions whenever you can to manipulate the strings. 
// Don't forget to add a null character at the end of the new string after you have finished copying the characters.
// You must use only char arrays for this course - no String class.

// ~~~~~~~~~~~~~~ Example-1: ~~~~~~~~~~~~~~
// INPUT:
// Mower Street
// 1991 
// $
// OUTPUT:
// Your strong password is: Mower1991$

// ~~~~~~~~~~~~~~ Example-2: ~~~~~~~~~~~~~~
// INPUT:
// Gayathri Iyer 
// 2024
// &
// OUTPUT:
// Your strong password is: Gayathri2024&

#include <iostream>
#include <limits>
#include <cctype>
#include <cstring>

using namespace std;

const char PROMPT_PHRASE[] = 
  "\n"
  "Enter a word or phrase you will remember. \n"
  "Longer words are best, and phrases are even better. \n";

const char PROMPT_DIGITS[] = 
  "\n"
  "Enter four digits [0-9] \n"
  "Use a number you can remember, \n"
  "such as the year you graduated high school.\n";

const char PROMPT_SPECIAL[] = 
  "\n"
  "Enter a special character symbol you will remember. [!@#$%^&*()] \n"
  "Make sure it is readily available on your keyboard\n"
  "so you don't have to hunt for it. \n";

const char LABEL_PASSWORD[] = "Your strong password is: ";

int main() {
  const size_t MAX_CHARS = 20;
  const size_t REQUIRED_DIGITS = 4;
  
  char word[MAX_CHARS + 1] = {0};
  char password[MAX_CHARS + 1] = {0};
  char c = '\0'; 
  int digit_count = 0;

  cout << PROMPT_PHRASE;
  cin >> word;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  strcpy(password, word);

  cout << PROMPT_DIGITS;
  while(digit_count < REQUIRED_DIGITS) {
    cin.get(c);
    if(c >= '0' && c <= '9') {
      password[strlen(password)] = c; // Initialized with {0} so null terminator is already in place.
      digit_count++;
    } else {
      cerr << "NON-DIGIT IGNORED: " << c << endl;
    }
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore trailing characters and newline

  cout << PROMPT_SPECIAL;
  cin.get(c);
  password[strlen(password)] = c;

  cout << LABEL_PASSWORD;
  cout << password << endl;

  return 0;
}
