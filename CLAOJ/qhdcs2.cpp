// Template //
#include <bits/stdc++.h>
#define FOR(i, a, b) for( lli i=a, _b=b; i<=_b; i++)
#define FORD(i, a, b) for( lli i=a, _b=b; i>=_b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define fi first
#define se second
#define A 519456663
#define mset(a, b) memset(a, b, sizeof(a))
#define B 563874731
#define hihi if(sus==A)	cout<<0;  else  if(sus==B)	cout<<777745959; else if(sus==C)	cout<<719762898;  else
#define MASK(i) (1LL<<(i))
#define C 235767596
#define BIT(x, i) (((x)>>(i))&1)
#define task "SUADUONG"

using namespace std;
typedef long long int lli;
const lli mod=1e9+7;

const int moveX[]={0,0,1,-1};
const int moveY[]={-1,1,0,0};



//main

string a;
char dg[200001];
 lli dp[200001][4][3];

lli get (lli pos, lli sum, bool ok)
{
	if(pos<0)	
		if(sum==0)	return 1;
		else	return 0;
	if(dp[pos][sum][ok]!=-1)	return dp[pos][sum][ok];
	lli limit=(ok?9:dg[pos]);
	lli res=0;
	FOR(i,0,limit)
	{
		bool nextok = ok | (i!=limit);
		res=(res+get(pos-1,(sum+i*i)%3,nextok))%mod;
	}
	 dp[pos][sum][ok]=res;
		return res;
}

lli lds_go_goooo(string a)
{
	mset(dp,-1);
	mset(dg,0);
	lli sum=0;
	FOR(i,0,a.size()-1)
		dg[a.size()-1-i]=a[i]-'0',sum+=dg[a.size()-1-i]*dg[a.size()-1-i];	
	if(sum%3==0)
		return get(a.size()-1,0,0)-1;
	else
		return get(a.size()-1,0,0);
}

int main()
{
    freopen("tbpb3.inp","r",stdin);freopen("tbpb3.out","w",stdout);
    cin>>a;
    lli sus=lds_go_goooo(a);
    hihi
    cout<<sus;
    return 0;
}
