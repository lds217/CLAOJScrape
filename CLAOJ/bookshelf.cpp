#include <bits/stdc++.h>
using namespace std;
#define W 0
#define H 1
int main()
{
	freopen("BOOKSHELF.inp","r",stdin);
	freopen("BOOKSHELF.out", "w",stdout);
		long long  N,limit;
		long long  books[2][2001];
		long long  dp[2001];
	cin>>N>>limit;
	for(int x=0;x<N;x++)
		cin>>books[H][x]>>books[W][x];
	dp[0]=0;
	for(int i=1;i<=N;i++)
	{
		long long w=books[W][i-1];
			long long  h=books[H][i-1];
		dp[i]=dp[i-1]+h;
		for(int j=i-1;j>0 &&w+books[W][j-1]<=limit ;--j)
		{

				h=max(h,books[H][j-1]);
				w+=books[W][j-1];
				dp[i]=min(dp[j-1]+h,dp[i]);
		}
	}
	cout<<dp[N];
}
