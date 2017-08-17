// ******************** PLEASE READ THE DOCUMENTATION BEFORE USING THESE FUNCTIONS *********************

// ABSTRACTION(OR DEVELOPED) BY: MOHAMMED MAAZ BIN KHAWAR
// if you find any bug or just want to contribute in this open source project
// just contact: maazproductions25@gmail.com or 03162627726

#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <vector>
using namespace std;

class dateAndTime{

public :
    int year()
    {
        time_t t = time(0);   // get time now
        struct tm * now = localtime( & t );
        return (now->tm_year + 1900);
    }
    string month()
    {
        time_t t = time(0);   // get time now
        struct tm * now = localtime( & t );
        string months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        return months[ (now->tm_mon) ];
    }
    string weekDay()
    {
        time_t t = time(0);   // get time now
        struct tm * now = localtime( & t );
        string months[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        return months[ (now->tm_wday) ];
    }
    int day()
    {
        time_t t = time(0);   // get time now
        struct tm * now = localtime( & t );
        return (now->tm_mday);
    }
    int hour()
    {
        time_t t = time(0);   // get time now
        struct tm * now = localtime( & t );
        return now->tm_hour;
    }
    int minute()
    {
        time_t t = time(0);   // get time now
        struct tm * now = localtime( & t );
        return now->tm_min;
    }
    int second()
    {
        time_t t = time(0);   // get time now
        struct tm * now = localtime( & t );
        return now->tm_sec;
    }
    string time12()
    {
    string mode, mint;
    short hr = hour();
    if(hr > 11)
    {
        if(hr!=12)
            hr = hr - 12;
        mode = "PM";
    }
    else
    {
        if(hr == 0)
            hr = 12;
        mode = "AM";
    }
    mint = to_string(minute());

    if(minute() < 10)
        mint = "0" + mint;


    return ( to_string(hr)+":"+mint+" "+mode );
    }

};

string center(string text)
{
    string spacing ="";
    if(text.size()>80)
        text.resize(80);
    spacing.resize( (( 80-text.size() )/2),' ' );
    return spacing + text;
}

string whiteSp(short num)
{
    string wspc = "";
    wspc.resize(num,' ');
    return wspc;
}

int validateInt(bool flag=1)
{
    int inp;
    string str;

    inp = getch();

    do
    {
    while(inp!=13)
    {
        if( (inp == 8)&&(!str.empty()) )
        {
            cout << "\b \b";
            str.pop_back();
        }
        else if (inp == 27)
            return 2147483647;
        else if(str.size()==10)
        {
            if(flag==1)
                cout << '\a';
        }
        else if( (inp>47 && inp<58) || (inp == 45 && str.empty()) )
        {
            str = str + (char)inp;
            cout << (char)inp;
        }
        else
        {
            if(flag==1)
                cout << '\a';
        }
        inp = getch();
    }

    if( !str.empty() && str!="-" && stod(str)<2147483647)
            return stoi(str);

    inp = getch();

    }//end do
    while(true);

}

int clrStrToCode(string clrName)
{
    int clrCode;
    string clrArr[] = {"Black","Blue","Green","Cyan","Red","Purple","Yellow","White","Gray","L Blue","L Green",
                        "L Cyan", "L Red", "L Purple", "L Yellow", "Bright White"};

    for(clrCode = 0; clrCode<16; ++clrCode)
    {
        if(clrName == clrArr[clrCode])
            return clrCode;
    }

    return -1;
}


int getCurrentClrCode(){
        CONSOLE_SCREEN_BUFFER_INFO info;
        GetConsoleScreenBufferInfo( GetStdHandle(STD_OUTPUT_HANDLE), &info );
        return info.wAttributes;
}

bool setBgClr(string BgClrName, int len = 2000)
{
    //Declarations :
    HANDLE stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD rCords = {0,0}, wCords;
    DWORD written = 0;
    short x,y, futureClr;
    vector<WORD> rAttr(len*sizeof(WORD));
    WORD wBgClr, wFgClr;

    //validating color name and assigning it's code to wBgClr
    if( clrStrToCode(BgClrName)>-1 )
        wBgClr = clrStrToCode(BgClrName);
    else
        return false; //Invalid background color name! So retaining previous background color.

    //saving attributes of entire console screen
    ReadConsoleOutputAttribute(stdout_handle, &rAttr[0], len, rCords, &written);

    //checking cell by cell to change the background color of each cell
    for(int i=0; i<len; ++i)
    {
        x = i%80;
        y = i/80;
        wCords = {x,y};

        if( rAttr[i] % 17 )
        {
            wFgClr = (wBgClr*16) + (rAttr[i]%16);
            WriteConsoleOutputAttribute(stdout_handle, &wFgClr, 1, wCords, &written);
        }
        else
        {
            WriteConsoleOutputAttribute(stdout_handle, &wBgClr, 1, wCords, &written);
        }
    }

    //setting future colors
    futureClr = (wBgClr*16) + (getCurrentClrCode()%16);
    SetConsoleTextAttribute(stdout_handle,futureClr);

    return true; //confirm that the background color has changed
}

bool setFgClr(string FgClrName, string BgClrName = " ")
{
    short newFgClr;

    if( (clrStrToCode(FgClrName)== -1)&&(clrStrToCode(BgClrName)== -1) )
        return false; // if color name is invalid then retain previous foreground color, new color can't be set!
    else if( clrStrToCode(BgClrName)== -1 )
        newFgClr = (getCurrentClrCode()/16)*16 + clrStrToCode(FgClrName);
    else if( clrStrToCode(FgClrName)== -1 )
        newFgClr = (clrStrToCode(BgClrName)*16) + (getCurrentClrCode()%16);
    else
        newFgClr = (clrStrToCode(BgClrName)*16) + (clrStrToCode(FgClrName));

    //setting new FG color.
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), newFgClr);
    return true; //confirming the color has been set.
}

void colorArea(string fgClrName, short x, short y, int units, string bgClrName = " ")
{
    short fgCode, bgCode, clrCode;

    if( (clrStrToCode(fgClrName) == -1)&&(clrStrToCode(bgClrName) == -1) || units<=0 )
        return;
    else if( clrStrToCode(bgClrName) == -1 )
        clrCode = (getCurrentClrCode()/16)*16 + clrStrToCode(fgClrName);
    else if( clrStrToCode(fgClrName) == -1 )
        clrCode = (clrStrToCode(bgClrName)*16) + (getCurrentClrCode()%16);
    else
        clrCode = (clrStrToCode(bgClrName)*16) + (clrStrToCode(fgClrName));

    HANDLE stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coords = {x,y};
    DWORD written = 0;
    vector<WORD> Attr(units*sizeof(WORD),clrCode);

    WriteConsoleOutputAttribute(stdout_handle, &Attr[0], units, coords, &written);
}


void Locate(short x, short y) {
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void cursorVisAndSize(bool visibility, short len = 20)
{
    if(len<1 || len>100)
        len = 10;
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = len;
    info.bVisible = visibility;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void WriteTextAtLoc(string text, short x, short y)
{
    HANDLE stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD written = 0;
    int len = text.size();
    COORD cords = {x,y};

    WriteConsoleOutputCharacter(stdout_handle,&text[0],len,cords,&written);
}

void clrdLine(string clr, short x1, short y1, short x2, short y2)
{
    short leastX, leastY;
    if(x1<x2)
        leastX = x1;
    else
        leastX = x2;
    if(y1<y2)
        leastY = y1;
    else
        leastY = y2;

    for(int i=0; i<abs(y2-y1); ++i)
        colorArea( clr,leastX,leastY+i,abs(x2-x1),clr );
}

