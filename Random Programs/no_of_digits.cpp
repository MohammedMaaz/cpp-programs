#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int num, counter=-1;
    cout << "Enter an integer: ";

    while(num!=13)
    {
        num = getch();
        if((num==48)||(num==49)||(num==50)||(num==51)||(num==52)||(num==53)||(num==54)||(num==55)||(num==56)||(num==57)||(num==13))
        {
           cout << (char)num;
            ++counter;
        }
    }
    cout << endl << "No. of digits = " << counter << endl;

    return 0;
}
