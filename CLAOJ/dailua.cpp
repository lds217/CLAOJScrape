#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,a[1000001],prefix[1000001];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		prefix[i]=prefix[i-1]+a[i];
	}
	long long maxrighteven[1000001],maxrightodd[1000001];
	long long maxeven=LLONG_MIN,maxodd=LLONG_MIN;
	for(int i=n;i>=1;i--)
	{
		if(i%2==0)
		{
			maxrighteven[i]=max(prefix[i],maxeven);
			maxeven=max(maxeven,prefix[i]);
		}
		else
		{
			maxrightodd[i]=max(prefix[i],maxodd);
			maxodd=max(maxodd,prefix[i]);
		}
	}
	long long res=LLONG_MIN;
	for(int i=0;i<=n;i++)
	{
		if(i%2==0&&i+4<=n)
			res=max(res,-prefix[i]+maxrighteven[i+4]);
		else
			if(i+4<=n)
				res=max(res,-prefix[i]+maxrightodd[i+4]);
	}
	cout<<res;
}
