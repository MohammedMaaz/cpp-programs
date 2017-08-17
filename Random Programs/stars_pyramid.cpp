#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string star = "*";
    int len = 4;

    for(int i=1; i<=4; ++i)
    {
        cout << setw(len) << star << endl;
        star = star + "**";
        len = len + 1;
    }

    return 0;
}
