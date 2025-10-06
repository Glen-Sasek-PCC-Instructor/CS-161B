# **CS 161B: Programming and Problem Solving II**

# Assignment 4: Course Rosters

## Purpose

In this assignment, you will write a program that uses arrays to represent a list of courses and students enrolled in them and manipulate those arrays.

You will:

1. Write a program to read course numbers (a string of text) and the number of students enrolled (int) in the course into 2 parallel arrays.  
2. Once the data has been read, you will need to cancel all courses where the number of students is less than 10\. You will go through the lists, find the courses that have enrollment below 10 and remove them from the lists.  
3. The maximum number of students that can be enrolled in a course is less than or equal to 25\.  
4. The maximum number of courses you can have is 20\. The maximum number of characters you can have for a course is 51\.

After completing this assignment you will be able to:

* Shift elements in array(s) to insert or delete elements  
* Use a for loop to manipulate the array(s) without going out of bounds  
* Pass arrays and their size to a function and manipulate the arrays

## Task 

* Before you get started:

  * Check out Sample Assignment A04 \- [SampleA04.cpp](https://github.com/Glen-Sasek-PCC-Instructor/CS-161B/blob/main/SampleA04.cpp)

  * Check out the sample for [inserting into an array](https://github.com/Glen-Sasek-PCC-Instructor/CS-161B/blob/main/example-insert-sorted-into-arrays.cpp) in the right position. 

* Your job is to create a program that will read course numbers (c-string or text data type) and number of students enrolled in that course (int data type) from the user. You will then call a function to cancel or remove courses that have less than 10 students enrolled in them.

* You must have functions to do the following:

* **void welcome()** \- This function prints a welcome message to the user.

* **void readInput(char courseNums\[\]\[MAXCHAR\], int students\[\], int \&count)** 
  1. This function takes an array of c-strings, and an array of ints and reads the course numbers and students enrolled from the user.  
  2. Read until the user enters “Quit” or “quit” for the course number. The SampleA04.cpp should help you do this. Read the corresponding number of students enrolled.   
  3. Call the **readInt** function to read the number of students for each course number. You must catch all invalid data such as characters, negative numbers etc.

  4. You must also do validation to make sure that the number is between 0 and 25\. The maximum number of students that can be enrolled in a course is less than or equal to 25\. Use a while loop to do this.

  5. Insert the course number and the number of students in the right position based on the course number. **You must not use any sorting algorithm. Insert the course numbers and its students in the right position, by finding the position and shifting the other courses. See sample run below.**  
  6. **count** will keep track of the number of courses entered.  
  7. Test your function with at least 10 courses to make sure that the insertion works correctly.  
* **void readInt(string prompt, int \&num)**
  1. This function should be used any time you read any integers from the user. Use this function to read the menu option from the user.

* **void printList(char courseNums\[\]\[MAXCHAR\], int students\[\], int count)**  
  1. This function takes the 2 arrays and count, uses a for loop and prints the lists to the user.  
  2. Format your list neatly.  
* **void cancelCourses(char courseNums\[\]\[MAXCHAR\], int students\[\], int \&count)**  
  1. This function takes the 2 arrays and the count and removes all courses with less than 10 students in the course.  
  2. You must use a for loop, find the index where the number of students is less than 10, and then remove that number and the corresponding course number from the char array by shifting elements in both the arrays.  
  3. Update the count appropriately. If you cancel or remove 3 courses, then count should be subtracted by 3, so the number of courses is updated.  
* **int main()**  
  1. Declare the arrays for course numbers and students.  
  2. Call the **readInput()** function and get the arrays filled. **The list must be ordered by the course numbers. This is important for this grade level.**  
  3. Call the **printList()** function and print the course numbers and students neatly formatted.  
  4. Call the **cancelCourses()** function and cancel the courses with less than10 students in them.  
  5. Call the **printList()** function again and print the course numbers and students neatly formatted.  
  6. End your program.  

* To get started, open the [Assignment Template File](https://github.com/Glen-Sasek-PCC-Instructor/2025-06-22/blob/main/main.cpp), and make a copy.

* Complete all sections of the Assignment Template File. 

* You must express your algorithm as **pseudocode.** [Pseudocode Reference](https://github.com/Glen-Sasek-PCC-Instructor/2025-06-22/blob/main/Pseudocode-Reference.txt)


## Criteria for Success

* Look at the sample run below. Use the function prototypes you will need for the various options (your list may include other options):

```
Welcome to my Course Rosters program!!
Enter course number and students enrolled when prompted. Enter Quit or quit for course number when you are done.
Enter course number: CS133G
Number of students enrolled: 7
Enter course number: CS160
Number of students enrolled: 15
Enter course number: CS161A
Number of students enrolled: 21
Enter course number: CS161B
Number of students enrolled: 23
Enter course number: CS162
Number of students enrolled: 30
Invalid number!! Please enter a number between 0 and 25
Number of students enrolled: 25
Enter course number: CS260
Number of students enrolled: 5
Enter course number: Quit

List of courses and students:
CS133G          7
CS160           15
CS161A          21
CS161B          23
CS162           25
CS260           5

List after cancellations:
CS160           15
CS162A          21
CS161B          23
CS162           25

Thank you for checking out my Course Rosters program!
```

```
Welcome to my Course Rosters program!!
Enter course number and students enrolled when prompted. Enter Quit or quit for course number when you are done.
Enter course number: CS133G
Number of students enrolled: 7
Enter course number: CS160_1
Number of students enrolled: 15
Enter course number: CS161A_1
Number of students enrolled: 21
Enter course number: CS161B
Number of students enrolled: 23
Enter course number: CS162
Number of students enrolled: 30
Invalid number!! Please enter a number between 0 and 25
Number of students enrolled: 25
Enter course number: CS260
Number of students enrolled: 5
Enter course number: CS160_2
Number of students enrolled: 7
Enter course number: CS161A_2
Number of students enrolled: 25
Enter course number: quit

List of courses and students:
CS133G          7
CS160_1         15
CS160_2         7
CS161A_1        21
CS161A_2        25
CS161B          23
CS162           25
CS260           5

List after cancellations:
CS160_1         15
CS161A_1        21
CS161A_2        25
CS161B          23
CS162           25

Thank you for checking out my Course Rosters program!
```

* Complete zyBooks section **Chapter 11: Sections 11.12 to 11.14 CS 161B Arrays** activities, and **zyLabs 11.17 and 11.18.**

* You may use any IDE to write your code. But to be successful in future CS classes use the Linux server as much as you can.

* Please bookmark the [PCC Linux and Vim Manual](https://docs.google.com/document/d/1Ap4xFkNUkUbi7kYteg0KEIu9I9_hAuDZBtubA3ExxLM/edit?usp=sharing) \- this will become a frequently used reference\!
