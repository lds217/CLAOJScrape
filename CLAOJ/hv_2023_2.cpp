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
#define task "DULICH"

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

int n,m,x;
vector <ii> adj[maxn];
int tickets[maxn];
void input()
{
	cin>>n>>m>>x;
	FOR(i,1,m)
	{
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].pb({w,v});
		adj[v].pb({w,u});
	}
	FOR(i,1,n)
		cin>>tickets[i];
}
ll d[maxn];
ll refuel[maxn],fuelleft[maxn];

void bfs1(int st)
{
	refuel[st]=0;
	priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> q;
	q.push({0,st,x});
	while(!q.empty())
	{
		auto [du,u,fuel]=q.top();q.pop();
		if(du!=refuel[u])	continue;
		fuelleft[u]=fuel;
		for( auto [dv,v]:adj[u])
		{
			if(dv>x)	continue;
			if(dv<=fuel&&minimize(refuel[v],refuel[u]))
				q.push({refuel[v],v,fuel-dv});
			if(dv>fuel&&minimize(refuel[v],refuel[u]+1))
				q.push({refuel[v],v,x-dv});
		}
	}
}
void bfs(int st)
{
	priority_queue<ii,vector<ii>,greater<ii>> q;
	q.push({0,st});
	d[st]=0;
	while(!q.empty())
	{
		auto [du,u]=q.top();q.pop();
		if(du!=d[u])	continue;
		for(auto [dv,v]: adj[u])
		    if(minimize(d[v],d[u]+dv))
			    q.push({d[v],v});	
	}

}

void lds_go_goooo()
{
	mset(d,0x3f);
	mset(refuel,0x3f);
	bfs1(1);
	bfs(n);
/*	FOR(i,1,n)
		cout<<refuel[i]<<' ';*/
	ll ans=1e9;
	FOR(i,1,n)  
	{
		ll r=(d[i]-fuelleft[i])/x;
		if((d[i]-fuelleft[i])%x!=0)	r++;
	//	cout<<refuel[i]<<endl;
		minimize(ans,refuel[i]+(r-tickets[i]>0?r-tickets[i]:0));
	}
	cout<<ans;
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
