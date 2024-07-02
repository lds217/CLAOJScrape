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
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
const ll maxn=1e5+2;
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

ll n,m,t;
vector <ii> k[maxn];
ll par[maxn];
ll c[maxn];
ll val[maxn],dp[maxn];
void input()
{
    mset(dp,0);
	cin>>n>>m>>t;
	FOR(i,1,n)
		cin>>c[i];
	FOR(i,1,m)
	{
		long long u,v,w;
		cin>>u>>v>>w;
		k[u].pb({w,v});
		k[v].pb({w,u});
	}
}

void bfs(ll st)
{
	mset(val,0x3f);
	val[1]=0;
		priority_queue<ii, vector<ii>, greater<ii>> q;
	q.push({0,1});
	while(!q.empty())
	{
		ll u=q.top().se;
		ll du=q.top().fi;
		q.pop();
		if (du != val[u]) continue;

		for(ii i: k[u])
		{
			ll v=i.se;
			ll dv=i.fi;
			if(val[v]>val[u]+dv)
			{
				val[v]=val[u]+dv;
				par[v]=u;
				q.push({val[v],v});
			}
			if(val[v]==val[u]+dv)
			    par[v]=min(par[v],u);
		}
	}
}

bool vs[maxn];
void dfs(ll u)
{
	dp[u]+=c[u];
	for(ii v: k[u])
		if(vs[v.se]==0&&par[v.se]==u)
			vs[v.se]=1,dfs(v.se),dp[u]+=dp[v.se];


}

void lds_go_goooo()
{
   // FOR(i,1,n-1)  par[i]=i;
	bfs(1);
//	build();
	mset(dp,0);
	//cout<<f[1].size();
	//debug_build(1);
	dfs(1);
/*	FOR(i,1,n)
		cout<<val[i]<<' ';
	cout<<endl;
	FOR(i,1,n)
		cout<<dp[i]<<' ';*/
	ll ans=0;
	FOR(i,1,n)
		maximize(ans,(val[i]-t)*dp[i]);
	cout<<ans;
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
