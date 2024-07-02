#include <iostream>
#include <string>
using namespace std;

bool ss(string &a, string &b )
{
    while(a.size()<b.size()) a='0'+a;
    while(b.size()<a.size()) b='0'+b;
    return a<b;
}

int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int maxx=0;
    string ans;
    while(n--)
    {
        string tmp;
        cin>>tmp;
        int num=0;
        for(int i=0;i<tmp.size();i++)
            num+=tmp[i]-'0';
        if(maxx<num)
        {
            ans=tmp;
            maxx=num;
        }
        if(maxx==num)
        {
            if(ss(ans,tmp))
                ans=tmp;
        }
    }
    cout<<ans;
    return 0;
}
