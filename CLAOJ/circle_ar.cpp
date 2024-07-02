#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	freopen("circle.inp", "r" , stdin);
    freopen("circle.out","w", stdout);
	vector<pair <double ,int > > dot;
	cin>>n;
	for(int x=0;x<n;x++)
	{
		double u,v;
		cin>>u>>v;
		u=sqrt(u*u+v*v);
		dot.push_back({u,0});
	}
	for(int x=0;x<n;x++)
	{
		double u,v;
		cin>>u>>v;
		u=sqrt(u*u+v*v);
		dot.push_back({u,1});
	}
	sort(dot.begin(),dot.end());
	int r=0,b=0;
	double res=0;
	double temp=0,tmp;
	for(pair<double,double> i : dot)
	{
	    tmp=i.first;
		if(b==r&&b!=0&&r!=0&&temp!=i.first&&temp!=0)
		{
			res=temp;
			break;
		}
		temp=i.first;
		if(i.second==0)
			b++;
		else
			r++;
	}
	if(res==0)
	   cout<<setprecision(6)<<fixed<<tmp;
	   else
	cout<<setprecision(6)<<fixed<<res;
}
