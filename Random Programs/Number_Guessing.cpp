#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int n, attempt, tryagain;
    char ch;

    do {
        system("CLS");
        attempt = 0;
        tryagain = 0;
        cout << "                                Number Guessing \n" << endl;
        cout << "The computer has a no. in between 0-500 , You have to guess it!" << endl;
        do {
            cout << "Make Your Guess? (attempts remaining: " << 5 - attempt << ") ";
            cin >> n;
            if (n<0 || n>500){
                cout << "Please enter a no. in the range of '0-500' :" << endl;
                cin >> n;
            }
            if (n<227){
                cout << "Sorry! your guessed no. is smaller than the original one. \n" << endl;
            }
            if (n>227){
                cout << "Sorry! your guessed no. is greater than the original one. \n" << endl;
            }
            if (n==227){
                cout << " \n**********************************************************" << endl;
                cout << "Congratulations! You have Successfully guessed the number!" << endl;
                cout << "**********************************************************" << endl;
            }
            attempt = attempt + 1;
            }
        while(n!=227 && attempt < 5);

        if (n!= 227 && attempt >= 5){
            cout << "Oops! you have exceeded the attempts limit." << endl;
            cout << "Try Again ? (y/n)";
            cin >> ch;
            if (ch==89 || ch==121){
                tryagain = 1;
                cout << endl << endl;
            }
        }
    }
    while(tryagain == 1);

    system("pause");

    return 0;
}
