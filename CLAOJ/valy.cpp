#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int N,S;
    cin>>N>>S;
    int w[N+1],v[N+1],dp[105][105]={0};
    for(int x=1;x<=N;x++)
        cin>>w[x]>>v[x];
    for(int i=1;i<=N;i++)
        for(int j=1;j<=S;j++)
        {
            if(j<w[i])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-w[i]]+v[i]);
        }
    
    int i=N,j=S,res[200]={0};
    while(dp[i][j]!=0)
    {
        
        if(dp[i-1][j]==dp[i][j])
            i--;
        else
        {
            res[i]++;
            j=j-w[i];  
        }
    }
    cout<<dp[N][S]<<endl;
    for(int x=0;x<=N;x++)
    {
        if(res[x]!=0)
            cout<<x<<" "<<res[x]<<endl;
    }
}
