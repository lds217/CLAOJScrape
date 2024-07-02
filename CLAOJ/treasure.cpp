#include <bits/stdc++.h>

using namespace std;

#define MOD 26051968 
#define int long long
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	freopen("TREASURE.INP","r",stdin);
	freopen("TREASURE.OUT","w",stdout);
	int n,k,dp[100001];
	cin>>n>>k;
		dp[1]=1;
	dp[2]=2;
	while(k--)
	{
		int u;
		cin>>u;
		dp[u]=-1;
	}

	for(int i=3;i<=n;i++)
	{
		if(dp[i]==-1)
			dp[i]=0;
		else
			dp[i]=(dp[i-1]+dp[i-2])%MOD;
	}
	cout<<dp[n];
}
