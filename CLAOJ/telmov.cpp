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

ll n,m,p,l,k;
vector<ii> adj[maxn];
ll dp[maxn][15][15];

void input()
{
	cin>>n>>m>>p>>l>>k;
	FOR(i,1,m)
	{
		int u,v,w; cin>>u>>v>>w;
		adj[u].pb({v,w});
		adj[v].pb({u,w});
	}
}
struct lds{
	ll cost,node,dis,used;
};

struct cmp {
	bool operator()(lds const& n1, lds const& n2)
	{
	    return n1.cost > n2.cost;
	}
};
void lds_go_goooo()
{
	priority_queue< lds, vector<lds>,cmp> q;
	mset(dp,0x3f);
	q.push({0,1,0,0});
	dp[1][0][0]=0;
	while(!q.empty())
	{
		auto [nw,u,nl,nk]= q.top(); q.pop();
		if(nw!=dp[u][nl][nk])	continue;
		if(u==n)
		{
			cout<<nw<<endl;
			return;
		}
		for(auto[v,w]: adj[u])
		{
			if(nl>0&&nl<l&&minimize(dp[v][nl+1][nk],nw))
				q.push({dp[v][nl+1][nk],v,nl+1,nk});
			if(nk<k&&minimize(dp[v][1][nk+1],nw+p))
				q.push({dp[v][1][nk+1],v,1,nk+1});
			if(minimize(dp[v][0][nk],nw+w))
				q.push({dp[v][0][nk],v,0,nk});
		}
	}
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

/* orz anh Hung */
