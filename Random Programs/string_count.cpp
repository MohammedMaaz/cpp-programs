#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

void wordsCounter()
{
    string word = "", str;
    vector<string> wordsArray;

    cout << "Enter any sentence:\n";
    getline(cin,str);
    str = str + ' ';

    for(int i=0; i<str.size(); ++i)
    {
        if(str[i]!=' ')
            word = word+str[i];
        else
        {
            bool flag = 1;
            for(int i=0; i<wordsArray.size(); ++i)
            {
                if(word==wordsArray[i])
                {
                    flag=0;
                    break;
                }
            }
            if(flag && word!="")
                wordsArray.push_back(word);
            word = "";
        }
    }
    sort(wordsArray.begin(),wordsArray.end());


    cout << "\n\nNumber of distinct words = " << wordsArray.size();
    cout << "\n\nSorted list of words:\n";
    cout << '[';
    for(int i=0; i<wordsArray.size()-1; ++i)
        cout << wordsArray[i] << ", ";
    cout << wordsArray[wordsArray.size()-1] << ']' << endl;
}

void GCD()
{
    int a,b, i=2, res=1;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    while(i<=abs(a) && i<=abs(b))
    {
        if(a%i==0 && b%i==0)
        {
            a = a/i;
            b = b/i;
            res = res*i;
        }
        else
            ++i;
    }

    cout << "\n\nGCD: " << res << endl;
}

int main()
{
    GCD();

    return 0;
}
