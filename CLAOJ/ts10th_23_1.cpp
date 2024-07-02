#include <bits/stdc++.h>
using namespace std;
#define task "CAU1"
int main()
{
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    int n,cnt=0;
    cin>>n;
    while(n--)
    {
        string t;
        cin>>t;
        if(t[t.size()-1]!='0')  continue;
        int cur=0;
        for(int i=0;i<t.size();i++)
            (cur+=t[i]-'0')%=9;
        if(cur==0)
            cnt++;
    }
    cout<<cnt;
}
