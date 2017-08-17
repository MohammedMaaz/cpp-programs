#include <iostream>
using namespace std;

int main()
{
    string str1 = "Pakistan";

    cout << "substring" << endl;
    cout << str1.substr(0,3) << endl << str1.substr(3);

    cout << endl << endl << "find and rfind";
    cout << endl << str1.find("ist") << endl << str1.rfind("a");

    cout << endl << endl << "size";
    cout << endl << str1.size(); //no argument required.

    cout << endl << endl << "erase";
    cout << endl << str1.erase(3,5);

    str1 = "Pakistan"; //because erase also modified the str1

    cout << endl << endl << "replace";
    cout << endl << str1.replace(0,3,"Bak") << endl;
    str1 = "Pakistan"; cout << str1.replace(0,3,"Baloch");



    return 0;
}
