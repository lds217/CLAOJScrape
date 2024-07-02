#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int M,N;
    cin>>M>>N;
    long long dp[2000][2000]={-100000000};
    for(int i=1;i<=M;i++)
        for(int j=1;j<=N;j++)
            cin>>dp[i][j];
    for(int i=2;i<=N;i++)
        for(int j=1;j<=M;j++)
            dp[j][i]+=max(dp[j-1][i-1],max(dp[j][i-1],dp[j+1][i-1]));
    long long res=-100000000;
    for(int x=1;x<=M;x++)
        res=max(res,dp[x][N]);
       cout<<res;
}
