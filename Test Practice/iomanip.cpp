#include <iostream>
#include <iomanip>
using namespace std;

//setprecision, setw, fixed, scientific.
int main()
{
    double pi = 3.15942356124, planck = 6.62607004e-34, i = 2;

    cout << "*********** Without setprecision ************\n\n";
    cout << " pi = " << pi << "   Planck's constant = " << planck << endl << endl << endl;

    cout << "*********** With a precision of 10 ************\n\n";
    cout << " pi = " << setprecision(10) << pi;
    cout << "   Planck's constant = " << planck << endl;

    cout << endl << left << setw(12) << " Default:" << right << setw(18) << i;
    cout << endl << left << setw(12) << " Fixed:" << setw(18) << right << fixed << i;
    cout << endl << left << setw(12) << " Scientific:" << setw(18) << right << scientific << i << endl;

    return 0;
}
