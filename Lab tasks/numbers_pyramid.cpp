#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int len, lim = 1, loopLen;

    cout << "Enter length of the pyramid (an integer less than 10): ";
    cin >> len;

    loopLen = len;

    for(int i=1; i<=loopLen; ++i)
    {
         cout << setw(len);

         for(int i=1; i<=(lim-1); ++i)
        {
            cout << i;
        }

        for (int i=0; i<lim; ++i)
        {
            cout << (lim-i);
        }

        cout << endl;

        lim = lim+1;
        len = len-1;
    }

    return 0;
}
