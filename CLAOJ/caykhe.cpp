#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,S;
    cin>>N>>S;
    int w[N+1],v[N+1],dp[105][105]={0};
    for(int x=1;x<=N;x++)
        cin>>v[x]>>w[x];
    for(int i=1;i<=N;i++)
        for(int j=1;j<=S;j++)
        {
            if(j<w[i])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
        }
    
    int i=N,j=S;vector<int> res;
    while(dp[i][j]!=0)
    {
        
        if(dp[i][j]==dp[i-1][j])
            i--;
        else
        {
            res.push_back(i);
            j=j-w[i];  
            i--;
        }
    }
   cout<<dp[N][S]<<endl;
    cout<<res.size()<<' ';
    reverse(res.begin(),res.end());
    for(int i : res)
        cout<<i<<' ';
}
