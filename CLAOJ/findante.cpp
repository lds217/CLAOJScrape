#include <bits/stdc++.h>
using namespace std;

map <long long,long long> K,idx;
int cnt=0;

int main()
{
	freopen("FINDDANTE.INP","r",stdin);
	freopen("FINDDANTE.OUT","w",stdout);
	long long a;
	while(cin>>a)
	{
		if(K[a]==0)
			idx[cnt++]=a;
		K[a]++;	
	}
	for(int i=0;i<cnt;i++)
		if(K[idx[i]]%2!=0)
		{
			cout<<idx[i];
			return 0;
		}
}
