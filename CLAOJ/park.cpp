#include <bits/stdc++.h>
using namespace std;


int main()
{
	long long k,len;
	cin>>k>>len;
	string s;
	cin>>s;long long n=s.size();
	long long l=0,r=0;
	vector<pair<int,int>> a;
	while(r<=n)
	{
		if(k==0)	break;
		while(s[l]=='X') l++;
		if((s[r]=='X'||r==n)&&l<r)
		{
			for(l+=len-1;l<r;l+=len)
			{
				if(k==0)	break;
				if(r-l<len)	a.push_back({r-l,l});
				else
				s[l]='X',k--;
			}
			l=r;
		}
		r++;
	}
	sort(a.begin(),a.end(),[](pair <int,int> a, pair <int,int>b)
	{
		return a.first>b.first;
	});
	for(pair<int,int> i:a)
	{
		if(k==0)	break;
		s[i.second]='X';
		k--;
	}
	cout<<s;
}
