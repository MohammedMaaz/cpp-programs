#ifndef CASHMANAGER_H
#define CASHMANAGER_H

#include <string>
#include <conio.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <vector>
#include <thread>
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


private :
    //time_t t = time(0);   // get time now
    //struct tm * now = localtime( & t );

};


string center(string text)
{
    string spacing ="";
    if(text.size()>80)
        text.resize(80);
    spacing.resize( (( 80-text.size() )/2),' ' );
    return spacing + text;
}


string whiteSp(int num)
{
    string wspc = "";
    wspc.resize(num,' ');
    return wspc;
}


int validateInt()
{
    int inp;
    string str;

    inp = getch();

    do
    {
    while(inp!=13)
    {
        if( (inp>47 && inp<58) || (inp == 45 && str.empty()) )
        {
            str = str + (char)inp;
            cout << (char)inp;
        }
        else if( (inp == 8)&&(!str.empty()) )
        {
            cout << "\b \b";
            str.pop_back();
        }
        else if (inp == 27)
            return 2147483647;
        else
        {
            cout << '\a';
        }
        inp = getch();
    }

    if( !str.empty() && str!="-" )
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


void YArrowFunc(short pos)
{
    for(int i=0; i<4; ++i)
    {
        colorArea("White",32,5+2*i,40);
        colorArea("Black",31,5+2*i,1);
    }
    Locate(31,5+2*pos);
    cout << (char)175;
    colorArea("Bright White",31,5+2*pos,40);
}


void WriteTextAtLoc(string text, short x, short y)
{
    HANDLE stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD written = 0;
    int len = text.size();
    COORD cords = {x,y};

    WriteConsoleOutputCharacter(stdout_handle,&text[0],len,cords,&written);
}


void DateThread(void)
{
    dateAndTime now;

        WriteTextAtLoc( now.weekDay()+", "+now.month()+" "+to_string(now.day())+", "+to_string(now.year()) ,56,0 );
        WriteTextAtLoc( now.time12(),56,1 );

    colorArea("White",56,0,24);
    colorArea("White",56,1,24);

    Sleep(950);

    DateThread();
}


void Header(string title, string FgClr)
{
    system("CLS");
    cout << center(title) << "\n\n";
    colorArea( FgClr, ((80-title.size())/2), 0, title.size() );
}


short ArrKeyEvents(short limY, void (*f1)(short), void (*f2)(short) = nullptr, short limX=0, void (*f3)(short) = nullptr, void (*f4)(short) = nullptr)
{
    short posX=0, posY=0;
    cursorVisAndSize(false); //hiding cursor

    while( 1 )
    {
        short BufferKey = getch();
            if(BufferKey==13)
                return (posX*10)+posY;
            else if(BufferKey==27)
                return -1;
        switch((getch()))
        {
        case 72:
            if(posY > 0 && posY <= limY) //UP
            {
                --posY;
                (*f1)(posY);
            }
            break;
        case 80:
            if(posY >= 0 && posY < limY) //DOWN
            {
                ++posY;
                (*f2)(posY);
            }
            break;
        case 77:
            if(posX >= 0 && posX < limX) //RIGHT
            {
                ++posX;
                (*f3)(posX);
            }
            break;
        case 75:
            if(posX >0 && posX <= limX) //LEFT
            {
                --posX;
                (*f4)(posX);
            }
            break;

        } //switch ends
    } //while ends
}



/*int arrowKeyEvents( void (*thread)(void), short limY, void (*f1)(short), void (*f2)(short) = nullptr, short limX=0, void (*f3)(short) = nullptr, void (*f4)(short) = nullptr )
{
    short posY=0, posX=0;
    dateAndTime now;
    thread();

    HANDLE rhnd = GetStdHandle(STD_INPUT_HANDLE);  // handle to read console

    DWORD Events = 0;     // Event count
    DWORD EventsRead = 0; // Events read from console
    bool Running = true;

    while(Running)
    {
        // gets the systems current "event" count
        GetNumberOfConsoleInputEvents(rhnd, &Events);

        if(Events)  // if something happened we will handle the events we want
        {
            // create event buffer the size of how many Events
            INPUT_RECORD eventBuffer[Events];

            // fills the event buffer with the events and saves count in EventsRead
            ReadConsoleInput(rhnd, eventBuffer, Events, &EventsRead);

            // loop through the event buffer using the saved count
            for(DWORD i = 0; i < EventsRead; ++i)
            {
                // check if event[i] is a key event && if so is a press not a release
                if(eventBuffer[i].EventType == KEY_EVENT && eventBuffer[i].Event.KeyEvent.bKeyDown)
                {
                    switch(eventBuffer[i].Event.KeyEvent.wVirtualKeyCode)
                    {
                        case VK_UP:
                            if(posY > 0 && posY <= limY)
                            {
                                --posY;
                                (*f1)(posY);
                            }
                            break;
                        case VK_DOWN:
                            if(posY >= 0 && posY < limY)
                            {
                                ++posY;
                                (*f2)(posY);
                            }
                            break;
                        case VK_RIGHT:
                            if(posX >= 0 && posX < limX)
                            {
                                ++posX;
                                (*f3)(posX);
                            }
                            break;
                        case VK_LEFT:
                            if(posX >0 && posX <= limX)
                            {
                                --posX;
                                (*f4)(posX);
                            }
                            break;
                        case VK_RETURN:
                            return (posX*10)+posY;
                        case VK_ESCAPE:
                            return -1;
                    }
                }

            } // end EventsRead loop
        }// Event Happened Loop

        if(now.second()==0)
        {
            (*thread)(); //background process
        }

    } // end program loop
}
*/


int homeMenu(void)
{
    short ch_menu;

        cout << "\n\n\n";
        //displaying menus
        setFgClr("White");
        cout << whiteSp(34) << "Sign in \n\n";
        cout << whiteSp(34) << "Sign up \n\n";
        cout << whiteSp(34) << "Help\n\n";
        cout << whiteSp(34) << "Exit\n\n\n\n";

         //showing first arrow indicator
        Locate(31,5);
        cout << (char)175;
        colorArea("Bright White",31,5,40);

        //waiting for the menu input
        ch_menu = ArrKeyEvents(3,YArrowFunc,YArrowFunc)%10;

        return ch_menu;
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


void WelcomeScreen(void)
{
    cursorVisAndSize(false);

    system("CLS");
    system("Color 84");
    string logoClr = "Red";
    short delay = 200;
    Sleep(1000);

    // M
    Sleep(delay);
    clrdLine(logoClr,24,3,26,16);
    Sleep(delay);
    clrdLine(logoClr,27,3,30,4);
    Sleep(delay);
    clrdLine(logoClr,31,3,32,16);
    Sleep(delay);
    clrdLine(logoClr,33,3,34,16);
    Sleep(delay);
    clrdLine(logoClr,35,3,38,4);
    Sleep(delay);
    clrdLine(logoClr,39,3,43,16);
    Sleep(delay);

    // P
    clrdLine(logoClr,44,3,53,5);
    Sleep(delay);
    clrdLine(logoClr,54,3,55,10);
    Sleep(delay);
    clrdLine(logoClr,44,11,55,12);
    Sleep(delay);

    Locate(24,17);
    cout << "M A A Z    P R O D U C T I O N S";

    Sleep(3500);
}
#endif
