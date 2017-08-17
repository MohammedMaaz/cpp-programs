#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <vector>
using namespace std;

string signedUser, customSigninMessage, logoutMenu;
int  lmlim=2, signinMenuLen = 43;

void Read( vector <string> & user_fullName, vector <string> & user_dob, vector <string> & usr_id, vector <string> & usr_pas, vector <string> & user_secQues, ifstream & readFile );
int signInSearch( vector<string> & usr_id, string usr_name, vector<string> & usr_password, string usr_pas );
bool signUpSearch( vector<string> & usr_id, string usr_name, vector<string> & usr_password, string usr_pas );
bool dobFormat( string dob );
void Delay(double Sec);
void replacePass( int index_of_name, string rep_pass, ifstream & readFile, ofstream & outFile );
char sym = 7;
string lowerCase(string mixed_str);

int main()
{
    ofstream outDB("database.mpd",ios::app|ios::out);
    ifstream inDB("database.mpd");

    vector <string> user_id, user_pas, user_fullName, user_dob, user_secQues; //permanent storage
    time_t now = time(0);
    int currYear = now/(3600*24*365) + 1970.0;
    string usr_name, password, p_dob, p_fullName, p_secQues; //for internal program only
    string r_userName, r_dob, r_secQues; //for resetting password
    char main_menu_ch;

    Read(user_fullName,user_dob,user_id,user_pas,user_secQues,inDB);

    // Welcome Screen Formatting //
    system("CLS");
    cout << setw(43 - signedUser.size()/2 ) << "Welcome " << signedUser << " \n" ;
    cout << setw(41) << "to\n";
    cout << setw(50) << "Maaz Productions\n\n\n";

    cout << "\n" << setw(signinMenuLen) << right << "1. Sign in" + customSigninMessage;
    cout << "\n\n" << setw(43) << right << "2. Sign up";
    cout << "\n\n" << setw(42) << right << logoutMenu;
    cout << "\n\n\n";

    cout << setw(51) << right << "Choose a menu option: ";
    cin >> main_menu_ch;
    main_menu_ch = (int)main_menu_ch - 48;
    while( main_menu_ch<1||main_menu_ch>lmlim )
    {
        cout << setw(57) << "Incorrect Choice, Choose again: ";
        cin >> main_menu_ch;
        main_menu_ch = (int)main_menu_ch - 48;
    }
    cin.ignore();


    switch(main_menu_ch)
    {
        // ********************** CASE1 ****************************
        // ****************** sign in option ***********************
    case 1 :
        {
            char p, tryAgain;

            if(user_id.size()==0)
            {
                cout << "\n\n\n\n\n\n\t\tNo account have been added yet, Sign Up to add one!";
                Delay(3.2);
                return main();
            }

        do
        {
            system("CLS");
            cout << "Sign in\n\n\n";

            //user name starts
            cout << "\nEnter Username: ";
            getline(cin,usr_name);
            //user name ends


            cout << "\nEnter Password: ";
            password = "";
            while( (p=getch()) !=13)  //password structure
            {
                if( (p==8)&&(!password.empty()) )
                {
                    password.pop_back();
                    cout << "\b \b";
                }
                else
                {
                    password.push_back(p);
                    cout << '*';
                }
            }  //password structure

            if(signInSearch(user_id,usr_name,user_pas,password)!=-1)
            {
                signedUser = user_fullName[ signInSearch(user_id,usr_name,user_pas,password) ];
                customSigninMessage = " with a different account.";
                logoutMenu = "3. Logout";
                lmlim = 3;
                signinMenuLen = 43 + customSigninMessage.size();
                tryAgain = 'n';
            }
            else
            {
                cout << "\n\nInvalid Username or Password!\n\n";
                cout << "1. Try again?\n";
                cout << "2. Forgot password?\n";
                cout << "3. Main Menu";
                cout << "\nChoose a number between 1 to 3: ";
                cin >> tryAgain;
                while( ((int)tryAgain-48)<1||((int)tryAgain-48)>3 )
                {
                    cout << "\nChoose a number between 1 to 3: ";
                    cin >> tryAgain;
                }
                cin.ignore();
                switch(tryAgain)
                {
                case '2':
                    {
                        system("CLS");
                        int rs_index=-1;
                        bool dob_flag=0, secq_flag=0, usn_flag=0;
                        cout << setw(50) << "Password Recovery" << "\n\n\n\n";

                        cout << "Enter your Username: "; //Asking user name;
                        while(usn_flag==0)
                        {
                            usn_flag = 1;
                            getline(cin,r_userName);
                            for(int i=0; i<r_userName.size(); ++i)
                            {
                                if(r_userName==user_id[i])
                                {
                                    rs_index = i;
                                    break;
                                }
                            }
                            if(r_userName.empty())
                            {
                                cout << "\nThis field is Required! Enter again: ";
                                usn_flag = 0;
                            }
                            else if(rs_index == -1)
                            {
                                cout << "\nRecord Not Found!, Try again: ";
                                usn_flag = 0;
                            }
                            else
                            {
                                cout << "\nProceed with the Date of Birth...\n\n";
                            }
                        }


                        cout << "Enter your Date of Birth, (format: \"dd-mm-yyyy\"): "; //Asking date of birth;
                        while(dob_flag==0)
                        {
                            getline(cin,r_dob);
                            dob_flag=1;
                            if( dobFormat(r_dob)==0 )
                            {
                                cout << "\nIncorrect format, Enter Again: ";
                                dob_flag=0;
                            }
                             else if( stoi(r_dob.substr(0,2))>31||stoi(r_dob.substr(0,2))<1 )
                            {
                                cout << "\nDate must be in the range of 1 to 31, Enter again: ";
                                dob_flag=0;
                            }
                             else if( stoi(r_dob.substr(3,2))>12||stoi(r_dob.substr(3,2))<1 )
                            {
                                cout << "\nMonth must be in the range of 1 to 12, Enter again: ";
                                dob_flag=0;
                            }
                            else if( r_dob!=user_dob[rs_index] )
                            {
                                cout << "\nThis date of birth does not match with your username, Enter again: ";
                                dob_flag=0;
                            }
                        }

                        cout << "\nAnswer this security question:-\n"; //Asking Security Question
                        cout << "What is your favorite Book's name? ";
                        while(secq_flag==0)
                        {
                            secq_flag = 1;
                            getline(cin,r_secQues);
                            r_secQues = lowerCase(r_secQues); //changing to lowercase
                            for(int case_iter=0; case_iter<r_secQues.size(); case_iter++)
                            {
                                if( isupper(r_secQues[case_iter])==1 )
                                    r_secQues[case_iter] = tolower(r_secQues[case_iter]);
                            }
                            if(r_secQues.empty())
                            {
                                cout << "\nThis field is Required, Enter again: ";
                                secq_flag = 0;
                            }
                            else if( r_secQues!=user_secQues[rs_index] )
                            {
                                cout << "\nYour answer didn't match, Try again: ";
                                secq_flag = 0;
                            }
                        }
                        cout << "\nEnter new Password: ";
            passRepStruct:
            {
                password="";
                while( (p=getch()) !=13)
                {
                if( (p==8)&&(!password.empty()) )
                {
                    password.pop_back();
                    cout << "\b \b";
                }
                else
                {
                    password.push_back(p);
                    cout << '*';
                }
                }
            }
            if( password.size()<6||password.size()>18 )
            {
                cout << "\nPassword must be 6 to 18 characters long, Enter again: ";
                goto passRepStruct;
            }
            if( password.find(sym)< password.size() )
            {
                cout << "\nPassword can't contain a " << sym << " character, Enter again: ";
                goto passRepStruct;
            }
            user_pas[rs_index] = password;
            replacePass(rs_index,password,inDB,outDB); //replacing password

                        break;
                    } // case 2

                case '3':
                    {
                        return main();
                    }
                } // switch
            } // else
        } //do
        while( (tryAgain=='1') );
        break;
        }





        // ********************** CASE 2 ***************************
        // ****************** sign up option ***********************
        case 2 :
        {
            system("CLS");
            cout << "Sign up\n\n\n";
            char p;

            // full name starts
            cout << "\nEnter your Full Name: ";
        fullNameStruct:
            getline(cin,p_fullName);
            if(p_fullName.size()==0)
            {
                cout << "\nThis Field is Required. Enter again: ";
                goto fullNameStruct;
            }
            // full name ends;


            // DOB starts
            cout << "\nEnter your Date of Birth, (format: \"dd-mm-yyyy\"): ";
        dobStruct:
            getline(cin,p_dob);
            if( dobFormat(p_dob)==0 )
            {
                cout << "\nIncorrect format, Enter Again: ";
                goto dobStruct;
            }
            else if( stoi(p_dob.substr(0,2))>31||stoi(p_dob.substr(0,2))<1 )
            {
                cout << "\nDate must be in the range of 1 to 31, Enter again: ";
                goto dobStruct;
            }
            else if( stoi(p_dob.substr(3,2))>12||stoi(p_dob.substr(3,2))<1 )
            {
                cout << "\nMonth must be in the range of 1 to 12, Enter again: ";
                goto dobStruct;
            }
            else if( stoi(p_dob.substr(6))>(currYear-5)||stoi(p_dob.substr(6))<(currYear-100) )
            {
                cout << "\nThis program is intended for the users between ages 6 to 100.";
                Delay(6);
                return main();
            }
            //DOB ends


            // user name starts
            cout << "\nEnter Username: ";
        usrnameStruct:
            getline(cin,usr_name);
            if( (int)usr_name[0]>47&&(int)usr_name[0]<58 )
            {
                cout << "\nUsername cannot start with a number. Enter again: ";
                goto usrnameStruct;
            }
            else if( (usr_name.find(" ")!=-1) )
            {
                cout << "\nUsername cannot contain space(s). Enter again: ";
                goto usrnameStruct;
            }
            else if( (usr_name.size()<4) )
            {
                cout << "\nUsername must be at least 4 characters long. Enter again: ";
                goto usrnameStruct;
            }
            else if( signUpSearch(user_id,usr_name,user_pas,password)==1 )
            {
                cout << "\nUsername already exists. Try a new one: ";
                goto usrnameStruct;
            }
            //user name ends

            //password structure
            cout << "\nEnter Password: ";
        passStruct:
            {
                password="";
                while( (p=getch()) !=13)
                {
                if( (p==8)&&(!password.empty()) )
                {
                    password.pop_back();
                    cout << "\b \b";
                }
                else
                {
                    password.push_back(p);
                    cout << '*';
                }
                }
            }
            if( password.size()<6||password.size()>18 )
            {
                cout << "\nPassword must be 6 to 18 characters long, Enter again: ";
                goto passStruct;
            }
            if( password.find(sym)< password.size() )
            {
                cout << "\nPassword can't contain a " << sym << " character, Enter again: ";
                goto passStruct;
            }
            //password structure


            // Secret question starts
            cout << "\n\nAnswer this secret question for security purpose. This will help you recover your account in case you lose it.";
            cout << "\nWhat is your favorite Book's name? ";
       secQuesStruct:
           getline(cin,p_secQues);
            if(p_secQues.size()==0)
            {
                cout << "\nThis Field is Required. Enter again: ";
                goto secQuesStruct;
            }
            p_secQues = lowerCase(p_secQues); //changing to lower case
            // Secret Question ends

            //writing sign up details to the file
            user_fullName.push_back(p_fullName);
            user_dob.push_back(p_dob);
            user_id.push_back(usr_name);
            user_pas.push_back(password);
            user_secQues.push_back(p_secQues);
            password.resize(19,sym);
            outDB << p_fullName << endl << p_dob << endl << usr_name << endl << password << endl << p_secQues << endl;

            system("CLS");
            cout << "\n\n\n\n\n\n\t\t\t Record Entered Successfully!";
            Delay(3.5);

            break;
        }

        case 3:
            {
                signedUser = "";
                customSigninMessage = "";
                logoutMenu = "";
                lmlim = 2;
                signinMenuLen = 43;
                break;
            }
    }

    return main();
}


