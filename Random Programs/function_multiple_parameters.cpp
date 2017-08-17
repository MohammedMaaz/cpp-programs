#include <iostream>
using namespace std;

int sum(int x, int y) // parameters must be separated by a comma.
{
    return (x+y);
}

int main()
{
    int a, b, result;

    cout << "Enter any two numbers: ";
    cin >> a >> b;

    result = sum(a,b); //also arguments must also be separated by commas when calling a function.

    cout << endl << "Sum of " << a << " and " << b << " is " << result << endl;

    return 0;
}
