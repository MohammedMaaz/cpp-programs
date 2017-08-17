#include "cash_manager.h"
using namespace std;

int main()
{
    // ***** WELCOME SCREEN ***** //
    WelcomeScreen();
    // WELCOME SCREEN ENDS //



HomeMenu:
    system("Color 0B"); //Setting Color Immediately
    // ******** DISPLAYING HOMEMENU HEADER ********** //
    Header("Cash Manager","L Yellow");
    thread homeMenuThread(DateThread);

    short ch_mainMenu;
    ch_mainMenu = homeMenu();

    homeMenuThread.detach();
     // ******* HOMEMENU END ********* //



    switch(ch_mainMenu)
    {
    case 0:
        {
            Locate(38,17);
            cout << "Sign in.\n";
            break;
        }
    case 1:
        {
            Locate(38,17);
            cout << "Sign up.\n";
            break;
        }
    case 2:
        {
            Locate(38,17);
            cout << "Help.\n";
            break;
        }
    }

	return 0;
}
