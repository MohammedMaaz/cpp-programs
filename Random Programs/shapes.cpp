#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<console_formatting.h>
#include<windows.h>
#include<algorithm>
using namespace std;

void pyramid(int s=9, bool center=false, int offset=0)
{
    if(s%2 == 0)
        ++s;
    if(center)
        offset = (80-s)/2;
    int mid = s/2;
    string str, offsetStr;
    str.resize(s,' ');
    offsetStr.resize(offset,' ');
    for(int i=0;i<s/2+1;++i)
    {
        str[mid-i] = '*';
        str[mid+i] = '*';
        cout << offsetStr << str << endl;
    }
}

void diamond(int s=9, bool center=false, int offset=0)
{
    if(s%2 == 0)
        ++s;
    if(center)
        offset = (80-s)/2;
    int mid = s/2;
    string str, offsetStr;
    str.resize(s,' ');
    offsetStr.resize(offset,' ');
    for(int i=0;i<s;++i)
    {
        if(i<=s/2)
        {
            str[mid-i] = '*';
            str[mid+i] = '*';
        }
        else
        {
            str[mid-(s-i)] = ' ';
            str[mid+(s-i)] = ' ';
        }
        cout << offsetStr << str << endl;
    }
}

void sinusoid(int amp=10, int T=20, int phaseShift=0, char fgChar='.', string fgClr="Bright White", char bgChar=' ', string bgClr="Black", bool scale=false)
{
    system("cls");

    if(amp==0 || T==0)
        return;

    int x_limit = 80;
    string sinStr[2*amp][x_limit];
    double pi = 3.141593;

    //if fgChar == bgChar then this line will eliminate this issue
    bgChar = bgChar + 1;

    //filling with bgChar
    for(int i=0; i<2*amp; ++i)
    {
        for(int j=0; j<x_limit; ++j)
            sinStr[i][j] = bgChar;
    }

    //marking *
    for(int t=0; t<T*x_limit; t=t+T)
    {
        int vt = amp*sin(t*pi/180 + pi*(1 + phaseShift/180.0));
        sinStr[vt+amp][t/T] = fgChar;
    }

    //printing string array
    for(int i=0; i<2*amp; ++i)
    {
        for(int j=0; j<x_limit; ++j)
        {
            string str; str.push_back(fgChar);
            if(sinStr[i][j]==str)
            {
                setFgClr(fgClr);
                cout << fgChar;
            }
            else
            {
                setFgClr(bgClr);
                cout << (char)(bgChar-1);
            }
        }
    }

    if(bgChar-1 == ' ')
        setBgClr(bgClr, 10000);


    if(scale)
    {
        setFgClr(fgClr);
        cout << endl << "0000";
        for(int i=1; i<16; ++i)
            cout << setw(4) << i*(T*x_limit/16) << " ";
    }

    //resetting default foreground color
    setFgClr("White");
}

int main()
{
    sinusoid(10,15,0,'.',"White");

    return 0;
}
