#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
int n,k,i,j,x,dp[102][100002],a[102],ans,m,pre[102][100004];
int main()
{
    //freopen("INP.txt","r",stdin);
    //freopen("OUT.txt","w",stdout);
    cin>>n>>k;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if (n==2)
    {
        for (i=0;i<=a[1];i++)
        {
            if (m-i<=a[2]&&m-i>=0)
            {
                ans++;
                if (ans>=MOD) ans-=MOD;
            }
        }
        if (ans!=0) cout<<ans; 
    }
    else 
    {
        dp[0][0]=1;
        for (i=1;i<=n;i++)
        {
            for(j=0;j<=k;j++)
            {
                if (j-min(a[i],j)==0) dp[i][j]=pre[i-1][j]-pre[i-1][j-min(a[i],j)]+1; else dp[i][j]=pre[i-1][j]-pre[i-1][j-min(a[i],j)-1];
                 if (dp[i][j]<0) dp[i][j]+=MOD;
                if (dp[i][j]>=MOD) dp[i][j]-=MOD;
                if (j>=1) pre[i][j]=pre[i][j-1]+dp[i][j]; else pre[i][j]=dp[i][j];
                if (pre[i][j]>=MOD) pre[i][j]-=MOD;
            }
        }
        //for (i=1;i<=n;i++)
        //{
            //for (j=0;j<=k;j++)
            //{
                //cout<<dp[i][j]<<" ";
            //}
            //cout<<endl;
        //}
        cout<<dp[n][k];
    }
    return 0;
}
