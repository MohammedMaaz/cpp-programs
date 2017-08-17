#include <iostream>
using namespace std;

//Square box
int main()
{
    int t=1;

    for(int i=1; i<=9; i++)
    {
        cout << "*";
        while(t<=7)
        {
           if(i==9||i==1)
           {
            cout << "*";
            t++;
           }
           else
           {
            cout<<" ";
            t++;
           }
        }
        t=1;
        cout << "*" << endl;
    }
    return 0;
}
