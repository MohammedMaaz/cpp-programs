#include <iostream>
#include <stdlib.h>
using namespace std;

// rand() function generates a random number and is present in the cstdlib or stdlib.h
int main()
{
    cout << rand() << endl; // rand returns an integer value and must not have any arguments. However every time it returns the
                    // same sequence of values.

    cout << 1 + (rand()%8) << endl; // generates numbers only in the range of 1 to 8;

    srand(98); // generates diff. value for rand on diff. arguments, the argument act as a seeding value. Now if rand()
               // is used it will give a different series of numbers.

    cout << rand();

    return 0;
}