// Reading the database file and storing user name and password in arrays //
void Read( vector <string> & user_fullName, vector <string> & user_dob, vector <string> & usr_id, vector <string> & usr_pas, vector <string> & user_secQues, ifstream & readFile )
{
    int j=5;
    string line;

    while( getline(readFile,line) )
    {
        switch(j%5)
        {
            case 0 :
            {
                user_fullName.push_back(line);
                break;
            }
            case 1 :
            {
                user_dob.push_back(line);
                break;
            }
            case 2 :
            {
                usr_id.push_back(line);
                break;
            }
            case 3 :
            {
                int pos_of_end = line.find(sym);
                usr_pas.push_back(line.substr(0,pos_of_end));
                break;
            }
            default :
            {
                user_secQues.push_back(line);
            }
        }
        ++j;
    }
}

// searching for matched ID and PASSWORD //
int signInSearch( vector<string> & usr_id, string usr_name, vector<string> & usr_password, string usr_pas )
{
    for(int i=0; i<usr_id.size(); ++i)
    {
        if(usr_name==usr_id[i])
        {
            if(usr_pas==usr_password[i])
                return i;
        }
    }
    return -1;
}

// searching if user name is repeated
bool signUpSearch( vector<string> & usr_id, string usr_name, vector<string> & usr_password, string usr_pas )
{
    for(int i=0; i<usr_id.size(); ++i)
    {
        if(usr_name==usr_id[i])
                return 1;
    }
    return 0;
}

