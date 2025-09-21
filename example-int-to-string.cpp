//This program shows you how to convert int to string and cstrings.

#include <iostream>
#include <cstring>
#include <string>
using namespace std;
//constants
const int MAXCHAR = 51;
const int MAXTIME = 10;

//function prototypes
void readTime(char prompt[], char timeStr[]);

int main() {
  char timeStr[MAXTIME] = {0};  
  char prompt[MAXCHAR] = "Enter time in the HH:MM format: ";
  readTime(prompt, timeStr);
  cout << "Time: " << timeStr << endl;
  return 0;
}

//Name:   readTime(char prompt[], char timeStr[])
//Desc:   This function reads time in a particular format and converts it to a char array
//input:  char prompt[], char timeStr[]
//output: Maybe error message
//return: char array by reference
void readTime(char prompt[], char timeStr[])
{
  int hour = 0, min = 0;
  char discard;
  cout << prompt;
  //read hour and min into ints and the char into discard
  //the discard is just the name of a variable - data that I am
  //throwing away.
  //12:34
  cin >> hour >> discard >> min;
  //while the numbers are not good or the character is not a :
  //error and stay in the loop.
  while(!cin || discard != ':')
  {
    cout << "Invalid input! Please try again!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cin >> hour >> discard >> min;
  }   
  
  //when data is all good, come out and ignore the newline
  cin.ignore(100,'\n');
  //convert hour from int to string then to cstring and copy to timeStr
  strncpy(timeStr, to_string(hour).c_str(),10);
  //convert min from int to string and then cstring and concatenate to timeStr
  strcat(timeStr, to_string(min).c_str());
}
