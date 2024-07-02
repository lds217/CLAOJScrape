#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    
   bool done=0;
    string a;
    cin>>a;
    int n=a.size(),dem=0;
    a=" "+a;
    int res=0;
    for(int x=1;x<=n;x++)
    {
        dem=1;
        for(int i=1;i<=n;i++)
        {
            if(a[x+i]==a[x-i]&&x-i>0&&x+i<=n)
            {
                dem+=2;
                done=1;
            }
            else
                break;
            
        }
        //cout<<"Chay";
        res=max(res,dem);
    }
    for(int x=1;x<=n;x++)
    {
        dem=2;
        for(int i=1;i<=n;i++)
        {
            if(a[x+i+1]==a[x-i]&&x-i>0&&x+i<=n)
            {
                dem+=2;
                
            }
            else
                break;
            
        }
        //cout<<"Chay";
        res=max(res,dem);
    }
    if(done!=1&&res==2)
    cout<<1;
    else
    cout<<res;
}
