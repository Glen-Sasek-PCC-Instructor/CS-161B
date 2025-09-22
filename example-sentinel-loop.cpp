//This code demos sentinel while loops
//Read until user enters -1.
#include <iostream>
using namespace std;

const int CAP = 5;

//function prototypes
void printList(const int list[], int count);
void srchList(const int list[], int count);

int main() {
  int list[CAP] = {0}, userNum = 0, count = 0; 
  cout << "Enter numbers -1 to quit: ";
  cin >> userNum;
  while(userNum != -1 && count < CAP)
    {
      list[count++] = userNum;
      if(count < CAP)
      {
        cin >> userNum;  
      }
      else
      {
        cout << "List full!" << endl;
      }
    }  
  printList(list, count);
  srchList(list, count);
}

//prints the array
void printList(const int list[], int count)
{
  for(int i= 0 ; i < count; i++)
    {
      cout << list[i] << " ";
    }
    cout << endl;
}

//search the list
void srchList(const int list[], int count)
{
  int srchNum = 0, index = 0;
  cout << "Enter number to look for: ";
  cin >> srchNum;
  for(index = 0; index < count; index++)
    {
      if(list[index] == srchNum)
      {
        cout << "Number found at " << index << " !!" << endl;
        break;
      }
    }
   if (index == count)
      {
        cout << "Number not found!" << endl;
      }
}
