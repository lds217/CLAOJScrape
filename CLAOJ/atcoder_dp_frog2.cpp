#include <bits/stdc++.h>
using namespace std;

int n,k,a[200001],dp[200001]; 

int main()
{
	cin>>n>>k;
	dp[1]=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2;i<=n;i++)
	{
		int tmp=1e9;
		for(int j=i-1;j>=i-k&&j>0;j--)
			tmp=min(tmp,abs(a[j]-a[i])+dp[j]);
			dp[i]=tmp;
	}
	cout<<dp[n];
}
