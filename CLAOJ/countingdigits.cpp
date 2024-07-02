#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int cdg(int x)
{
    int sum=0;
    while(x>0)
    {
        if(x%10==c)
            sum++;
        x/=10;
    }
    return sum;
}

int main()
{
    
    cin>>a>>b>>c;
    int ans=0;
    for(int i=a;i<=b;i++)
        ans+=cdg(i);
    cout<<ans;
}
