// Template //
#include <bits/stdc++.h>
#define FOR(i, a, b) for(ll i=a, _b=b; i<=_b; i++)
#define FORD(i, a, b) for(ll i=a, _b=b; i>=_b; i--)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define MASK(i) (1<<(i))
#define BIT(x, i) (((x)>>(i))&1)
#define task "cspb"

using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=2*1e4+2;
const ll mod=26051968;
const ll inf=1e18;

const int moveX[]={0,0,1,-1};
const int moveY[]={-1,1,0,0};

bool maximize(ll &A, ll B)
{
    return A<B ? A=B, true : false;
}

bool minimize(ll &A, ll B)
{
    return A>B ? A=B, true : false;
}

ll POW(ll a, ll b)
{
    if (b==0) return 1;
    ll tmp=POW(a, b/2);
    return b%2==0 ? (tmp*tmp)%mod : (tmp*tmp*a) % mod;
}

//main

long long dp[20][MASK(12)][3];
string l,r,str;
long long n;

void input()
{
	cin>>l>>r;
}

long long dpdg(long long pos, long long mask, bool ok)
{
	if(pos>=n)
		return 1;
	long long &res=dp[pos][mask][ok];
	if(res!=-1)
		return res;
	res=0;
	int lim=ok?9:str[pos]-'0';
//	cout<<lim;
	FOR(i,0,lim)
	{
		if( mask ==0&&i==0 )
		 res+=dpdg(pos+1,mask,ok|(i<lim));
		else
			if((mask&MASK(i))==0)
				res+=dpdg(pos+1,mask|MASK(i),ok|(i<lim));
	}
	return res;
}

long long ma(string &a)
{
	str=a;
	mset(dp,-1);
	n=a.size();
	return dpdg(0,0,0);
	
	
}

void lds_go_goooo()
{
	l=to_string(stoll(l)-1);
	cout<<ma(r)-ma(l);
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
