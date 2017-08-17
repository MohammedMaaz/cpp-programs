#include <iostream>
using namespace std;

// an array can also be used in a function as argument. The parameter should be defined as an array with sq. brackets.

void printArray(int arr[], int size)
{
  for(int x=0; x<size; x++)
  {
    cout <<arr[x]<< endl;
  }
}
int main()
{
    int myArr[5]= {42, 33, 88, 17, 23};
    printArray(myArr, 3);

    return 0;
}
