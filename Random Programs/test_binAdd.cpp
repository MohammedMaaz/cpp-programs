#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> binAdd(vector<int> n1, vector<int> n2)
{
    vector<int> temp, res;
    int iniLen, len;

    if( n1.size() >= n2.size() )
        {
            iniLen = n2.size();
            len = n1.size();
            temp.resize(len);
            for(int i=0; i<len; ++i)
            {
                if(i < iniLen)
                    temp[i+(len-iniLen)] = n2[i];
            }
            n2.resize(len);
            for(int i=0; i<len; ++i)
            {
                n2[i] = temp[i];
            }
        }
    else
        {
            iniLen = n1.size();
            len = n2.size();
            temp.resize(len);
            for(int i=0; i<len; ++i)
            {
                if(i < iniLen)
                    temp[i+(len-iniLen)] = n1[i];
            }
            n1.resize(len);
            for(int i=0; i<len; ++i)
            {
                n1[i] = temp[i];
            }
        }

        res.resize(len+2);

    for(int i=(len-1); i >=0; --i)
    {
        if( (n1[i] + n2[i]) == 0)
            {
                if(i==0)
                {
                    res[i+2] = 0;
                    res[i+1] = 0;
                }
                res[i+2] = 0;
            }
        else if( (n1[i] + n2[i]) ==1 )
            {
                if(i==0)
                {
                    res[i+2] = 1;
                    res[i+1] = 0;
                }
                res[i+2] = 1;
            }
        else if( (n1[i] + n2[i]) ==2 )
        {
            if(i==0)
                {
                    res[i+2] = 0;
                    res[i+1] = 1;
                }
            res[i+2] = 0;
            n1[i-1] = n1[i-1] + 1;
        }
        else
        {
            if(i==0)
                {
                    res[i+2] = 1;
                    res[i+1] = 1;
                }
            res[i+2] = 1;
            n1[i-1] = n1[i-1] + 1;
        }
    }

    return res;
}


int main()
{
    vector<int> num = {0,0,0,0,0,0}, inc = {1}, result;

    for(int i=1; i<=64; ++i)
    {
        for(int i=0; i<num.size(); ++i )
            cout << num[i];

        cout << endl;

        num = binAdd(num,inc);
        num.erase(num.begin(),num.begin()+2);
    }

}
