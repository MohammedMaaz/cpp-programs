#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string star = "*";
    int len, iter;

    cout << "Enter length of the star pyramid (an integer less than or equal to 40): ";
    cin >> len;

    iter = len;

    for(int i=1; i<=iter; ++i)
    {
        cout << setw(len) << star << endl;
        star = star + "**";
        len = len + 1;
    }

    return 0;
}
