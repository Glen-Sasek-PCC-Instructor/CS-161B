#include <iostream>

// COMPILE
// g++ main.cpp

// RUN
// ./a.out

// TEST (Output will not display test input, only program output)
// ./a.out < test-1.txt

// REMOVE COMPILED EXECUTABLE .out 
// rm ./a.out

// COMPILE RUN TEST and REMOVE COMPILED EXECUTABLE
// g++ && ./a.out < test-1.txt && rm ./a.out

using namespace std;

const int TODO_STATUS_VALUE = -1;

int enqueue(int queue[], int &size, int val);
int dequeue(int queue[], int &size, int &val);
void printQueue(int queue[], int size);

const int MAX = 3; // maximum size of queue

const char* MESSAGE_WELCOME = "Welcome to the FIFO Queue Program!";
const char* MESSAGE_GOODBYE = "Goodbye!";

const char* PROMPT_OPTION = "Enter option: ";
const char* PROMPT_INTEGER = "Integer: ";

const char* ERROR_OVERFLOW = "Error: Queue Overflow!";
const char* ERROR_INVALID_OPTION = "Invalid option.";

const char* LABEL_NOT_IN_QUEUE = " is not in the queue.";


// In your main(), an array of size 3 has been declared for you. 
// Using a small array will make it easier to debug all of the conditions. 
// You should then read user commands (input type char) and use the queue functions to manipulate the queue accordingly. 
// The program must support the following single-character commands: 
// +  Adds an integer into the rear of the queue. 
// -  Removes an integer from the front of the queue. All integers before are also removed (see sample run).
// p  Prints the queue.
// q  Quit.
// The queue should be printed using printQueue() after every command except q. 
// If an unknown command is entered, print an error message and DO NOT print the queue.
int main() {
    int queue[MAX]; // integer array for queue
    int size = 0;   // contains number of elements in queue

    cout << MESSAGE_WELCOME << endl;
    cout << endl;
    // Add your code here

    cout << endl;
    cout << MESSAGE_GOODBYE << endl;
    return 0;
}

// Inserts a value into the REAR of a queue of integers. 
// Takes three arguments: 
// queue  The array containing the queue 
// size  A reference to the number of elements in the queue 
// val  The value to insert 
// Returns 0 on success, 1 on overflow (queue is full, cannot add).
int enqueue(int queue[], int &size, int val){
    int status = TODO_STATUS_VALUE; // update in your code
    // add your code here
    cout << "TODO: int enqueue(int queue[], int &size, int val)" << endl; // Remove when done

    return status;
}

// Removes a value out of a queue of integers. 
// Integers are removed from the FRONT of the queue. 
// If the integer is in the queue, ALL integers before are also removed and the remaining elements are shifted to the FRONT of the queue.
// The first occurrence is removed if there are multiple occurrences.
// Takes three arguments: 
// queue  The array containing the queue 
// size  A reference to the number of elements in the queue 
// val  The integer to be removed from the queue
// Returns 0 on success, 1 on underflow (queue is empty, no values to dequeue), 2 if integer is not in the queue.
int dequeue(int queue[], int &size, int &val){
    int status = TODO_STATUS_VALUE; // update in your code
    // add your code here
    cout << "TODO: int dequeue(int queue[], int &size, int &val)" << endl; // Remove when done

    return status;
}

// Call this function to print the queue
void printQueue(int queue[], int size){
    cout << "[";
    for (int i = 0; i < size; i++){
        cout << queue[i];
        
        if (i != size - 1)
            cout << ", " ;
    }
    cout << "]" << endl;
}

