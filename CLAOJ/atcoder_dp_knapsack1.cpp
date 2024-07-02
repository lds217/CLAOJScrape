#include <bits/stdc++.h>
using namespace std;
long long n,W,w[100001],v[100001],dp[100001][101];
int main()
{
	cin >> n >> W;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];
	
	for (int i = 0; i<n;i++) dp[0][i] = 0;
	for (int i = 0; i<W;i++) dp[i][0] = 0;
	
	for (int i = 1; i <= W; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = dp[i][j-1];

			if (i >= w[j]) dp[i][j] = max(dp[i][j-1],dp[i-w[j]][j-1]+v[j]);
		}
	}

	cout << dp[W][n];	
	
}
