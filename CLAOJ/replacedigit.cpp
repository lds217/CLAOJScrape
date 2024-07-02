#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string str,ans;
        cin>>str;
        for(int i=0;i<str.size();i++)
            if(str[i]=='0')
                ans+='5';
            else
                ans+=str[i];
        cout<<ans<<endl;
    }
}
