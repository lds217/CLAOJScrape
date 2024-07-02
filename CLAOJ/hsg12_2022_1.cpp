#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N,K;
	cin>>N>>K;
	int res=0;
	for(int i=1;i<=N;i++)
	{
		int tmp=i;
		while(tmp>0)
		{
			if(tmp%10==K)
				res++;
			tmp/=10;
		}
	}
	cout<<res;
}
