#include <iostream>
using namespace std;

int main()
{
    int num, sum=0;

    cout << "Enter an integer: ";
    cin >> num;

    sum = num;

    while(sum<=100)
    {
        cout << "Running sum = " << (sum) << endl << endl;
        cout << "Enter an integer: ";
        cin >> num;
        sum = sum + num;
    }

    cout << endl << "Sum exceeds 100. Program terminated." << endl;

    return 0;
}
