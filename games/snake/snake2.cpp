#include <iostream>
#include "snake2.h"
#include <stdlib.h>
#include <thread>

using namespace std;

int main()
{
    srand(time(NULL));
    init(32,15,'L',3);
    cout << " score: " << score << endl << endl;
    cout <<"\n\n\n\n\n\n\n\n\n\n Use arrow keys to" <<endl<< " move the snake." <<endl<<endl<<" Press 'space bar'" <<endl<< " to pause/resume.";

    getch();
    thread t1(collectKeyEvents); //inputs tracking key events simultaneously
    int speed = (31-level)*10;
    while(!gameOverCondition)
    {
        Locate(8,0);
        cout << score;
        Sleep(speed);

        if(!keys.empty())
        {
            direction = keys.front();
            keys.pop();
        }
        program();
        while(pause);
    }

    t1.detach();
    //t1.join();

    Locate(35,10);
    cout << "Game Over!";
    Locate(31,12);
    cout << "Press 'ESC' to exit";
    Locate(30,13);
    cout << "'Enter' to Play Again";

    while(1)
    {
        switch(getch())
        {
        case '\r':
            system("cls");
            resetData();
            return main();
        case 27:
            system("cls");
            return 0;
        }
    }
}
