/******************************************************************************
# Author:           
# Lab:              
# Date:             
# Description:      
#
# Input:           
# Output:           
# Sources:       
#******************************************************************************/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// function prototypes
bool openFile(ifstream &inFile, string fileName);
void ratioCalc(ifstream& inFile, ofstream& outFile);



// main
int main() {
  ifstream inFile;
  string fileName;
  
  cout << "Enter name of input file:";
  cin >> fileName;
 
  if (!openFile(inFile, fileName)) {
    cout << "file did not open. Program terminating!!!";
    return 0;
  }
 
  inFile.close();
}

// function to open file
// returns true if file opens
// returns false if file does not open for any reason
// parameters: file stream variable by reference and fileName

bool openFile(ifstream &inFile, string fileName) {
  inFile.open(fileName);
  if (!inFile) {
    return false;
  }
  return true;
}



// write the ratioCalc function below this
void ratioCalc(ifstream& inFile, ofstream& outFile);
