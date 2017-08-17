#include <iostream>
using namespace std;

/* A function is a group of statements doing a particular task. Mostly functions return a value, but some functions
   need not to return a value they are defined by the void keyword. void is a valueless state. */

/* Function's basic syntax: return_type name(parameters-optional)
   {
    body of the function
   }
*/

void testFunction() //making a function with no return type and parameters. Declaring a function in main() isn't allowed.
    {
        cout << "Test Function" << endl;
    }

    /* Just like a variable a function can be declared before and it's body can be assigned afterwards. */

int main()
{

    testFunction(); //To call a function, you need to pass the required parameters and function name.

    return 0;
}
