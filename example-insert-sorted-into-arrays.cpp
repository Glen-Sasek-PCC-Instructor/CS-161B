//This program demos  arrays and shows you how to insert //alphabetically into an array from a file called fruits.txt
//The const MAX holds the number of characters for the fruit name
//The const CAP holds the number of fruits that can be stored in
//an array of fruits.

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

//constants
const int MAX = 101;
const int CAP = 15;

//function prototypes
void readData(ifstream &inFile, char fruits[][MAX], int &size);
void printData(char fruits[][MAX], int size);

//main function
int main()
{
    ifstream inFile;
  //create an array of fruits - 2 dim char array
    char fruits[CAP][MAX];
    int size = 0;
    inFile.open("fruits.txt");
    if(!inFile)
    {
        cout << "File not found! Program exiting!!";
        exit(0);
    }

    readData(inFile, fruits, size);
    printData(fruits, size);
    return 0;
}

//Name: readData
//Desc: reads a fruit name from a file and compares and inserts into
//      right alphabetical position
//input: file stream var, array of fruits and size
//output: none or error message
//return: none
void readData(ifstream &inFile, char fruits[][MAX], int &size)
{
  //create a temp fruit object
    char tempFruit[MAX];
    int i = 0;
    while(!inFile.eof())
    {
      //read the name of the fruit from the file into tempFruits's name
        i = 0;
        inFile.get(tempFruit, MAX);
        inFile.ignore(5, '\n');
        if(size == CAP)
        {
            cout << "Array full!" << endl;
            return;
        }
        if(!size)
        {
            strcpy(fruits[size], tempFruit);
        }
        else
        {
          while(strcmp(fruits[i], tempFruit) < 0 && i < size)
          {
            i++;
          }
          //in a loop copy one fruit object to the next space
          //This is the process of shifting to make room.
          for(int j = size; j > i; j--)
          {
            strcpy(fruits[j], fruits[j-1]);
          }
            //insert into the right position AFTER shifting all the fruits
          strcpy(fruits[i], tempFruit);
        }
      //increment size - one more fruit inserted.
        size++;
    }
}

//Name:  isLessThan
//Desc:  compares 2 fruit names and returns true or false
//       Extract just the name from the struct object and send to this function.
//       You could also write a function to send 2 objects and in the function
//       compare the names and return true or false.
//input:  two c strings with fruit names
//output: None
//return: true or false
bool isLessThan(char fruit1[], char fruit2[])
{
    if(strcmp(fruit1, fruit2) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Name:  printData
//Desc:  prints the data from the fruits array
//input: array of fruits and size
//output: list of fruits in alphabetical order
//return: none
void printData(char fruits[][MAX], int size)
{
  //go through a loop and print the data members.
  //In this case that would be just the fruit name
    for(int i = 0; i < size; i++)
    {
        cout << fruits[i] << endl;
    }
}
