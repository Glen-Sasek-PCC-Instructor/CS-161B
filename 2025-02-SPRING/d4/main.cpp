//*****************************************************************************
// Author: Glen
// Assignment: Discussion 4
// Date: 2025-04-22
// Description:
// Sources: 
//*****************************************************************************


// Read a list of integers from input into an array 
// and 
// modifies the array by shifting numbers to the right 
// and 
// moving the numbers to the front of the list. 

// The input begins with an integer indicating the number of values that follow. 

// The last input is the index of the number to start shifting from.

// Output the modified array 
// and 
// end with a newline.

// Ex 1:
// 6                SIZE
// 2 4 6 8 10 12    VALUES
// 4                OFFSET
// 10 12 2 4 6 8    RESULT

// Ex 2: 
// 6 
// 2 4 6 8 10 12
// 2
// 6 8 10 12 2 4

#include <iostream>

using namespace std;

const int MAX_ARRAY_SIZE = 100;

int main() {
  int array_size = 0;
  int offset = 0;
  int arr[MAX_ARRAY_SIZE];

  cin >> array_size;

  for(int i =0; i < array_size; i++) {
    cin >> arr[i];
  }

  cin >> offset;

  // for(int i = 0; i < array_size; i++) {
  //   cout <<  arr[(i + offset) % array_size] << ' ';
  // }


  // Assume MAX_ARRAY_SIZE >= array_size + offset;
  for(int i = 0; i < offset; i++) {
    arr[array_size + i]  = arr[i]; // Move values to be over-written to end
  }

  // shuffle left
  for(int i = 0; i < array_size; i++) {
    arr[i] = arr[i + offset]; 
  }

  for(int i = 0; i < array_size; i++) {
    cout <<  arr[i] << ' ';
  }

  cout << endl;

  return 0;
}
