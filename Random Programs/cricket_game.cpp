#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <ctime>
using namespace std;

int main()
{
    srand( time(NULL) );

    system("CLS");
    cout << "********************** Book Cricket **********************" << endl << endl;

    int overs, score = 0, scoreA=0, scoreB=0, target, balls, wkts, wktsA, wktsB;
    double temp_overs, oversA, oversB;
    bool tossDec;
    char team, flag_t, pl_again;

    cout << "Set the length of the match in overs: ";
    cin >> overs;
    cout << "\nPlayer1 is 'Team A' and Player2 is 'Team B'" << endl;
    cout << "\nPress any key to toss the coin...";
    getch();

    if( (rand()%2)==0 )
    {
        cout << "\n\nTeam A wins the toss!";
        cout << "\nBat or Bowl? (0/1)";
        cin >> tossDec;
        if(tossDec == 0)
           {
               team = 'A';
               flag_t = 'A';
               cout << "\nTeam " << team << " will bat first.";
           }
        else
           {
               team = 'B';
               flag_t = 'B';
               cout << "\nTeam " << team << " will bat first.";
           }
    }
    else
    {
        cout << "\n\nTeam B wins the toss!";
        cout << "\nBat or Bowl? (0/1)";
        cin >> tossDec;
        if(tossDec == 1)
            {
                team = 'A';
                flag_t = 'A';
                cout << "\nTeam " << team << " will bat first.";
            }
        else
            {
                team = 'B';
                flag_t = 'B';
                cout << "\nTeam " << team << " will bat first.";
            }
    }

    cout << "\n\n\n\t\t    Press any key to start the match....";
    getch();

    system("CLS");
    cout << "\nMatch started!";

    for(int j=0; j<2; ++j)
    {
        wkts = 0;
    for(int i=1; i<=(overs*6); ++i)
    {
        cout << "\n\nPress any key to play a ball!";
        getch();
        system("CLS");

        switch( (rand()%5) )
        {
        case 0 :
            {
                cout << "\nOUT! \t\t\t Score: " << score;
                ++wkts;
                if(wkts == 5)
                {
                    temp_overs = ( (i/6) + (0.1*(i%6)) );
                    i = (overs*6)+2;
                }
                break;
            }
        case 1 :
            {
                cout << "\n2 Runs! \t\t\t Score: " << (score = score+2);
                break;
            }
        case 2 :
            {
                cout << "\n4 Runs! \t\t\t Score: " << (score = score+4);
                break;
            }
        case 3 :
            {
                cout << "\n6 Runs! \t\t\t Score: " << (score = score+6);
                break;
            }
        case 4 :
            {
                --i;
                cout << "\nNo Ball! \t\t\t Score: " << (score = score+1);
                break;
            }
        }
        if( i<= (overs*6) )
        {
            temp_overs = ( (i/6) + (0.1*(i%6)) );
            cout << "-" << wkts << "\tOvers: " << temp_overs;
        }
        if(j==1)
            {
                cout << "\tTarget: " << target;
                if(score >= target)
                    i = (overs*6)+2;
            }
    }
    if( team == 'A' )
    {
        scoreA = score;
        oversA = temp_overs;
        wktsA = wkts;
        temp_overs = 0;
        target = (scoreA + 1);
        team = 'B';
        score = 0;
        if(j==0)
            cout << "\n\n Team B will bat now.";
    }
    else
    {
        scoreB = score;
        oversB = temp_overs;
        wktsB = wkts;
        temp_overs = 0;
        target = (scoreB + 1);
        team = 'A';
        score = 0;
        if(j==0)
            cout << "\n\n Team A will bat now.";
    }

    }
        if(scoreB > scoreA)
            {
                cout << "\n\n\n\t\t\t    **** Team B wins! ****";
                team = 'B';
                temp_overs = oversB;
                wkts = wktsB;
            }
        else if(scoreA > scoreB)
            {
                cout << "\n\n\n\t\t\t    **** Team A wins! ****";
                team = 'A';
                temp_overs = oversA;
                wkts = wktsA;
            }
        else
            {
                cout << "\n\n\t\t\t    **** Match Tied! *****";
                team = 'C';
            }

    cout << "\n\n\n\nPress any key for 'Match Summary'";
    getch();
    system("CLS");

    cout << "\t\t\t**** Match Summary ****";
    cout << endl << endl << endl << "\t\t\tTeam\tScore\tOvers(" << overs << ")";
        if(flag_t == 'A')
        {
            score = scoreA - scoreB;
            cout << endl << endl << "\t\t\t A\t " << scoreA << "-" << wktsA << "\t  " << oversA;
            cout << endl << endl << "\t\t\t B\t " << scoreB << "-" << wktsB << "\t  " << oversB;
        }
        else
        {
            score = scoreB - scoreA;
            cout << endl << endl << "\t\t\t B\t " << scoreB << "-" << wktsB << "\t  " << oversB;
            cout << endl << endl << "\t\t\t A\t " << scoreA << "-" << wktsA << "\t  " << oversA;
        }

        balls = ((int)temp_overs*6) + (temp_overs-(int)temp_overs)*10;

    if(flag_t == team)
        cout << "\n\n\t\t\tTeam " << team << " wins by " << (score) << " Run(s)." << endl;
    else if(team == 'C')
        cout << "\n\n\t\t\tMAtch tied" << endl;
    else
        cout << "\n\n\t\t\tTeam " << team << " wins with " << (overs*6-balls) << " ball(s) and " << (5-wkts) << " wicket(s) remaining." << endl;

        cout << "\n\n\n\n\n\n\t\t\tEnter 'y' to play again: ";
        cin >> pl_again;

        if( (pl_again=='y') || (pl_again=='Y') )
            return main();

        cout << endl;

    return 0;
}
