# **CS 161B: Programming and Problem Solving II**

# Assignment 2: Encoder

Have you ever encountered a text encoder? Now you can write one yourself. This is the first term we are using D2L across the University as our learning management system. It will take some adjustment to get used to it. One thing I have found working with D2L is that it changes your file names when we download submissions. There is “some” logic to the file name it creates, and you are going to write a program to encode the fileNames\!\!

## Purpose

Your job is to design and create a program to allow for PCC to encode and build the file name for D2L. You should ask the user at the beginning if they are building the name of the file (encoding it) or if the program wants to quit.  Then, the user will need to enter in information to  
allow the program to build the encoded file name or quit.

After completing this assignment you will be able to:

* Use the cstring library for all appropriate string functions like strncpy(), strcat() etc.  
* Use arrays of characters (char arrays) or cstrings.  
* Apply the concept of overloaded functions, and functions with value and reference parameters.

## Task 		

* Complete zyBooks section **Chapter 10: CS 161B Char Arrays** activities.

* Before you get started check out these examples:

  * Example 1 \- [How to use **strncpy() and strcat()** functions.](https://github.com/Glen-Sasek-PCC-Instructor/CS-161B/blob/main/example-strncpy.cpp)

  * Example 3 \- [How to extract the numbers and convert them to a cstring.](https://github.com/Glen-Sasek-PCC-Instructor/CS-161B/blob/main/example-int-to-string.cpp)

* Your job is to design and create a program to allow for PCC to encode and build the file name for D2L.   
* You will need to obtain some information from the user:

  * The user’s last name, first name, if the assignment was late or not, their student ID, the file name, and the time of submission.

  * Use the functions below to get the information and output the encoded filename to the user.

## Required Functions

* **void welcome()** \- This function prints a welcome message to the user.

* **void displayMenu()**\- This function prints the menu to the user. Your menu must have 2 items \- Encode file name and quit. Here is an example:

  * (E)ncode a file name

  * (Q)uit

* **void readOption(char \&option)**. 

  * This function will read an option and return to the called function through the reference parameter.

  * You must do validation to make sure that the character is E/e or Q/q and nothing other than that. Use a while loop to do this.

* **void encode(char encodeFileName\[\])**

  * This should be a void function that takes 1 char array **encodeFileName**.

  * Declare appropriate local variables.

  * Call the **readInput()** function to read student’s names and lateFlag.

  * Call the **readInput()** function to read Student ID and filename.

  * Call the **readTime(**) function to read the submitted time. **(\*\*\*new for this level\*\*\*)**

  * Fill the **encodeFileName** array based on the six pieces of information adding underscores between.

  * Start with the student’s names, if the assignment is late, put LATE in the filename and nothing otherwise, add the parsed Student ID, add the time, without the colon, and then finally add the filename.

  * For example: If late: smith\_sue\_LATE\_5587\_1824\_prog2.c

  * If it is not late: smith\_sue\_5587\_1824\_prog2.c

* **void readInput(char fName\[\], char lName\[\], bool \&lateFlag) \- overloaded function**

  * This void function should take 2 char arrays and 1 bool variable by reference.

  * It reads the student’s first name, last name and if the assignment is late or not. Student last name (e.g. Smith) **(char array).** Student first name (e.g. Sue) **(char array)**

  * Make sure all character data for the student’s name is lowercase \- you may write a function to convert a cstring to all lowercase.

  * If the assignment was late or not (e.g., Y or N) **(bool var)**. Must do data validation for this.

  * ***Hint: Remember an overloaded function has the same function name but different types of parameters or the number of parameters are different.***

* **void readInput(char parsedID\[\], char fileName\[\]) \- overloaded function**

  * This void function should take 1 char array for the parsed 4 digit Student ID that will be returned and another char array for the filename.

  * The Student ID (e.g., 977-15-5587) **(char array)** is a local variable. Use the strncpy() function to copy from position 7 till the end of the string. **strncpy(parsedID, stdID \+ 7, 4\)** will copy 4 characters from the 7th position in the stdID string to the parsedID string. 

  * The name of the file (e.g., prog2.cpp) **(char array)**

* **void readTime(char strTime\[\]) (\*\*\*new for this level\*\*\*)**

  * This is a void function that should read the time from the user as 2 integers and return one char array by reference (that is the strTime array).

  * The time read from the user will be in military time (e.g.. 18:24 for 6:24pm) **(2 ints, one for hour and one for mins).** Check out this [example code file](https://replit.com/@GDIyer/convert-int-to-string#main.cpp) to extract the numbers and convert them to a cstring. This example is not quite sophisticated. You must do data validation by checking the hours are between 0 and 24 and the minutes are between 0 and 60\.

  * This function must do data validation for the numbers and the HH:MM format. Make sure the colon : is used to separate the mins and hours.

* **int main()**

  * Declare appropriate local variables.

  * In an appropriate loop call the functions and output the encoded file name.

  * Repeat the menu in the loop until the user chooses to quit.

  * main() should do nothing more than the above steps.

* To get started, open the [Assignment Template File](https://github.com/Glen-Sasek-PCC-Instructor/2025-06-22/blob/main/main.cpp), and make a copy.

* Complete all sections of the Assignment Template File. 

* You must express your algorithm as **pseudocode.** [Pseudocode Reference](https://github.com/Glen-Sasek-PCC-Instructor/2025-06-22/blob/main/Pseudocode-Reference.txt)


## Criteria for Success 
Test your program using the following sample runs, making sure you get the same output when using the given inputs:


```
Welcome to my fileName encoding program!!
Please pick an option below:
(e)Encode a file name
(q)quit
>>e
This program will ask you a few questions and generate an encoded fileName based on your answers.
Enter your last name: Iyer
Enter your first name: GD
Was your assignment Late (y/n)? Y
Enter your Student-ID (format: 222-22-2222): 234-05-4556
Enter the file name: a05.cpp
Enter the time submitted (military time - ex: 18:24 for 6:24pm): 13:45
Your encoded file name is: iyer_gd_LATE_4556_1345_a05.cpp
Please pick an option below:
(e)Encode a file name
(q)quit
>>b
Invalid option! Please try again!!
Please pick an option below:
(e)Encode a file name
(q)quit
>>q
Thank you for using my fileName generator!
```

* Additional tests of your design.

## Coding Construct Requirements:

  * **You may not use any other data structures or complex types such as strings, or other data structures such as Vector.** **Use only the concepts and functions we have learned so far. You can use local temporary variables for char arrays.**

  * Try not to have any redundant code (repeated code) in your program. That is the purpose of functions.

  * Your program must have function prototypes. Place the prototypes for your functions globally, after your \#includes. **All functions must be implemented after main()**. 

  * Must do data validation where appropriate and where required in the functions above.

  * Must read the time as 2 ints and the convert to a char array. Must do data validation for this function. Check the functions under Task.

  * Student’s first name and last name should be lower case.

  * Print a welcome and goodbye message.
