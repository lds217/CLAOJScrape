#include <bits/stdc++.h>
using namespace std;
int MOD=1000000007;

unsigned long long dp[2001][2001],A[2001],B[2001],n,m;

int main(int argc, char** argv)
{
    cin>>n>>m;
    for(int x=1;x<=n;x++)
        cin>>A[x],dp[0][x]=1;
    for(int x=1;x<=m;x++)
        cin>>B[x],dp[x][0]=1;
    dp[0][0]=1;
    for(int x=1;x<=m;x++)
        for(int y=1;y<=n;y++)
        {
            dp[x][y]=(dp[x-1][y]+dp[x][y-1]-dp[x-1][y-1]);
            if(A[y]==B[x])
                dp[x][y]=(dp[x][y]+dp[x-1][y-1])%MOD;
            else
                dp[x][y]=(dp[x][y]+MOD)%MOD;

        }
        // for(int x=1;x<=m;x++){
        // for(int y=1;y<=n;y++)
        //     cout<<dp[x][y]<<" ";
        // cout<<endl;
        // }
    cout<<dp[m][n];
}
