//demos parallel arrays
//read names and scores from user and find a name
//read input from the user until they enter "quit" or "Quit" for name
#include <iostream>
#include <cstring>
using namespace std;
const int CAP = 25;
const int MAXCHAR = 51;

//function protytpes
void getInput(char names[][MAXCHAR], double scores[], int &count);
void printList(const char names[][MAXCHAR], const double scores[], int count);
void findName(const char names[][MAXCHAR], const double scores[], int count);

//main
int main() {
  char names[CAP][MAXCHAR] = {0};
  double scores[CAP] = {0.0};
  int count = 0;
  getInput(names, scores, count);
  printList(names, scores, count);
  findName(names, scores, count);
  return 0;
}

//getInput from user
void getInput(char names[][MAXCHAR], double scores[], int &count)
{
  char tempName[MAXCHAR] = {0};
  cout << "Enter name: ";
  cin.getline(tempName, MAXCHAR);
  while(strcmp(tempName, "quit") != 0 && strcmp(tempName, "Quit") != 0)
    {
      if (count < CAP)
      {
        strcpy(names[count], tempName);
        cout << "Enter score: ";
        cin >> scores[count];
        cin.ignore(100, '\n');
        count++;
      }
      else{
        cout << "List full!!" << endl;
        break;
      }
      cout << "Enter next name: ";
      cin.getline(tempName, MAXCHAR);
    }
}

//print the list
void printList(const char names[][MAXCHAR], const double scores[], int count)
{
  for(int i = 0; i < count; i++)
    {
      cout << names[i] << ";" << scores[i] << endl;
    }
}

//find a name in the list
void findName(const char names[][MAXCHAR], const double scores[], int count)
{
  char srchName[MAXCHAR];
  int i = 0;
  cout << "Enter name to find: ";
  cin.getline(srchName, MAXCHAR);
  for(i = 0; i < count; i++)
    {
      //if(strcmp(names[i], srchName) == 0)
      if(strstr(names[i], srchName) != nullptr)
      {
        cout << names[i] << ";" << scores[i] << endl;
        break;
      }
    }
  if(i == count)
  {
    cout << "Name not found!! " << endl;
  }
}