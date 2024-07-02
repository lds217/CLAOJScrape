#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str,temp="";
    cin>>str;
    long long minn=1000000;
    for(int x=0;x<str.size();x++)
    {  
        if(str[x]>='0'&&str[x]<='9')
        {
            temp+=str[x];
            if(x==str.size()-1)
            {
                long long a=stoi(temp);
                minn=min(a,minn);
            }

        }
        else
        {   if(temp!="")
            {
                long long a=stoi(temp);
                minn=min(a,minn);
            }
            temp="";
        }
    }
    cout<<minn;
}
