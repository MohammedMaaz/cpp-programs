#include <iostream>
using namespace std;

int main()
{
    int m,n,x;
    cout<<"enter decimal number "<<endl;
    cin>>n;
    m=n;
    while (n>0)
    {
       x=n%2;
       n=n/2;
       cout<<x;
    }
    return 0;
}
