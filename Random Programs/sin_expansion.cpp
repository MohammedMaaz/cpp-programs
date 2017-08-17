#include <iostream>
#include <cmath>
using namespace std;

unsigned long long int fact(int a)
{
    unsigned long long int f = a;
    for(int i=1; i<a; ++i)
        f = f*i;
    return f;
}

int main()
{
    double x, n=0, fx, pi=3.14159265;

    cout << "Enter the value of angle 'x' of sinx in degrees: ";
    cin >> x;

    x = x*pi/180;

    do
    {
        ++n;
        fx = pow(-1.0,n)*pow(x,(2.0*n+1.0))/fact(2*n+1);
        x = x + fx;
    }
    while( fabs(fx) > 0.0001);

    cout << endl << x;

    return 0;
}
