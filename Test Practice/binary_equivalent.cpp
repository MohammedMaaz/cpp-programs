#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int dec, bin, orig_dec;
    string result="", inc;

    cout << "Enter any decimal integer: ";
    cin >> dec; cout << endl;

    orig_dec = dec;

    cout << "The binary equivalent of " << orig_dec << " is ";

    if(dec!=0)
        cout << "1";
    else
        cout << "0";

    while(dec>1)
    {
        bin = dec%2;
        dec = dec / 2;
        if(bin == 1)
            inc = "1";
        else
            inc = "0";
        result = inc + result;
    }
    cout <<  result << endl;

    return 0;
}
