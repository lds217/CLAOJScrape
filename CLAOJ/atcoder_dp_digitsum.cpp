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
#define MASK(i) (1LL<<(i))
#define BIT(x, i) (((x)>>(i))&1)
#define task "SUADUONG"

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

string s;
ll k;
ll dp[10005][101][2];

void input()
{
	cin>>s>>k;
}

ll lds(ll pos=0,ll sum=0,bool ok=0)
{
	if(pos>=s.size())
		return(sum%k==0);
	ll &res=dp[pos][sum][ok];
	if(res!=-1)
		return res;
	
	res=0;
	ll lim=ok?9:s[pos]-'0';
	FOR(i,0,lim)
		res=(res+lds(pos+1,(sum+i)%k,ok|(i<lim)))%(ll)(1e9+7);
		
	return res;
}

void lds_go_goooo()
{
	mset(dp,-1);
	cout<<(lds()+(ll)(1e9+7)-1)%(ll)(1e9+7);
}

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; //cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
