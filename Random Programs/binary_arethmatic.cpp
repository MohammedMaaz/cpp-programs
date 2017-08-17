#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long int btod(long long int bin)      // Binary to Decimal Converter
{
    long dec = 0, rem, base = 1;

    while (abs(bin) > 0)
    {
        rem = bin % 10;
        dec = dec + rem * base;
        base = base * 2;
        bin = bin / 10;
    }

    return dec;
}

long long int dtob(long int num)             // Decimal to Binary Converter
{
    long rem,i=1,sum=0, dec= abs(num);

    do
    {
        rem=dec%2;
        sum=sum + (i*rem);
        dec=dec/2;
        i=i*10;
    }
    while(dec>0);

    return sum;
}



long double binArith(long long int val1=1, char oper='+',long long int val2=1)
{
    int dec1 = btod( abs(val1) ), dec2 = btod( abs(val2) );

    if(oper != '+' && oper != '-' && oper != '*' && oper != '/')
        return sqrt(-1.0);

    switch(oper)
    {
    case '+' :
        {
            return ( dtob(dec1 + dec2) );
        }
    case '-' :
        {
            return ( dtob(abs(dec1 - dec2)) );
        }
    case '*' :
        {
            return ( dtob(dec1 * dec2) );
        }
    case '/' :
        {
            if(dec2 == 0)
                return sqrt(-1.0);
            else
            return ( dtob(dec1 / dec2) );
        }
    }
}


int main()
{
    int num = 000000;
    string str;

    for(int i=0; i<63; ++i)
    {
        num = binArith(num,'+',1);
        str = to_string(num);
        while(str.size()!=6)
        {
            str.insert(0,"0");
        }
        cout << str << endl;
    }

    return 0;
}
