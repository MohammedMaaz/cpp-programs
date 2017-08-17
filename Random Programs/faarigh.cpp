#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <conio.h>
using namespace std;

void Read( vector <int> & roll, vector <string> & name, vector <double> & cgp, ifstream & inFile );
void Rep( vector <int> & roll, vector <string> & name, vector <double> & cgp, ofstream & outFile );

int main()
{
    vector <int> roll;
    vector <string> name;
    vector <double> cgp;

    ofstream outF("C:\\Users\\HP\\Desktop\\C++ Programs\\Random Programs\\Text Files\\students_db.txt",ios::app|ios::out);
    ifstream inF("C:\\Users\\HP\\Desktop\\C++ Programs\\Random Programs\\Text Files\\students_db.txt");

    Read(roll,name,cgp,inF);

    int menu=0, choice, rNo;
    string nam;
    double cGp;
    bool flag = 0;

    cout << "\t\t\t ***** Student's Database Program ***** ";
    cout << endl << endl << endl << endl;
    cout << "\t\t\t      Created By:   Mohammed Maaz" << endl;
    cout << "\t\t\t      Roll Number:  EE-227" << endl;
    cout << "\t\t\t      Date Created: 30/10/2016" << endl << endl << endl;

    cout << "\n\n \t\t\t Press any key to continue.... ";
    getch();

    while(menu!=27)
    {

    system("CLS");
    cout << "\t\t\t\t Menu" << endl;
    cout << endl << "\t\t\t 1. Enter a record";
    cout << endl << "\t\t\t 2. Display a record";
    cout << endl << "\t\t\t 3. Replace a record";
    cout << endl << endl << "\t\t Choose a menu option (1-3) or press ESC to exit: ";
    menu = getch();

    while( (menu!=49)&&(menu!=50)&&(menu!=51)&&(menu!=27) )
        menu = getch();

    switch(menu)
    {
    case 49 :
        {
            system("CLS");
            cout << "///// Record Entry /////" << endl << endl;

                if(flag==1)
                    cin.ignore();
                cout << "Enter Student's Name: ";
                getline(cin,nam);
                outF << nam << endl;
                name.push_back(nam);

                cout << "Enter Student's Roll number: ";
                cin >> rNo;
                while( (rNo<1)||(rNo>1000) )
                {
                    cout << endl << "Must be a number between 1 to 1000: ";
                    cin >> rNo;
                }
                outF << rNo << endl;
                roll.push_back(rNo);

                cout << "Enter Student's CGPA: ";
                cin >> cGp;
                while( (cGp<0)||(cGp>4.0) )
                {
                    cout << endl << "Must be a number between 0 to 4: ";
                    cin >> cGp;
                }
                outF << cGp << endl;
                cgp.push_back(cGp);

                cout << "\nRecord entered successfully!";

            cout << "\n\n\nPress any key for main menu...";
            getch();
            break;
        }
    case 50 :
        {
            system("CLS");
            cout << "///// Record Display /////" << endl << endl;
            cout << "Enter record number: ";
            cin >> choice;
            while( (choice<0) )
            {
                cout << "\nMust be a positive integer: ";
                cin >> choice;
            }
            if(choice>=roll.size())
                cout << "\n\nRecord not entered yet.";
            else
            {
                cout << endl << endl << "Record NO. " << choice << endl;
                cout << endl << "Student's Name:     " << name[choice];
                cout << endl << "Student's Roll No:  " << roll[choice];
                cout << endl << "Student's CGPA:     " << cgp[choice];
            }
            cout << "\n\n\nPress any key for main menu...";
            getch();
            break;
        }
    case 51 :
        {
            system("CLS");
            cout << "///// Record Replace /////" << endl << endl;
            cout << "Enter record number: ";
            cin >> choice;
            while( (choice<0) )
            {
                cout << "\nMust be a positive integer: ";
                cin >> choice;
            }
            if(choice>=roll.size())
                cout << "\n\nRecord not entered yet.";
            else
            {
                cin.ignore();
                cout << "\n\nEnter Student's Name: ";
                getline(cin,name[choice]);
                cout << "Enter Student's Roll number: ";
                cin >> rNo;
                while( (rNo<1)||(rNo>1000) )
                {
                    cout << endl << "\nMust be a number between 1 to 1000: ";
                    cin >> rNo;
                }
                roll[choice] = rNo;
                cout << "Enter Student's CGPA: ";
                cin >> cGp;
                while( (cGp<0)||(cGp>4.0) )
                {
                    cout << endl << "\nMust be a number between 0 to 4: ";
                    cin >> cGp;
                }
                cgp[choice] = cGp;
                Rep(roll,name,cgp,outF);
                cout << "\nRecord replaced successfully!";
            }
            cout << "\n\n\nPress any key for main menu...";
            getch();
            break;
        }
    default :
        {
            system("CLS");
            cout << endl << endl << endl << "\t\t\t ************************";
            cout << endl << "\t\t\t      End of Program";
            cout << endl << "\t\t\t ************************" << endl << endl;
        }
    }

    flag = 1;

        //Updating the Display File
        ofstream dispF("C:\\Users\\HP\\Desktop\\C++ Programs\\Random Programs\\Text Files\\display.txt");
        dispF << "***************** Student's Database File *****************" << endl << endl << endl;
        dispF << left << setw(11) << "Rec No." << setw(12) << "Roll No." << setw(35) << "Name" << right << setw(4) << "CGPA" << endl << endl;
        for(int di=0; di<roll.size(); ++di)
        {
            dispF << left << setw(11) << di << setw(12) << roll[di] << setw(35) << name[di] << setw(4) << right << fixed << setprecision(2) << cgp[di] << endl;
        }


    } //while end

    return 0;
}

void Read( vector <int> & roll, vector <string> & name, vector <double> & cgp, ifstream & inFile )
{
    int j=3;
    string line;

    while( getline(inFile,line) )
    {
        switch(j%3)
        {
            case 0 :
            {
                name.push_back(line);
                break;
            }
            case 1 :
            {
                roll.push_back( stoi(line) );
                break;
            }
            default :
            {
                cgp.push_back( stod(line) );
            }
        }
        ++j;
    }
}

void Rep( vector <int> & roll, vector <string> & name, vector <double> & cgp, ofstream & outFile)
{
    outFile.close();
    outFile.open("C:\\Users\\HP\\Desktop\\C++ Programs\\Random Programs\\Text Files\\students_db.txt");
    for(int i=0; i<roll.size(); ++i)
    {
        outFile << name[i] << endl << roll[i] << endl << cgp[i] << endl;
    }
    outFile.close();
    outFile.open("C:\\Users\\HP\\Desktop\\C++ Programs\\Random Programs\\Text Files\\students_db.txt",ios_base::app);
}

