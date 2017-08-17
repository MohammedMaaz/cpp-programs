#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

int primeFinder(int a=2)
{
    for(int i=2; i<=(sqrt(a)); ++i)
    {
        if(a%i == 0)
        {
            return 0;
        }
    }
    return a;
}

int main()
{
    cout << endl << "\t ******************* PRIME NUMBERS FINDER ***********************" << endl << endl;
    cout << "This program finds prime numbers with in a specified range. Set the lower and upper limits to find"
            << " the prime numbers within that range." << endl << endl;

    int upperLim, lowerLim, k, num;

    do
    {
        cout << "Set lower limit: ";
        cin >> lowerLim;
        cout << "Set upper limit: ";
        cin >> upperLim;
        if(upperLim<lowerLim)
            cout << "\nlower limit can not be greater than upper limit.\n\n";
    }
    while(upperLim<lowerLim);

    for(num = lowerLim ; num <= upperLim; ++num)
    {
        k = primeFinder(num);
        char ch;
        if (k != 0)
        {
            cout << endl << num << endl;



        }
    }
    if(num >= upperLim)
        cout << endl << "Upper limit exceeded! No more prime numbers in the given range.";

    cout << endl;
    system("pause");
    return 0;
}
