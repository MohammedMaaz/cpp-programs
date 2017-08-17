#include <iostream>
using namespace std;

int main()
{
    int currentNumber;

    cout << "Enter any integer: ";
    cin >> currentNumber;

    if((currentNumber%2) != 0)
        cout << endl << (currentNumber*3 + 1) << endl;
    else
        cout << endl << (currentNumber / 2) << endl;

    return 0;
}
