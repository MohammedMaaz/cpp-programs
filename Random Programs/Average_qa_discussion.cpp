#include <iostream>
using namespace std;

int main()
{
    double n1, n2, n3, sum;

    cout << "Enter first number: ";
    cin >> n1;

    while (n1 > 100 || n1 < 0)
    {
        cout << "\nTest score can't be greater than 100. Please enter a valid number: ";
        cin >> n1;
    }

    cout << "Enter second number: ";
    cin >> n2;

    while (n2 > 100 || n2 < 0)
    {
        cout << "\nTest score can't be greater than 100. Please enter a valid number: ";
        cin >> n2;
    }

    cout << "Enter third number: ";
    cin >> n3;

    while (n3 > 100 || n3 < 0)
    {
        cout << "\nTest score can't be greater than 100. Please enter a valid number: ";
        cin >> n3;
    }

    //normal average
    sum = n1 + n2 + n3;

    cout << "\n\nNormal average of three numbers is: " << (sum/3);

    //average with lowest dropped
    if(n1<=n2 && n1<=n3)
        sum = n2 + n3;
    if(n2<=n1 && n2<=n3)
        sum = n1 + n3;
    if(n3<=n1 && n3<=n2)
        sum = n1 + n2;

    cout << "\n\nAverage with lowest dropped is: " << (sum/2);

    //average with highest counting twice
    if(n1>=n2 && n1>=n3)
        sum = 2*n1 + n2 + n3;
    if(n2>=n1 && n2>=n3)
        sum = n1 + 2*n2 + n3;
    if(n3>=n1 && n3>=n2)
        sum = n1 + n2 + 2*n3;

    cout << "\n\nAverage with highest counting twice is: " << (sum/4) << endl;

	return 0;
}
