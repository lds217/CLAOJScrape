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
const ll maxn=2*1e5+2;
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

ll dp[maxn][MASK(6)+1];
int n,m,k,l;
vector <ii> adj[maxn];
ll melon[maxn];
ll mask[maxn];

void input()
{
	cin>>n>>m>>k>>l;
	FOR(i,1,n)
	{
		ll u;
		cin>>u;
		FOR(j,1,u)
		{
			ll v;
			cin>>v;
			mask[i]=mask[i]|MASK(v);
		}
	}
	FOR(i,1,m)
	{
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].pb({w,v});
		adj[v].pb({w,u});
	}
	
}

struct lds{
	ll cost,node,status;
};

struct cmp {
	bool operator()(lds const& n1, lds const& n2)
	{
	    return n1.cost > n2.cost;
	}
};

void lds_go_goooo()
{
	mset(dp,0x3f);
	priority_queue<lds,vector <lds>, cmp> q;
	q.push({0,1,mask[1]});dp[1][mask[1]]=0;
//	cout<<1;
	while(!q.empty())
	{
		auto [du,u,status] = q.top();q.pop();
		if(du!=dp[u][status])	continue;
		if(u==n && __builtin_popcount(status)>=l)
		{
			cout<<du;
			return;
		}
		for(auto [dv,v]:adj[u])
			if(minimize(dp[v][status|mask[v]],du+dv))
				q.push({dp[v][status|mask[v]],v,status|mask[v]});
	}
	cout<<-1;
}

int main()
{
 	//ios_base::sync_with_stdio(false);
   // cin.tie(0);
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
