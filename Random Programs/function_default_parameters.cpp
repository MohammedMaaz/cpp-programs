#include <iostream>
using namespace std;

/* we can specify default values to any argument of the function. If while recalling the function any argument is not
   given then the default value will be used. */

int product(int a=1, int b=2)
{
    return a*b;
}

int main()
{
    cout <<  product(2,3) << endl;
    cout << product(2) << endl;
    cout << product() << endl;

    return 0;
}
