#include <iostream>
using namespace std;

int main()
{
    int n1, n2, n3, n4, n5, maxi;

    cout << "Enter 5 numbers: ";
    cin >> n1 >> n2 >> n3 >> n4 >> n5;

    maxi = n1;

    if (maxi < n2)
        maxi = n2;
    if(maxi < n3)
        maxi = n3;
    if (maxi < n4)
        maxi = n4;
    if (maxi < n5)
        maxi = n5;

    cout << "\n\nGreatest no. is: " << maxi << endl;

    return 0;
}
