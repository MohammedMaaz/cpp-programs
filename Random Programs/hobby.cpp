#include <iostream>
using namespace std;

int main()
{
    int var = 6;
    int *p=&var; // This * is for declaring the type pointer.

    cout << &var << endl;

    cout << *p << endl; // while this * is totally different thing,it returns the value of the variable in the pointer.

    return 0;

    /* Note that a pointer say 'p' points to the memory of it's variable, while the *p (also called derefrencing)
       is simply the new name (alias) of the variable itself. */
}
