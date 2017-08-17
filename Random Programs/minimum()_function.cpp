#include <iostream>
using namespace std;

int minimum(int a, int b, int c)
{
    if( (a<=b)&&(a<=c) )
        return a;
    else if ( (b<=a)&&(b<=c) )
        return b;
    else
        return c;
}

int main()
{
    int a,b,c;

    cout << "Enter any 3 integers: ";
    cin >> a >> b >> c;

    cout << "\nSmallest integer is: " << minimum(a,b,c) << endl;

    return 0;
}
