#include <iostream>
using namespace std;

/* There are two methods of passing arguments to the function :

1. By value : in this case the copy of the original argument is provided to the function when it is called. And after the
   function's execution there is no effect on the original value of argument.

2. By reference : This method copies the reference of an argument into the formal parameter of the function. So changes
   made to the parameter also change the argument.
*/

void myFunc(int x)
{
  x = 100;    // parameter is changed! Now see what happens when function is called by value.
}
void myFunc(int *x)
{
  *x = 100;    // parameter is changed! Now see what happens when function is called by reference.
}

int main()
{
    int var = 20;
    myFunc(var);  // argument is passed by value, so there will be no effect on it.
    cout << "Argument was passed by value so it's value remains " << var << " although the parameter has been changed to 100" << endl << endl;

    int var1 = 20;
    myFunc(&var1); // argument is passed by reference, so it will be changed because the parameter has changed.
    cout << "Argument was passed by reference so it's value changes to " << var1 << " because the parameter has been changed to 100" << endl ;

    return 0;
}
