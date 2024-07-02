#include <bits/stdc++.h>
using namespace std;


int main()
{
	long long len,n,m,a[50000];
	freopen("SUPERMAR.INP", "r", stdin);
    freopen("SUPERMAR.OUT","w", stdout);
	cin>>len>>n>>m;
	
	for(int i=1;i<=n;i++)
		cin>>a[i];
	a[n+1]=0,
	a[n+2]=len;
	n+=2;
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++)
//		cout<<a[i]<<' ';
//	cout<<endl;
	int l=0,r=len;
	int h=1;
	while(r>=l)
	{
		int mid=(r+l)/2;
	//	cout<<mid<<endl;
		int cnt=0;
		for(int i=1;i<n;i++)
		{
			int j=i+1;
		//	cout<<a[i]<<":"<<endl;
			while(a[j]<a[i]+mid&&j<=n)
				cnt++,j++;
			i=--j;
			if(cnt>m)
			{
//				cout<<" cnt :"<<cnt; ;
				r=mid-1;
				break;
			}
		//	cout<<endl;
		}
		if(cnt<=m)
			l=mid+1;
//		cout<<endl;
	}
	cout<<r;
}
