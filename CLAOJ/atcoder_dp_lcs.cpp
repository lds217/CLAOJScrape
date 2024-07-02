#include <bits/stdc++.h>
using namespace std;

int main()
{
	int dp[3001][3001];
	string a,b;
	cin>>a>>b;
	a="0"+a;
	b="0"+b;
	for(int i=1;i<a.size();i++)
		for(int j=1;j<b.size();j++)
		{
			if(a[i]==b[j])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	int i=a.size()-1,j=b.size()-1;
	string ans="";
	
//	for(int i=1;i<a.size();i++)
//	{
//		for(int j=1;j<b.size();j++)
//			cout<<dp[i][j]<<" ";
//		cout<<endl;
//	}
	
	while(i>0&&j>0)
	{
		if(a[i]==b[j])
		{
			ans+=a[i];
			i--;
			j--;	
		}
		else
			if(dp[i-1][j]>=dp[i][j-1])
				i--;
			else
				j--;
	}
	reverse(ans.begin(),ans.end());
	cout<<ans;
}
