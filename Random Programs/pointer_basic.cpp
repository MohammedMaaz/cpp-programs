#include <iostream>
using namespace std;

int main()
{

    int score = 5;
    int *scorePtr;
    scorePtr = &score;

    cout << scorePtr << endl;;
                           /* A pointer is a variable, with the address of another variable as its value
                              it is declared through datatype '*' before it's name. The address memory of
                              any variable is accessd through ampersand (&) function. */




    return 0;
}
