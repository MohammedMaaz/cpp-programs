#include <iostream>
using namespace std;

int main()
{
    for(int i=1; i<=2; ++i)
    {
        for(int i=1; i<=3; ++i)
        {
            cout << "*" << endl;

            for(int i=1; i<=5; ++i)
            {
                cout << "#";
            }

            cout << endl;
        }

        cout << endl << "==================" << endl;
    }

    return 0;
}
