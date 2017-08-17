#include <iostream>
using namespace std;

 void function1(string x) /* parameter must be a variable. */
    {
        cout << x << endl;
    }

    int function2(int x) /* the return value will be double of the argument */
    {
        return x*2;
    }

int main()
{
   function1("Maaz");

   cout << function2(26);

   return 0;
}
