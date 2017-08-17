#include <iostream>
using namespace std;

int main()
{
    long long a;

    int b =0;

    cin >> a;

    while(a!=0)
    {
        b++;
        a= a/10;
    }

    cout << b;

    return 0;
}
