#include <iostream>
using namespace std;

int main()


{
    cout<<"\t MENU"<<endl;
    cout<< "1. Welcome Message"<<endl;
    cout<< "2. Hello World Message"<<endl;
    cout<< "3. Good Bye Message"<<endl;
    cout<< "4. Exit Message"<<endl;

    int x;

    cout<<"Enter a number from1 to 4:";

    cin>>x;

    switch(x)

{
    case 1:
    {
        cout<<"\n\nWelcome!\n\n";
    return main();


    }


    case 2:
    {
        cout<<"\n\nHello World!\n\n";
    return main();


    }



    case 3:
    {
        cout<<"\n\nGood Bye!\n\n";
    return main();


    }


    default:
    {
        cout<<"\n\nExit!\n\n";
    return 0;

    }

}
}
