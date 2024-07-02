#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,M[60],N[60],ans[60][60];
	cin>>n>>m;
	for(int x=0;x<n;x++)cin>>N[x];
	for(int x=0;x<m;x++)cin>>M[x];
	for(int i=0; i < n ;i++)
	{
		for(int j=0;j<m;j++)
		{
			int temp=min(N[i],M[j]);
			N[i]=N[i]-temp;
			M[j]=M[j]-temp;
			ans[i][j]=temp;
		}
	}
		for(int i=0; i < n ;i++)
	{
	
		for(int j=0;j<m;j++)
		 	cout<<ans[i][j]<<" ";
		cout<<endl;
}
}
