#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int year;
    bool leapYear;

    cout << "Enter any year: ";
    cin >> year;

    if(year%4==0)
        leapYear = true;

    cout << leapYear;

    return 0;
}
