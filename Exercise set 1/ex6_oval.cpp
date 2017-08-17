#include <iostream>
using namespace std;

int main()
{
    for(int test=1; test<=9;test++)
    {
        switch(test)
    {
        case (1) :
        for(int i=1; i<=9; i++)
        {
            if(i<=3||i>6)
                cout << " ";
           else
                cout << "*";
        }
        break;

        case (9) :
        for(int i=1; i<=9; i++)
        {
            if(i<=3||i>6)
                cout << " ";
           else
                cout << "*";
        }
        break;

        case (2) :
        cout << "\n *";
        for (int i=1; i<=5; i++)
        {
            cout << " ";
        }
        cout << "*";
        break;

        case (8) :
        cout << "\n *";
        for (int i=1; i<=5; i++)
        {
            cout << " ";
        }
        cout << "*\n";
        break;

        default:
        cout << "\n*";
        for (int i=1; i<=7; i++)
        {
            cout << " ";
        }
        cout << "*";
    }

    }

    return 0;
}
