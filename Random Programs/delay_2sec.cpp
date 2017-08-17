#include <iostream>
#include <ctime>
using namespace std;

void delay2(void)
{
    double current_time = time(NULL);

    while( time(NULL) < (current_time + 2) )
    {

    }
}

int main()
{
    cout << "\t\t Printing numbers 1 to 10 with a delay of 2 seconds.\n\n";

    for(int i=1; i<=10; ++i)
    {
        cout << "\t\t\t\t\t" << i << endl;
        delay2();
    }

    return 0;
}
