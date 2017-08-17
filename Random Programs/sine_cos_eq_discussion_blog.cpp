#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, y, pi =3.141592654;

    cout << "Enter the value of x (0 to 0.1 radians): ";
    cin >> x;

    while (x<0 || x>0.1)
    {
        cout << "\nInvalid value, enter a value between 0 and 0.1: ";
        cin >> x;
    }

    y = (10.5*sin(2*pi + x))*(cos(3.5*pi + x));

    cout << "\n\nValue of y = " << y << endl;

    return 0;
}
