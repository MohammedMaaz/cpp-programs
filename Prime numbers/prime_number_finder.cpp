#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

string primeFinder(int a=2)
{
    for(int i=2; i<=(sqrt(a)); ++i)
    {
        if(a%i == 0)
        {
            return "Not a Prime number";
        }
    }
    return "Prime number";
}

int main()
{
    int num;

    cout << "This program tells whether a number is prime or not. Enter any no. to test it." << endl;
    cout << "Enter 0 to quit." << endl;

    do
    {
        cout << "\nEnter any positive integer: ";
        cin >> num;
        while(num < 0)
        {
            cout << "\nNumber can't be negative. Enter again: ";
            cin >> num;
        }

        if(num != 0)
            cout << endl << primeFinder(num);
    }
    while(num != 0);

    cout << endl;
    system("pause");

    return 0;
}
