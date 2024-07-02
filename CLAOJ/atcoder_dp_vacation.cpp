#include <bits/stdc++.h>
using namespace std;


int N;
int main()
{
	cin>>N;
	long long K[100001][3];
	for(int i=1;i<=N;i++)
		cin>>K[i][0]>>K[i][1]>>K[i][2];
	for(int i=2;i<=N;i++)
	{
		K[i][0]+=max(K[i-1][1],K[i-1][2]);
		K[i][1]+=max(K[i-1][0],K[i-1][2]);
		K[i][2]+=max(K[i-1][0],K[i-1][1]);
	}
	cout<<max(K[N][1],max(K[N][2],K[N][0]));
}
