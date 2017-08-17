#include <iostream>
using namespace std;

//use of getLine
int main()
{
    double cgpa;
    string name;

    cout << "Enter your cgpa: ";
    cin >> cgpa;

    cin.ignore(); // because getline function when used after cin does not work unless cin.ignore() is used.

    cout << "Enter Your Full name: ";
    getline(cin,name);

    cout << "\nName: " << name;
    cout << "\nCGPA: " << cgpa;

    return 0;
}
