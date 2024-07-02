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
const ll maxn=2*1e6+2;
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

ll dp[maxn];
ll n,m,p,D;
vector<ii> adj[maxn];
void input()
{
	FOR(i,0,n)	adj[i].clear();
	
	cin>>n>>m>>p>>D;
	FOR(i,1,m)
	{
		ll l,u,v;
		cin>>l>>u>>v;
		adj[v].pb({l,u});
	}
	mset(dp,-1);
}

ll dfs(ll u)
{
	ll &res=dp[u];
	if(~res)	return res;
	if(u==1)	return res=p;
	res=0;
	for(auto [dv,v]: adj[u])
	{
		ll cur=dfs(v);
		if(cur>dv)
			cur+=dv/2;
		else
			cur-=cur/2;
		maximize(res,cur);
	}
	return res;
}

void lds_go_goooo()
{
	ll cost=dfs(n);
	if(cost<D)
		cout<<"Impossible";
	else
		cout<<dp[n];
}

signed main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(task".INP", "r", stdin);
    //freopen(task".OUT", "w", stdout);
    ll test_case=1; cin>>test_case;
    while(test_case--)
    {
        input(), lds_go_goooo();
        cout<<'\n';
    }
    return 0;
}
