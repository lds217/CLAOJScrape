#include <bits/stdc++.h>
using namespace std;

long long dp[1005][1005]={};

int main(int argc, char **argv){
    int n,m;
    cin>>n>>m;
    string str[n+1];
    for(int i=0;i<n;i++){
        cin>>str[i];
    }
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(str[i][j]!='#')
            {
                if(i>0) dp[i][j]=(dp[i][j]+dp[i-1][j])%(1000000007);
                if(j>0) dp[i][j]=(dp[i][j]+dp[i][j-1])%(1000000007);
            }
            else
                dp[i][j]=0;
        }
    }
    
    cout<<dp[n-1][m-1];

}
