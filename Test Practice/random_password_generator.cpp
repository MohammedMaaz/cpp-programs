#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

int main()
{
    cout << endl << "                    ******** RANDOM PASSWORD GENERATOR ******** " << endl << endl << endl;

    srand(time(0));

    char ele[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y',
                  'z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X',
                  'Y','Z','1','2','3','4','5','6','7','8','9','0'} , ch;
    string pass;
    int length;

    cout << "What should be the length of the password? ";
    cin >> length;

    while((length <4)||(length > 40))
    {
        cout << "\nLength must be an integer between 4-40, input again: ";
        cin >> length;
    }

    do
    {
        for(int i=1; i<=length; i++)
        {
           pass = pass + ele[(rand()%62)];
        }
        cout << endl << pass << endl;

        pass = "";

        cout << "Generate again? (y/n): ";
        cin >> ch;
    }
    while((ch=='y')||(ch=='Y'));

    return 0;
}
