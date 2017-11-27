#include <console_formatting.h>
#include <queue>

using namespace std;

void colorPixel(short x, short y, string bgClrName)
{
    short /*fgCode, bgCode,*/ clrCode;

    clrCode = (clrStrToCode(bgClrName)*16);

    HANDLE stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coords = {x,y};
    DWORD written = 0;
    WORD Attr = clrCode;

    WriteConsoleOutputAttribute(stdout_handle, &Attr, 1, coords, &written);
}

string clrCodeToStr(int clrCode)
{
    string clrArr[] = {"Black","Blue","Green","Cyan","Red","Purple","Yellow","White","Gray","L Blue","L Green",
                        "L Cyan", "L Red", "L Purple", "L Yellow", "Bright White"};

    return clrArr[clrCode];
}

int getConsoleWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO cns;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cns);
    return (cns.srWindow.Right - cns.srWindow.Left);
}

int getConsoleHeight()
{
    CONSOLE_SCREEN_BUFFER_INFO cns;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cns);
    return (cns.srWindow.Bottom - cns.srWindow.Top);
}

int getPixelColor(short x, short y)
{
    HANDLE stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD rCords = {x,y};
    DWORD written = 0;
    WORD rAttr;

    ReadConsoleOutputAttribute(stdout_handle, &rAttr, 1, rCords, &written);
    return rAttr/16;
}

struct bodyUnit
{
    int x;
    int y;
};

vector<struct bodyUnit> snake;
queue<char> keys, dummy;
struct bodyUnit last, food;
char direction;
int ScrWidth, height, width=40;
int widthAdjust;
bool gameOverCondition=false, walls=false, pause = false;
string snakeColor = "L Red", wallsColor = "L Green", foodColor = "L Yellow";
int snakeColorCode = clrStrToCode(snakeColor), wallsColorCode = clrStrToCode(wallsColor);
int newHeadColor, score=0,level = 27;

void createFood()
{
    bool repeat = true;
    int initFColor;

    while(repeat) //decide where to place food, it should not be on the body of snake
    {
        food.x = rand()%(width-1)+widthAdjust+1;
        food.y = rand()%(height-1)+1;

        initFColor = getPixelColor(food.x, food.y);
        if( initFColor==snakeColorCode || initFColor==wallsColorCode )
            repeat = true;
        else
            repeat = false;
    }
    colorPixel(food.x, food.y, foodColor);
}

void init(int startX,int startY,char initialDirection,int initLength=2)
{
    ScrWidth = getConsoleWidth(), height = getConsoleHeight();
    widthAdjust = (ScrWidth+1-width)/2;
    cursorVisAndSize(0); //hide cursor
    direction = initialDirection;
    keys.push(direction);
    switch(initialDirection)
    {
    case 'L':
        for(int i=startX; i<startX+initLength; ++i)
            snake.push_back({i, startY});
        break;
    case 'R':
        for(int i=startX; i>startX-initLength; --i)
            snake.push_back({i, startY});
        break;
    case 'U':
        for(int i=startY; i<startY+initLength; ++i)
            snake.push_back({startX, i});
        break;
    case 'D':
        for(int i=startY; i>startY-initLength; --i)
            snake.push_back({startX, i});
        break;
    }

    //creating walls
        for(int i=widthAdjust; i<=width+widthAdjust; ++i)
        {
            colorPixel(i,0, wallsColor);
            colorPixel(i,height, wallsColor);
        }
        for(int i=0; i<=height; ++i)
        {
            colorPixel(widthAdjust,i, wallsColor);
            colorPixel(width+widthAdjust,i, wallsColor);
        }

    //create snake initially
    for(int i=0; i<snake.size(); ++i)
    {
        colorPixel(snake[i].x, snake[i].y, snakeColor);
    }
    //create food initially
    createFood();
}

void collectKeyEvents()
{
while(1)
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 75:
            if(keys.back()!='R' && !pause)
                keys.push('L');
            break;

        case 77:
            if(keys.back()!='L' && !pause)
                keys.push('R');
            break;

        case 72:
            if(keys.back()!='D' && !pause)
                keys.push('U');
            break;

        case 80:
            if(keys.back()!='U' && !pause)
                keys.push('D');
            break;

        case 32:
            pause = !pause;
            break;
        }//end switch
    }
}//end while
}

void program()
{
    last = snake[snake.size()-1]; //preserve last body unit to be erased later

    //every bodyUnit except the head follows its next one
    for(int i=snake.size()-1; i>0; --i)
    {
        snake[i] = snake[i-1];
    }

    if(snake[0].x==food.x && snake[0].y==food.y) //if snake eats food
    {
        score = score+level;
        snake.push_back(last); //then push one unit in the end and don't erase the tail
        createFood(); //create new food;
    }
    else
    {
        colorPixel(last.x, last.y, "Black"); //erase last tail
    }

    //head follows the given direction
    switch(direction)
    {
    case 'L':
        if(snake[0].x == widthAdjust+(1-walls))
        {
            snake[0].x = width+widthAdjust-1;
        }
        else
            snake[0].x = snake[0].x-1;
        break;
    case 'R':
        if(snake[0].x == width+widthAdjust-(1-walls))
        {
            snake[0].x = widthAdjust+1;
        }
        else
            snake[0].x = snake[0].x+1;
        break;
    case 'U':
        if(snake[0].y == (1-walls))
        {
            snake[0].y = height-1;
        }
        else
            snake[0].y = snake[0].y-1;
        break;
    case 'D':
        if(snake[0].y == height-(1-walls))
        {
            snake[0].y = 1;
        }
        else
            snake[0].y = snake[0].y+1;
        break;
    }
    //game over condition
    newHeadColor = getPixelColor(snake[0].x, snake[0].y);
    if( newHeadColor==snakeColorCode || (newHeadColor==wallsColorCode && walls) )
        gameOverCondition = true;
    else
        colorPixel(snake[0].x, snake[0].y, snakeColor); //move the head to the new position
}

void resetData()
{
    snake.resize(0);
    keys = dummy;
    last.x=-1, last.y=-1; food.x=-1, food.y=-1;
    direction='L';
    gameOverCondition = false; pause = false;
    score=0;
}

