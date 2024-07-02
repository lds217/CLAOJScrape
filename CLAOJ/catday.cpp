#include <bits/stdc++.h>
using namespace std;

long long n,m,a[200001],l=1,r=0;

int main()
{
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		r=max(r,a[i]);
	}
//	cout<<l << r;
long long res=0;
	while(r>=l)
	{
		long long mid=(l+r)/2;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
				cnt+=a[i]/mid;
		}
		if(cnt<m)
			r=mid-1;
		else
			if(cnt>=m)
			{
				//cout<<mid<<' ';
				l=mid+1;
				if(cnt==m)
					res=mid;
			}
			
	}
	cout<<r;
}
