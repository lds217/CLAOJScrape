#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int A[MAXN],lwb[MAXN];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
	    long long n;
	    cin>>n;
	    long long res=sqrtl(n);
	    if(res*res==n) cout<<"YES\n";
	    else cout<<"NO\n";
	}
}
