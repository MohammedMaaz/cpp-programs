#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double cf[4], fx, fx1, fx2, x[4];
    int _drop;

    cout << "Enter the coefficients (a,b,c,d) of the cubic polynomial: ";
    cin >> cf[0] >> cf[1] >> cf[2] >> cf[3];

    for(int i=0; i<4; ++i)
    {
        x[i] = cf[i];

        fx = (cf[0]*x[i]*x[i]*x[i]) + (cf[1]*x[i]*x[i]) + (cf[2]*x[i]) + (cf[3]);
        fx1 = (3.0*cf[0]*x[i]*x[i]) + (2.0*cf[1]*x[i]) + (cf[2]);
        fx2 = (6.0*cf[0]*x[i]) + (2.0*cf[1]);

        while( fabs(fx) > 0.0001 )
        {
            x[i] = x[i] - ( (2.0*fx*fx1)/( (2.0*fx1*fx1) - (fx*fx2) ) );
            fx = (cf[0]*x[i]*x[i]*x[i]) + (cf[1]*x[i]*x[i]) + (cf[2]*x[i]) + (cf[3]);
            fx1 = (3.0*cf[0]*x[i]*x[i]) + (2.0*cf[1]*x[i]) + (cf[2]);
            fx2 = (6.0*cf[0]*x[i]) + (2.0*cf[1]);
        }
    }

    for(int i=0; i<4; ++i)
    {
        for(int j=(i+1); j<4; ++j)
        {
            if(round(x[i])==round(x[j]))
            {
                _drop = i;
                break;
            }
        }
    }

    cout << "\nRoots are: \n";


    for(int i=0; i<4; ++i)
    {
        if(i!=_drop)
            cout << endl << x[i];
    }

    cout << endl;

    return 0;
}
