#include <bits/stdc++.h>
using namespace std;

const int INF=1e9;
const int MAX=2e4;
int n,i,a,j,f,dp[1004][5][MAX+10],res,v[1004];
int main()
{
    //freopen("INP.txt","r",stdin);
    //freopen("OUT.txt","w",stdout);
    cin>>n;
    for (i=1;i<=n;i++) 
    {
        cin>>v[i];
    }
    sort(v+1,v+n+1);
    n=unique(v+1,v+n+1)-v-1;
    for (i=0;i<=n;i++) 
    {
        for (j=0;j<=3;j++) 
        {
            for (f=0;f<=MAX;f++) 
            {
                dp[i][j][f]=-INF;
            }
        }
    }
    dp[0][0][0]=0;
    for (i=1;i<=n;i++) 
    {
        for (j=0;j<=3;j++)
        {
            for (f=0;f<=MAX;f++)
            {
                dp[i][j][f]=max(dp[i][j][f],dp[i-1][j][f]);
                dp[i][j+1][f^v[i]]=max(dp[i][j+1][f^v[i]] ,dp[i-1][j][f]+v[i]-(f^v[i])+f);
            }
        }
    }
    res=-INF;
    for (i=0;i<=MAX;i++) 
    {
        res=max(res,dp[n][3][i]);
    }
    cout<<res;
    return 0;
}
