#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int n1=0, n2=0, n3=0, n4=0, n5=0, n6=0;

    cout << endl;

    for(int i =1; i<=64; ++i)
    {
        cout << n1 << n2 << n3 << n4 << n5 << n6 << ", ";

        n6 = n6 + 1;

        if(n6>1)
        {
            n6=0;
            n5 = n5+1;
        }
        if(n5>1)
        {
            n5=0;
            n4 = n4+1;
        }
        if(n4>1)
        {
            n4=0;
            n3 = n3+1;
        }
        if(n3>1)
        {
            n3=0;
            n2 = n2+1;
        }
        if(n2>1)
        {
            n2=0;
            n1 = n1+1;
        }
    }

    cout << endl;

    return 0;
}
