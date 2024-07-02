#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[100001],dp[100001];
    int N;
    cin>>N;
    dp[1]=dp[0]=0;
    for(int x=1;x<=N;x++)
        cin>>a[x];
    for(int x=2;x<=N;x++)
    {
        if(x!=2)
            dp[x]=min(dp[x-1]+abs(a[x-1]-a[x]),dp[x-2]+abs(a[x-2]-a[x]));
        else
             dp[x]=abs(a[x-1]-a[x]);
    }
                      cout<<dp[N];
}
