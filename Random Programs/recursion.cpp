#include <iostream>
using namespace std;

// A recursive function is a function that calls itself, and to avoid recursion infinitely a termination condition is reqd.

int factorial(int n) {
  if (n==1 || n==0) {
    return 1; // This is the terminate condition of the recursion also called the base condition.
  }
  else {
    return n * factorial(n-1); // here the function is called again and it continues to be called unless n becomes 1.
  }
}

int main()
{
    int num;

    cout << "Enter any number to calculate it's factorial: ";
    cin >> num;

    cout << endl << "The factorial of " << num << " is " << factorial(num) << endl;

    return 0;
}
