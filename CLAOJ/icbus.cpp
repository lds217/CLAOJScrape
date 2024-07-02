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

struct cmp {
	bool operator()(ii const& n1, ii const& n2)
	{
	    return n1.fi> n2.fi;
	}
};

int n,k;
vector <ll> adj[maxn];
ll c[maxn],cnt[maxn];
void input()
{
	cin>>n>>k;
	FOR(i,1,n)	cin>>c[i]>>cnt[i];
	FOR(i,1,k)
	{
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
}

struct lds{
	ll cost,node,lim;
};

struct cmp1 {
	bool operator()(lds const& n1, lds const& n2)
	{
	    return n1.cost > n2.cost;
	}
};
ll d[maxn];
void lds_go_goooo()
{
	mset(d,0x3f);
	d[1]=0;
	priority_queue <ii, vector <ii>, cmp> pq;
	pq.push({0,1});
	while(!pq.empty())
	{
		auto [du,u]=pq.top();pq.pop();
		if(du!=d[u])	continue;
		if(u==n)
		{
			cout<<d[u];
			return;
		}
		priority_queue <lds, vector <lds>, cmp1> q;
		q.push({d[u],u,1});
		bool vs[maxn];
		mset(vs,0);
		vs[u]=1;
		while(!q.empty())
		{
			auto [dx,x,timer]= q.top();q.pop();
			if(dx!=d[x])	continue;
			for(auto y: adj[x])
			{
				if(minimize(d[y],d[u]+c[u]))
					pq.push({d[y],y});
				if(timer<cnt[u]&&vs[y]==0)q.push({d[y],y,timer+1});
				vs[y]=1;
				
				
			}
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
