#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double cost;
    int distance;

    cout << "Enter Distance: ";
    cin >> distance;

    if((distance >= 0) && (distance <= 100))
        cost = 5;
    else if((distance > 100) && (distance <= 500))
        cost = 8;
    else if((distance > 500) && (distance < 1000))
        cost = 10;
    else
        cost = 12;

    cout << endl << setprecision(2) << fixed << "\nThe cost is: " << cost << endl;

    return 0;
}
