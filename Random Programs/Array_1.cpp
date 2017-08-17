#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double num, arr_1[10]; // array's capacity should be known premeditatively!

    cout << setw(63) << "Backward Table of any number through Array." << endl << endl;
    cout << "Enter any number: ";
    cin >> num;
    cout << endl;

    for(int i=0;i<=9;i++)
    {
        arr_1[i]= (i+1)*num;
    }

    for(int i=9;i>=0;--i)
    {
        cout << setw(41) << arr_1[i] << endl;
    }

    return 0;
}
