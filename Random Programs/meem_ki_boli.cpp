#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int i=0, j=0;
    string us_inp, ch, prev, neu, ch_p, ch_n;
    bool fl1 = 1;

    cout << "Enter the text you want to transform in meem ki boli:\n";
    getline(cin,us_inp);

    us_inp = us_inp + " ";
    ch = us_inp[i];
    ch_p = us_inp[0];

    while( j<(us_inp.size()) )
    {
        while( ch!= " " )
        {
            ch_n = us_inp[i];

            if( ch_p==ch_n )
                fl1 = 0;
            else
                fl1 = 1;

            if( (ch!="a")&&(ch!="e")&&(ch!="i")&&(ch!="o")&&(ch!="u")&&(ch!=" ")&&(ch!="?")&&(ch!=",") )
            {
                us_inp.replace(i,1,"m");
            }
            ch_p = ch_n;
            prev = us_inp[i-1];
            neu = us_inp[i];

             if( (fl1 == 1) )
            {
                if( (prev=="m") && (neu=="m") )
                    us_inp.erase(i-1,1);
            }

            ++i;
            ch = us_inp[i];
        }
        ++i;
        ch = us_inp[i];
        j = i;
    }

    cout << endl << us_inp << endl << endl << endl;

    return main();
}