// Date Format checking
bool dobFormat( string dob )
{
    if(dob.size()!=10)
        return 0;
    for(int i=0; i<10; ++i)
    {
        if( i==2||i==5 )
        {
            if(dob[i]!='-')
                return 0;
        }
        else
        {
            if( (int)dob[i]<48||(int)dob[i]>57 )
                return 0;
        }
    }
    return 1;
}

// Time Delay function
void Delay(double Sec)
{
    double current_time = time(NULL);

    while( time(NULL) < (current_time + Sec) )
    {

    }
}

string lowerCase(string mixed_str)
{
    for(int case_iter=0; case_iter<mixed_str.size(); case_iter++)
    {
        mixed_str[case_iter] = tolower(mixed_str[case_iter]);
    }
    return mixed_str;
}

void replacePass( int index_of_name, string rep_pass, ifstream & readFile, ofstream & outFile )
{
    outFile.close();
    readFile.close();
    readFile.open("database.mpd");

    string line;
    int j=0, len = 0;
    while( getline(readFile,line) )
    {
        ++j;
        len = len + line.size();
            if( j == (index_of_name*5)+3 )
            {
                outFile.open("database.mpd",ios::in | ios::out);
                outFile.seekp( len+(j*2) );
                for(int i=0; i<19; ++i)
                    outFile << sym;
                outFile.seekp( len+(j*2) );
                outFile << rep_pass;
            }
    }

    outFile.close();
    outFile.open("database.mpd",ios_base::app);
    cout << "\n\nPassword Replaced successfully!\n";
    Delay(2);
}
