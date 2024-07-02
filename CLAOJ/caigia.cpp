#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e4 + 6;

ll n, m, dp[25][N], w[25]={0};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>w[i];
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (j<w[i]) dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+w[i]);
		}
	}
	cout<<dp[n][m];
}
